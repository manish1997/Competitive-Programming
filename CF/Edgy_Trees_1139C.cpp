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
vector<pair<int,int>> adj[MAX];
bool visited[MAX];
int currentColor;
int group[MAX];

void dfs(int node){
	group[currentColor]++;
	visited[node]=true;
	rep(i,0,adj[node].size()){
		if(adj[node][i].s==1) continue;
		if(visited[adj[node][i].f]) continue;
		dfs(adj[node][i].f);
	}

}

//Modulus Expo
ll expo(ll x, ll n, ll m){
    if(n==0 || x==1) return 1;
    ll temp=expo(x,n/2,m);
    temp = ((temp%m)*(temp%m))%m;
    if(n%2!=0) temp = ((temp%m)*(x%m))%m;
    return temp;
}
//end Modulus Expo

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n,k;cin>>n>>k;
    rep(i,0,n-1){
    	int a,b,c;cin>>a>>b>>c;
    	adj[a].pb({b,c});
    	adj[b].pb({a,c});
    }


    currentColor = 0;
    rep(i,1,n+1){
    	if(visited[i]) continue;
    	currentColor++;
    	dfs(i);
    }
    // tr1(currentColor);

    ll ans = expo(n,k,mod);

    rep(i,0,MAX){
    	ans=(ans-expo(group[i],k,mod)+mod)%mod;
    }
    while(ans<0)ans+=mod;
    ans%=mod;
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