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
#define MAX 200005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
int inDegree[MAX];
pair<int,int> edges[MAX];
vector<int> adj[MAX];
int parent[MAX];

int root(int a){
	if(a!=parent[a]) parent[a]=root(parent[a]);
	return parent[a];
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n,m;
    cin>>n>>m;
    rep(i,0,m){
    	cin>>edges[i].f>>edges[i].s;
    	adj[edges[i].f].pb(edges[i].s);
    	adj[edges[i].s].pb(edges[i].f);
    	inDegree[edges[i].f]++;
    	inDegree[edges[i].s]++;
    }
    int idx = 0;
    rep(i,1,MAX){
    	if(inDegree[i]>inDegree[idx]) idx=i;
    }
    rep(i,0,MAX) parent[i]=i;

    rep(i,0,adj[idx].size()){
    	cout << idx << " " << adj[idx][i] << endl;
    	parent[adj[idx][i]]=idx;
    }
    rep(i,0,m){
    	int roota = root(edges[i].f);
    	int rootb = root(edges[i].s);

    	if(roota==rootb) continue;
    	cout << edges[i].f << " " << edges[i].s << endl;
    	if(roota==idx){
    		parent[rootb]=roota;
    	}
    	else{
    		parent[roota]=rootb;
    	}
    }
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