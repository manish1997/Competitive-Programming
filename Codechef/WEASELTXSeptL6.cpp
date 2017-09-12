#include <bits/stdc++.h>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) prllf("%d\n",n)
#define plln(n) prllf("%i64d\n",n)
#define pis(n) prllf("%d ",n)
#define plls(n) prllf("%lld ",n)
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define S second
#define F first
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define newLine prllf("\n")
ll n,q;
vector<int> adj[272144];
vector<int> level[272144];
ll L[272144];
int Level;
// ll power(ll a, ll b){
// 	ll t=1;
// 	for(int i=1; i<=b; i++) t*=a;
 
// 	return t;
// }
// void binary(ll temp){
// 	string s; while(temp){
// 		if(temp%2){
// 			s.push_back('1');
// 		}
// 		else s.push_back('0');
// 		temp/=2;
// 	}
// 	reverse(s.begin(), s.end());
// 	cout << s << endl;
// }
void dfs(int node, int parent, int l){
	Level=max(Level,l);
	level[l].push_back(node);
	rep(i,0,adj[node].size()){
		if(adj[node][i]!=parent){
			dfs(adj[node][i],node, l+1);
		}
	}
}
vector<ll> generate(int start, int end, int top, int bottom){
	vector<ll> A(end-start+1,0);
	// cout << "st end "<< start << " " << end << endl;
	// cout << "top bott " << top << " " << bottom << endl;
	if(end-start==1){
		A[start]=L[top]^L[bottom];
		A[end]=L[top];
		 // cout << L[top] << " " << L[bottom] << endl;
		 // cout << V[start] << " " << V[end] << endl;
		return A;
	}
	vector<ll> LT=generate(start, (start+end)/2, top, (top+bottom)/2);
	rep(i,0,LT.size()) A[i]=LT[i];
	int size=(end-start+1);
	rep(i, LT.size(), end+1) A[i]=A[i-(size/2)];
	// rep(i,0,maxxL) cout << V[i] << " ";
	// cout << endl;
	LT=generate(start,((start+end)/2), 1+((top+bottom)/2), bottom);
	rep(i,0,LT.size()) A[i]^=LT[i];
	// rep(i,0,maxxL) cout << V[i] << " ";
	// cout << endl;
	return A;
}
int main(){
	sll(n); sll(q);
	if(n==1){
		ll x; cin >> x;
		rep(i,0,q) cout << x << endl;
		return 0;
	}
	rep(i,0,n-1){
		int u,v;
		si(u); si(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	Level=0;
	dfs(0,-1, 1);
	// cout << Level << endl;
	ll val[200005];
	rep(i,0,n) sll(val[i]);
	rep(i,1,Level+1){
		rep(j,0,level[i].size()){
			L[i]^=val[level[i][j]];
		}
		//cout << i << " " <<  L[i]<< endl;
	}
	bool flag=0;
	double temp=log2((double)Level)-((int)log2(Level));
	// cout << temp << endl;
	if(temp==0) flag=1;
	int maxxL=pow(2,(floor(log2(Level))+1));
	if(flag) maxxL/=2;
	// cout << maxxL << endl;
	vector<ll> V=generate(0,maxxL-1, 1, maxxL);
	// for(int i=0; i<maxxL; i++){
	// 	for(int j=Level-1; j>=1; j--){
	// 		L[j]^=L[j+1];
	// 	}
	// 	V.push_back(L[1]);
	// }
	// cout << "ans\n";
	// rep(i,0,V.size()) cout << V[i] << endl;
	for(int i=0; i<q; i++){
		ll Q;sll(Q);
		Q=(Q-1)%V.size();
		if(Q==-1) Q+=V.size();
		cout << V[Q] << endl;
	}
// 	cout << pow(2,floor((int)log2(100000))+1) << endl;
// 	cout << floor((int)log2(100000)) << endl;
// 	ll t; cin >> t;
// 	while(t<64){
// 		ll curr=power(2LL,t)-1LL;
// 		ll temp=curr;
// 		if(log2(t)==floor(log2(t)) && temp==curr){
// 				binary(temp);
// 			// if(temp&1) cout << "present" << endl;
// 			// else cout << "not present " << endl;
// 		}
// 		for(ll i=(t-2); i>=0; i-=2) temp=temp^(1LL<<i);
// 			ll ans=1;
// 		 while(temp!=curr){
// 		 	if(log2(t)==floor(log2(t)))
// 		 		binary(temp);
// 			// if(temp&1) cout << "present" << endl;
// 			// else cout << "not present " << endl;
// 			for(ll i=t-2; i>=0; i--){
// 				ll l=temp&(1LL<<i);
// 				ll r=temp&(1LL<<(i+1));
// 				//cout << l << " r " << r << endl;
// 				if(l&&r || (!l && !r)) temp&=(~(1LL<<i));
// 				else temp|=(1LL<<i);
// 				//cout << temp << endl;
// 			}
// 			ans++;
			
// 			//if(ans==4) break;
 
// 		 }
// 		//cout << t << "  ans " << ans << " " << pow(2,floor((int)log2(log2(curr))+1))<< endl;
 
// if(t==64)
// 		break;
// 		t++;
// 	}
	return 0;
}