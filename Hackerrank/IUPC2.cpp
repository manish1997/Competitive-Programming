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

vector<int> adj[MAX];
vector<int> inc[MAX];
int n,m;
int deg[MAX];
int ans[MAX];


void solve(){
    //solve the problem. You can and you will :) give your best shot..
	cin >> n >> m;
	rep(i,0,n+2) {
		adj[i].clear();
		deg[i]=ans[i]=0;
		inc[i].clear();
	}
	rep(i,0,m){
		int x,y;cin >> x >> y;
		adj[y].pb(x);
		inc[x].pb(y);
		deg[x]++;
	}
	queue<int> Q;
	rep(i,1,n+1){
		if(deg[i]==0){
			Q.push(i);
		}
	}
	int tempans=0;
	while(!Q.empty()){
		int curr=Q.front();
		Q.pop();
		if(inc[curr].size()!=0){
			rep(j,0,inc[curr].size()){
				ans[curr]=max(ans[curr], ans[inc[curr][j]]);
			}
			ans[curr]+=1;
			tempans=max(tempans,ans[curr]);
		}
		rep(i,0,adj[curr].size()){
			int node=adj[curr][i];
			deg[node]--;
			if(deg[node]==0) Q.push(node);
		}
	}
	tr1(tempans+1);
}

int main(){
	fast_cin;
    int t=1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}