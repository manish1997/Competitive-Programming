//TLE approach
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
#define MAX 2005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
 
ll dp[MAX][MAX];
 
map<pair<int,int>,bool > M; 
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll p,q,c,m;
    cin>>p>>q>>c>>m;
    if(p>2e3 || q>2e3) return;
    // M.clear();
    rep(i,0,m){
    	int x,y;cin>>x>>y;
        if(y<MAX && x<MAX) dp[y][x]=-1;
    }
    rep(i,0,p+1){
    	if(dp[0][i]!=-1) dp[0][i]=1ll;
    }
    dp[0][0]=0;
    // cout << dp[0][5] << endl;
    rep(i,1,q+1){
    	rep(j,i,p+1){
    		//i bad deeds and j good deeds
    		//possible from i-1 bad, j good (iff j-i>=c)& i bad, j-1 good
    		if(dp[i][j]==-1) continue;
            if(dp[i][j-1]!=-1) dp[i][j]=dp[i][j-1];
    		if(j-i>=c && dp[i-1][j]!=-1) dp[i][j]+=dp[i-1][j];
    		if(dp[i][j]>=mod) dp[i][j]%=mod;
    	}
    }
    cout<< (dp[q][p]==-1?0:dp[q][p]) <<endl;
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