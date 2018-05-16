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
#define MAX 500005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
ll n;
int parent[MAX];
vector<int> adj[MAX];
ll subtree[MAX];
int from[MAX];

ll bfs(int node, int p){
    parent[node]=p;
    subtree[node]=1LL;
    rep(i,0,adj[node].size()){
            if(adj[node][i]!=p){
                int cnt=bfs(adj[node][i], node);
                subtree[node]+=cnt;
            }
    }
    return subtree[node];
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n;
    int F,B;
    cin>>F>>B;
    rep(i,0,n-1) {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bfs(F,0);
    int curr=B;
    while(parent[curr]!=F){
        curr=parent[curr];
    }
    ll ans=(n*(n-1LL))-((n-subtree[curr])*subtree[B]);
    cout << ans << endl;
}

int main(){
    fast_cin;
    int t=1; 
    while(t--){
        solve();
    }
    return 0;
}