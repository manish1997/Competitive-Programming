#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define S second
#define F first
#define P pair<int,int>
#define PP pair<P,int>
using namespace std;
ll n,m;
ll minSal[1005];
ll tempGrid[1005][1005];
ll offered[1005];
vector<int> grid[1005];
unordered_map<ll,ll> M;
unordered_map<ll,ll> CURR;
ll findValid(ll ind){
	ll end=grid[ind].size()-1;
	for(ll i=end; i>=0; i--){
		if(M[grid[ind][i]]>CURR[grid[ind][i]]){
			CURR[grid[ind][i]]++;
			return grid[ind][i];
		}
	}
	return -1;
}
int main(){
	int t; si(t);
	while(t--){
		sll(n); sll(m);
		rep(i,0,1005){
			grid[i].clear();
		}
		M.clear();
		CURR.clear();
		rep(i,1,n+1){
			sll(minSal[i]);
		}
		rep(i,1, m+1){
			ll a,b;
			sll(a);
			sll(b);
			M[a]=b;
			offered[i]=a;
			CURR[a]=0;
		}

		rep(i,1,n+1){
			string s; cin >> s;
			rep(j,1,m+1){
				if(s[j-1]=='1' && minSal[i]<=offered[j]){
					grid[i].push_back(offered[j]);
					//cout << i << " " << offered[i] << endl;
				}
			}
		}
		rep(i,1,n+1){
			sort(grid[i].begin(), grid[i].end());
		}
		ll notSel=0;
		ll salOff=0;
		for(ll i=1; i<=n; i++){
			ll x=findValid(i);
			if(x==-1){
				notSel++;
				continue;
			}
			salOff+=x;
		}
		ll noCom=0;
		for(ll i=1; i<=m; i++){
			if(CURR[offered[i]]==0) noCom++;
		}
		plls(n-notSel);
		plls(salOff);
		plln(noCom);
	}
	return 0;
}