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
ll n,arr[MAX];
ll dp[MAX][3];
ll rev[MAX][3];
 
#define INF 1e16
 
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n;
    rep(i,0,n)cin>>arr[i];
    if(n==1){
        cout << arr[0] << endl;
        return;
    }
    dp[1][0]=arr[0]+arr[1];
    if(arr[0]-arr[1]>0) dp[1][1]=arr[0]-arr[1];
    else dp[1][1]=INF;
 
    if(-arr[0]+arr[1]>0) dp[1][2]=-arr[0]+arr[1];
    else dp[1][2]=INF;
 
    rep(i,2,n){
        dp[i][0]=dp[i-1][0]+arr[i];
        rev[i][0]=0;
        if(dp[i-1][2]+arr[i]<=dp[i][0]){
            dp[i][0]=dp[i-1][2]+arr[i];
            rev[i][0]=2;
        }
        dp[i][2]=INF;
        if(arr[i]-arr[i-1]>0 && dp[i][2]>(dp[i-1][1]+arr[i])){
            dp[i][2]=dp[i-1][1]+arr[i];
            rev[i][2]=1;
        }
        dp[i][1]=INF;
        if(arr[i-1]-arr[i]>0 && dp[i-1][0]-arr[i]>0){
            if(dp[i][1]>dp[i-1][0]-arr[i]){
                dp[i][1]=min(dp[i][1],dp[i-1][0]-arr[i]);
                rev[i][1]=0;
            }
        }
        if(arr[i-1]>arr[i-2]+arr[i] && dp[i-1][2]>arr[i]){
            if(dp[i][1]>(dp[i-1][2]-arr[i])){
                dp[i][1]=min(dp[i][1],dp[i-1][2]-arr[i]);
                rev[i][1]=2;
            }
        }
    }
    ll ans=min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    if(ans==dp[n-1][0]) ans=0;
    else if(ans==dp[n-1][1]) ans=1;
    else ans=2;

    int curr=n-1;
    while(curr>1){
        if(ans==1) arr[curr]*=-1LL;
        ans=rev[curr][ans];
        curr--;
    }
    if(ans==1) arr[1]*=-1;
    else if(ans==2) arr[0]*=-1;
    rep(i,0,n) cout << arr[i] << " ";
    cout << endl;
}
 
int main(){
    fast_cin;
    int t=1; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
} 