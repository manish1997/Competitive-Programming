#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define mod 1000000007
#define MAX 100005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

int dp[55][55];
ll arr[55];
ll n,K;

int check(ll mask){
    mem(dp,0);
    dp[0][0]=1;
    rep(i,1,n+1){
        rep(j,1,i+1){
            ll sum=0;
            repDown(k,i,1){
                sum+=arr[k];
                if(k>=j&&dp[i][j]==0 && (sum&mask)==mask){
                    dp[i][j]=dp[k-1][j-1];
                }
            }
        }
    }
    return dp[n][K];
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
   cin>>n>>K;
   rep(i,1,n+1)cin>>arr[i];
   ll ans=0;
   repDown(i,59,0) if(check(ans|(1LL<<i))>0)ans|=(1LL<<i);
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