#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define mod 1000000007
#define MAX 100005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n;
bool valid(ll x, ll y){
	return (x>=1 && x<=n && y>=1 && y<=n);
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n;
    pair<ll,ll> home;
    pair<ll,ll> dest;
    cin>>home.f>>home.s;
    cin>>dest.f>>dest.s;

   	char arr[n+1][n+1];
   	rep(i,1,n+1)rep(j,1,n+1)cin>>arr[i][j];

   	bool vis[n+1][n+1];
   	mem(vis,false);
   	queue<pair<ll,ll> > Q;
   	Q.push(home);


   	while(!Q.empty()){
   		pair<ll,ll> curr = Q.front();
   		Q.pop();
   		if(vis[curr.f][curr.s]){
   			continue;
   		}
   		vis[curr.f][curr.s]=true;
   		rep(i,-1,2){
   			rep(j,-1,2){
   				if(abs(i+j)!=1){
   					continue;
   				}
   				ll x= curr.f+i;
   				ll y= curr.s+j;
   				if(valid(x,y) && vis[x][y]==false && arr[x][y]!='1'){

   					Q.push({x,y});
   				}
   			}
   		}
   	}
   	if(vis[dest.f][dest.s]){
   		cout << 0;
   		return;
   	}
   	vector<pair<ll,ll> > temp1;
   	temp1.clear();
   	rep(i,1,n+1){

   		rep(j,1,n+1){
   			if(vis[i][j]){
   				temp1.push_back({i,j});
   			}
   		}
   	}
   	mem(vis,false);

   	Q.push(dest);
   	while(!Q.empty()){
   		pair<ll,ll> curr = Q.front();
   		Q.pop();
   		if(vis[curr.f][curr.s]){
   			continue;
   		}
   		vis[curr.f][curr.s]=true;
   		rep(i,-1,2){
   			rep(j,-1,2){
   				if(abs(i+j)!=1){
   					continue;
   				}
   				ll x= curr.f+i;
   				ll y= curr.s+j;
   				if(valid(x,y) && vis[x][y]==false && arr[x][y]!='1'){
   					Q.push({x,y});
   				}
   			}
   		}
   	}

   	vector<pair<ll,ll> > temp2;
   	temp2.clear();

   	rep(i,1,n+1){
   		rep(j,1,n+1){
   			if(vis[i][j]){
   				temp2.push_back({i,j});
   			}
   		}
   	}
   	ll ans = 1e15;

   	for(ll i=0; i<temp1.size(); i++){
   		for(ll j=0; j<temp2.size(); j++){
   			ll curr = (temp2[j].f-temp1[i].f)*(temp2[j].f-temp1[i].f);
   			curr += (temp2[j].s-temp1[i].s)*(temp2[j].s-temp1[i].s);
   			ans=min(ans, curr);
   		}
   	}
   	cout << ans << endl;






    
}

int main(){
    fast_cin;
    ll t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}