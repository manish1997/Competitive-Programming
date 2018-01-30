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

string s="";
int n;
int dp[5002][5002];
int pre[5002][5002];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin >> n;
    rep(i,0,n){
        char x;
        cin >> x;
        s.pb(x);
    }
    if(n==1) {
        printf("1\n");
        return;
    }

    mem(dp,0);
    mem(pre,0);
    repDown(i,n-1,0){
        int temp=0;
        if(s[i]=='f') temp=1;
        rep(j,1,5002){
            if(i==n-1 && s[i-1]!='f') dp[i][j]=j;
            else if(i==n-1) dp[i][j]=1;
            else{
                if(i>=1 && s[i-1]=='s'){
                    ll checkk=(ll)pre[i+1][j+temp]-(ll)pre[i+1][temp];
                    if(checkk<0) checkk+=mod;
                    dp[i][j]=checkk;
                }
                else{
                    dp[i][j]=dp[i+1][j+temp];
                }
            }
        }
        rep(j,1,5002) {
            ll checkk=((ll)pre[i][j-1]+(ll)dp[i][j])%mod;
            pre[i][j]=checkk;
        }
    }
    cout << dp[0][1] << endl;

}

int main(){
    fast_cin;
	//clock_t clk;
	//clk = clock();
	//srand (time(NULL));
    int t=1; 
    // rep(i,0,1e6/4){
    //     cout <<"aaab";
    // }
    // cin >> t;
    while(t--){
        solve();
    }
    //clk = clock() - clk;	
	//cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}