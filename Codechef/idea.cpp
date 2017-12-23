#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define MAX 1000005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
//Sieve
#define sieveMax 1000001 //maximum for which u need primality test
bool neverMakeThisName[sieveMax];

vector<int> Prime;
void sieve(){
    mem(neverMakeThisName,false);
    neverMakeThisName[0]=neverMakeThisName[1]=true;
    for(int i=4; i<sieveMax; i+=2) neverMakeThisName[i]=true;

    for(int i=3; i<=sqrt(sieveMax); i+=2){
        if(neverMakeThisName[i]==false) {
            for(int j=i*i; j<sieveMax; j+=i) neverMakeThisName[j]=true;
        }
    }

    rep(i,0,sieveMax) if(neverMakeThisName[i]==false) Prime.pb(i);
}
//end Sieve
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n; cin >> n;
    if(n<=1e7){
        ll temp=0;
        rep(i,1,n+1) if(n%i==0) temp+=i;
        tr2("sure ", temp);
    }
    unordered_map<ll,ll> M;
    int curr=0;
    while(n>1 && Prime[curr]*Prime[curr]<=n){
        if(n%Prime[curr]){
            curr++;
            continue;
        }
        int cnt=0;
        while(n%Prime[curr]==0){
            cnt++;
            n/=Prime[curr];
        }
        M[Prime[curr]]=cnt;
        curr++;
    }
    if(n>1) M[n]=1;

    ll ans=1;
    for(auto it=M.begin(); it!=M.end(); it++){
        ans=ans*((pow(it->f, it->s+1)-1)/(it->f-1));
    }
    tr1(ans);


}

int main(){
    fast_cin;
	clock_t clk;
	clk = clock();
	srand (time(NULL));
    int t=1; 
    sieve();
    // cin >> t;
    while(t--){
        solve();
    }
    clk = clock() - clk;	
	cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}