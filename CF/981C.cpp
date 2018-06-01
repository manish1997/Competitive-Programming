#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define mod 1000000007
#define MAX 100005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

int n;
vector<int> adj[MAX];
int deg[MAX];
int parent[MAX];
void bfs(int node, int p){
    parent[node]=p;
    rep(i,0,adj[node].size())if(adj[node][i]!=p)bfs(adj[node][i], node);
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
   cin>>n;
   rep(i,0,n-1){
        int a,b;cin>>a>>b;a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
        deg[a]++;
        deg[b]++;
   }
   int node=0;
   rep(i,1,n){
    if(deg[i]>deg[node]) node=i;
   }
   rep(i,0,n){
    if(i!=node && deg[i]>2){
        cout<<"No";
        return;
    } 
   }
   cout <<"Yes\n";
   vector<pair<int,int> > ans;
   rep(i,0,n){
    if(i!=node && deg[i]==1){
        ans.pb({i,node});
    }
   }
   cout << ans.size() << endl;
   rep(i,0,ans.size()) cout << ans[i].f+1 << " " << ans[i].s+1<< endl;

    
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