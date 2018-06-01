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
#define MAX 10005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
int dp[MAX][2];
pair<pair<int,int>,int> Q[MAX];

void solve(){
  //solve the problem. You can and you will :) give your best shot..
  int n,q;
  cin>>n>>q;
  rep(i,0,q){
    int li,ri,xi;cin>>li>>ri>>xi;
    Q[i]={{li,ri},xi};
  }
  sort(Q,Q+q);
  rep(i,0,q){
    dp[0][0]=n+1;
    rep(j,0,n){
      if(j+Q[i].s<=n){
        if(dp[j][0]>=Q[i].f.f){
          //j can be formed after start of current query
          dp[j+Q[i].s][1]=max(dp[j+Q[i].s][0], min(dp[j][0], Q[i].f.s));
        }
      }
    }
    rep(j,0,n+1){
      dp[j][0]=dp[j][1];
    }
  }
  vector<int> ans;
  rep(i,1,n+1)if(dp[i][0])ans.pb(i);
  cout<<ans.size()<<endl;
  rep(i,0,ans.size()) cout<<ans[i] <<" ";
  cout << endl;

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