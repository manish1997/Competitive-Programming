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
#define MAX (1<<17)+5
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
int n,k;
ll dp[2003][2003];

//earlier used dp code.
ll helper(int start, int len){
    if(len==1) return 1;
    //start here..
    //what can be choises for len-1's first
    //any multiple of start
    if(dp[start][len]!=-1) return dp[start][len];
    ll &ans=dp[start][len];
    ans=0;
    for(ll i=start; i<=n; i+=start){
        //reason for O(n^2*logn)
        ans=(ans+(helper(i, len-1)))%mod;
    }
    return ans;
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n>>k;
    rep(i,1,n+1) dp[i][1]=1;
    ll ans=0;
    rep(len,2,k+1){
        //len-1 wale sare
        rep(j,1,n+1){
            for(ll c=j; c<=n; c+=j){
                //(n^2*logn)
                //c=(n+n/2+n/3+n/4..........1)
                //c=(ln(xyz))..see quora for explanation
                dp[c][len]=(dp[c][len]+dp[j][len-1])%mod;
            }
        }
    }
    rep(j,1,n+1) ans=(ans+dp[j][k])%mod;
    cout<<ans<<endl;


}

int main(){
    fast_cin;
    int t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}