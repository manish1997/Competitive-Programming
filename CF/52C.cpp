#include <iostream>
#include <cmath>
#include <climits>
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
#define MAX 200005
#define newLine printf("\n")
ll n,m;
ll arr[MAX];
ll SEG[4*MAX];
ll query[3];
ll Lazy[4*MAX];
void build(ll node, ll start, ll end){
	if(start>end) return;
	if(start==end){
		SEG[node]=arr[start];
		return;
	}
	ll mid=(start+end)>>1;
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);
	SEG[node]=min(SEG[2*node], SEG[2*node+1]);
}
void check(string s){
	ll temp=0;
	int curr=0;
	query[2]=LLONG_MIN;
	bool neg=false;
	for(int i=0; i<=s.length(); i++){
		if(i==s.length() || s[i]==' '){
			query[curr++]=temp;
			temp=0;
		}
		else if(s[i]!='-'){
			temp=temp*10+s[i]-'0';
		}
		else{
			neg=true;
		}
	}
	if(neg){
		query[2]*=-1;
	}
}


ll finalQuery(ll node, ll start, ll end, ll l, ll r){
	if(start>end || l>end || r<start) return LLONG_MAX;
	if(Lazy[node]){
		SEG[node]+=Lazy[node];
		if(start!=end){
			Lazy[2*node]+=Lazy[node];
			Lazy[2*node+1]+=Lazy[node];
		}
		Lazy[node]=0;
	}
	if(l<=start && r>=end){
		return SEG[node];
	}
	ll mid=(start+end)>>1;
	ll left=finalQuery(2*node, start, mid, l, r);
	ll right=finalQuery(2*node+1, mid+1, end, l, r);
	return min(left, right);
}
void queryfunc(ll l, ll r){
	if(l<=r) cout << finalQuery(1LL,0LL,n-1LL,l,r) << endl;
	else cout << min(finalQuery(1LL,0LL,n-1LL,l,n-1),finalQuery(1LL,0LL,n-1LL,0LL,r)) << endl;
}
void finalUpdate(ll node, ll start, ll end, ll l, ll r, ll val){
	if(Lazy[node]){
		SEG[node]+=Lazy[node];
		if(start!=end){
			Lazy[2*node]+=Lazy[node];
			Lazy[2*node+1]+=Lazy[node];
		}
		Lazy[node]=0;
	}
	if(start>end || l>end || r<start) return;
	if(l<=start && r>=end){
		SEG[node]=SEG[node]+val;
		if(start!=end){
			Lazy[2*node]+=val;
			Lazy[2*node+1]+=val;
		}
		return;
	}
	ll mid=(start+end)>>1;
	finalUpdate(2*node, start, mid, l, r, val);
	finalUpdate(2*node+1, mid+1, end, l, r, val);
	SEG[node]=min(SEG[2*node], SEG[2*node+1]);
	return;
}
void update(ll l, ll r, ll value){
	if(l<=r) finalUpdate(1LL,0LL,n-1LL,l,r,value);
	else {
		finalUpdate(1LL,0LL,n-1LL,l,n-1LL,value);
		finalUpdate(1LL,0LL,n-1LL,0LL,r,value);
	}
}
int main(){
	sll(n);
	rep(i,0,n) sll(arr[i]);
	build(1,0,n-1);
	sll(m);
	getchar();
	rep(i,0,m){
		string s;
		getline(cin, s);
		check(s);
		if(query[2]!=LLONG_MIN)
			update(query[0],query[1],query[2]);
		else
			queryfunc(query[0],query[1]);
	}
	return 0;
}