#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define si(n) scanf("%d",&n)
#define si2(n1,n2) scanf("%d%d",&n1,&n2)
#define sll(n) scanf("%lld",&n)
#define sll2(n1,n2) scanf("%lld%lld",&n1,&n2)
#define tr1(n) printf("%d\n",n)
#define tr2(n1,n2) printf("%d%d\n",n1,n2)
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define pb push_back
vector<int> adj[10005];
int arr[10005];
int pa[10005];

void dfs(int node, int parent){
	pa[node]=parent;
	rep(i,0,adj[node].size()) if(adj[node][i]!=parent) dfs(adj[node][i], node);
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
	int n;
	cin >> n;
	rep(i,2,n+1){
		int x; cin >> x;
		adj[i].pb(x);
		adj[x].pb(i);
	}
	dfs(1,0);


	rep(i,1,n+1) {
		cin >> arr[i];
	}

	queue<pair<int,int> > Q;
	Q.push({1,0});
	int step=0;
	while(!Q.empty()){
		pair<int,int> curr=Q.front();
		Q.pop(); 
		if(curr.s!=arr[curr.f]){
			curr.s=arr[curr.f];
			step++;
		}
		rep(i,0,adj[curr.f].size()){
			int node=adj[curr.f][i];
			if(node==pa[curr.f]) continue;
			Q.push({node, curr.s});
		}
	}
	cout << step << endl;

    
}

int main(){
    int t=1; 
    //si(t);
    while(t--){
        solve();
    }
    return 0;
}