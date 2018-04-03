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
#define MAX 100005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
//Sieve
#define sieveMax 71 //maximum for which u need primality test
vector<int> Prime;
void sieve(){
    bool neverMakeThisName[sieveMax];
    mem(neverMakeThisName,false);
    neverMakeThisName[0]=neverMakeThisName[1]=true;
    for(int i=4; i<sieveMax; i+=2) neverMakeThisName[i]=true;

    for(int i=3; i<=sqrt(sieveMax); i+=2)
        if(neverMakeThisName[i]==false) {
            for(int j=i*i; j<sieveMax; j+=i) neverMakeThisName[j]=true;
        }

    rep(i,0,sieveMax) if(neverMakeThisName[i]==false) Prime.pb(i);
}
//end Sieve
int mapp[80];
int arr[74];
int dp[1<<20];
vector<int> fact(int num){
    vector<int> ans;
    rep(i,0,Prime.size()){
        int cnt=0;
        while(num%Prime[i]==0){
            num/=Prime[i];
            cnt++;
        }
        if(cnt%2) ans.push_back(Prime[i]);
    }
    return ans;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;cin>>n;
    rep(i,0,n){
        int x;cin>>x;
        arr[x]++;
    }
    dp[0]=1;
    rep(i,1,3){
        vector<int> facts=fact(i);
        // cout << i << endl;
        // rep(j,0,facts.size()) cout << facts[j] << " ";
        // cout<<endl;
        int mask=0;
        rep(j,0,facts.size()) mask+=(1<<mapp[facts[j]]);
        rep(j,0,1<<19) dp[j^mask]+=arr[i];
    }
    cout << dp[0] << endl;
}

int main(){
    fast_cin;
    int t=1; 
    sieve();
    rep(i,0,Prime.size()) {
        mapp[Prime[i]]=i;
    }

    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}