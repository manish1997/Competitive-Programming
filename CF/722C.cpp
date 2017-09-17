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
#define mod 1000000007
#define MAX 100005
#define newLine printf("\n")
pair<ll,ll> Parent[100005];
ll arr[100005];
vector<ll> Q;
ll n;
pair<ll,ll> root(ll a){
	//cout << a << " " << Parent[a].first << " " << Parent[a].second<< endl;
	if(Parent[a].first!=a) Parent[a]=root(Parent[a].first);
	return Parent[a];
}
void union1(pair<ll,ll> a, pair<ll,ll> b){
	a=root(a.first);
	b=root(b.first);
	Parent[a.first]=b;
	return;
}
int main(){
	sll(n);
	rep(i,1,n+1){
		ll x;
		sll(x);
		arr[i]=-1;
		Parent[i]={i,x};
	}
	rep(i,0,n){
		ll x;sll(x);
		Q.push_back(x);
	}
	ll pastAns=0;
	vector<ll> Ans;
	Ans.push_back(pastAns);
	for(ll i=Q.size()-1; i>=0; i--){
		ll x=Q[i];
		arr[x]=Parent[x].second;
		if(x!=n && arr[x+1]!=-1){
			union1(root(x),root(x+1));
			pair<ll,ll> temp=root(x);
			Parent[temp.first].second+=arr[x];
			pastAns=max(pastAns, Parent[temp.first].second);
		}
		if(x!=1 && arr[x-1]!=-1){
			pair<ll,ll> tt=root(x);
			union1(tt,root(x-1));
			pair<ll,ll> temp=root(x);
			Parent[temp.first].second+=tt.second;
			pastAns=max(pastAns, Parent[temp.first].second);
		}
		pastAns=max(pastAns, arr[x]);
		Ans.push_back(pastAns);
	}
	for(ll i=Ans.size()-2; i>=0; i--){
		plln(Ans[i]);
	}

	return 0;
}