#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll unsigned long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define mod2 1000000033
#define MAX 100003
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
vector<int> adj[MAX];
int s[MAX];
int p[MAX];

void dfs(int node, int parent){
    p[node]=parent;
    for(int i=0; i<adj[node].size(); i++){
        if(adj[node][i]!=parent){
            dfs(adj[node][i], node);
        }
    }
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;
    cin>>n;
    rep(i,0,n-1){
        int x;cin>>x;
        x--;
        adj[x].push_back(i+1);
    }
    dfs(0,-1);

    rep(i,0,n){
        cin>>s[i];
    }
    ll ans=s[0];
    for(int i=0; i<n; i++){
        if(s[i]==-1){
            int node=i;
            int baap=s[p[i]];
            int minn=2e9;
            for(int j=0; j<adj[node].size(); j++){
                if(s[adj[node][j]]<baap){
                    cout << -1 << endl;
                    return;
                }
                minn=min(minn, s[adj[node][j]]-baap);
            }
            if(minn!=2e9) ans+=minn;
            for(int j=0; j<adj[node].size(); j++){
                ans+= (s[adj[node][j]]-baap-minn);
            }

        }
    }
    cout << ans << endl;





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