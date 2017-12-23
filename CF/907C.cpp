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

void solve(){

    int n;
    cin >> n;

    bool correct=false;
    int ans=0;

    int arr[26];
    rep(i,0,26) arr[i]=1;

    rep(i,0,n-1){ 
        string a,b;
        cin >> a >> b;
        bool sh=false;
        if(a=="?"){
            sh=true;
            arr[b[0]-'a']=min(arr[b[0]-'a'], 0);
        }
        else if(a=="!"){
            sh=true;
            rep(j,0,26){
                char x='a'+j;
                bool pre=false;
                rep(k,0,b.length()) if(b[k]==x) pre=true;
                if(!pre) arr[x-'a']=min(arr[x-'a'],0);
            }
        }
        else{
            rep(j,0,b.length()) arr[b[j]-'a']=min(arr[b[j]-'a'],0);
        }
        if(correct&&sh) ans++;
        if(!correct){
            int cnt=0;
            rep(i,0,26) if(arr[i]) cnt++;
            if(cnt==1) correct=true;
        }
        
    }
    tr1(ans);
    
}

int main(){
    fast_cin;
	// clock_t clk;
	// clk = clock();
	// srand (time(NULL));
    int t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
 //    clk = clock() - clk;	
	// cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}