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
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    rep(i,0,m){
    	int a,b;cin>>a>>b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    priority_queue<int> PQ;
    PQ.push(-1);
    bool vis[n+1];
    mem(vis,false);

    while(!PQ.empty()){
    	int curr=-PQ.top();
    	PQ.pop();
    	if(vis[curr]) continue;
    	vis[curr]=true;
    	cout << curr << " ";
    	for(int i=0; i<adj[curr].size(); i++){
    		if(vis[adj[curr][i]]==false){
    			PQ.push(-adj[curr][i]);
    		}
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