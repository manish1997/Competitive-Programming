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
#define MAX 1000005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
ll n,m,k;
ll cost[62];
vector<pair<ll,ll> > adj[MAX];
bool visited[MAX];

void bfs(int node, ll mask){
	if(visited[node])return;
	visited[node]=true;
	rep(i,0,adj[node].size()){
		if(visited[adj[node][i].f]) continue;
		if((adj[node][i].s&mask)==adj[node][i].s){
			bfs(adj[node][i].f, mask);
		}
	}
}

bool possible(ll mask){
	mem(visited,false);
	bfs(0,mask);
	rep(i,0,n) if(visited[i]==false) return false;
	return true;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
	cin>>n>>m>>k;
	rep(i,0,k) cin>>cost[i];
	rep(i,0,m){
		ll a,b,l,c=0;
		cin>>a>>b>>l;
		a--;b--;
		rep(j,0,l){
			ll idx;cin>>idx;idx--;
			c+=(1LL<<idx);
		}
		adj[a].pb({b,c});
		adj[b].pb({a,c});
	}
	ll curr=0;
	rep(i,0,k){
		curr+=(1LL<<i);
	}
	if(possible(curr)==false){
		cout << -1 << endl;
		return;
	}
	repDown(i,k-1,0){
		curr=(curr^(1LL<<i));
		if(possible(curr)==false) curr=curr^(1LL<<i);
	}
	ll ans=0;
	rep(i,0,k){
		if((1LL<<i)&curr){
			ans+=cost[i];
		}
	}
	cout <<ans << endl;

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