#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define MAX 1000005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
int n;
vector<int> adj[200002];

int parent[200002];
int deg[200002];
vector<int> level[200002];

void dfs(int node, int p, int l){
	parent[node]=p;
	level[l].pb(node);
	rep(i,0,adj[node].size()) 
		if(adj[node][i]!=p) dfs(adj[node][i], node, l+1);
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n;
    rep(i,1,n+1){
    	int x;cin>>x;
    	if(x!=0){
    		adj[i].pb(x);
    		adj[x].pb(i);
    		deg[i]++;
    		deg[x]++;
    	}
    }
    dfs(1,0,0);
    vector<int> ans;
    // rep(i,0,3){
    // 	rep(j,0,level[i].size()){
    // 		cout << level[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }
    repDown(i,200001,0){
    	if(level[i].size()==0) continue;
    	rep(j,0,level[i].size()){
    		int node=level[i][j];
    		if(deg[node]%2){
    			continue;
    		}
    		else{
    			deg[parent[node]]-=1;
    			queue<int> Q;
    			Q.push(node);
    			while(!Q.empty()){
    				int fro=Q.front();
    				Q.pop();
    				ans.pb(fro);
    				deg[fro]=-1;
    				rep(k,0,adj[fro].size()){
    					if(adj[fro][k]!=parent[fro]){
    						if(deg[adj[fro][k]]!=-1){
    							Q.push(adj[fro][k]);
    						}
    					}
    				}
    			}

    		}
    	}
    }
    if(ans.size()!=n){
    	cout<<"NO"<<endl;
    	return;
    }
    cout<<"YES"<<endl;
    rep(i,0,n) cout<<ans[i]<<endl;

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