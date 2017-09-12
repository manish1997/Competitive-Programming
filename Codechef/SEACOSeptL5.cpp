#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <map>
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
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define newLine printf("\n")

ll n,m;
ll SEG[2][4*MAX];
ll lazy[2][4*MAX];
pair<int,pair<ll,ll> > arr[MAX];

ll add(ll &x, ll y){

	x=(x+y)%mod;
	if(x<0) x+=mod;
	return x;
}

ll query(int node, int start, int end, int index, int num){
	if(start>end || index>end || index<start) return 0;
	if(lazy[num][node]){
		add(SEG[num][node],lazy[num][node]);
		if(start!=end){
			add(lazy[num][node<<1],lazy[num][node]);
			add(lazy[num][(node<<1)|1],lazy[num][node]);
		}
		lazy[num][node]=0;
	}
	if(start==end && index==start) return SEG[num][node];
	int mid=(start+end)>>1;
	if(index<=mid) return query(node<<1, start, mid, index, num);
	else return query((node<<1)|1, mid+1, end, index, num);
}

void update(int node, int start, int end, int l, int r, ll val, int num){
	if(lazy[num][node]){
		add(SEG[num][node],lazy[num][node]);
		if(start!=end){
			add(lazy[num][node<<1],lazy[num][node]);
			add(lazy[num][(node<<1)|1],lazy[num][node]);
		}
		lazy[num][node]=0;
	}
	if(start>end || l>end || r<start) return;
	if(l<=start && r>=end) {
		add(SEG[num][node],val);
		if(start!=end){
			add(lazy[num][node<<1],val);
			add(lazy[num][(node<<1)|1],val);
		}
		return;
	}
	int mid=(start+end)>>1;
	update(node<<1, start, mid, l, r, val, num);
	update((node<<1)|1, mid+1, end, l, r, val, num);
	SEG[num][node]=0;
	add(SEG[num][node],SEG[num][node<<1]);
	add(SEG[num][node],SEG[num][(node<<1)|1]);
	return;
}
int main(){
	int t; si(t);
	while(t--){
		sll(n); sll(m);
		rep(i,0,m){
			si(arr[i].f);
			sll(arr[i].s.f);
			sll(arr[i].s.s);
		}
		memset(SEG,0,sizeof(SEG));
		memset(lazy,0,sizeof(lazy));
		for(int i=m-1; i>=0; i--){
			if(arr[i].f==2){
				ll val=query(1,0,m-1,i,0);
				add(val,1LL);
				//cout << i << " " << val << endl;
				update(1,0,m-1,arr[i].s.f-1, arr[i].s.s-1, val,0);
			}
			else update(1,0,m-1,i,i,1,0);
		}
		rep(i,0,m){
			ll val=query(1,0,m-1,i,0);
			//cout << val << " ";
			if(arr[i].f==1)	update(1,0,n-1,arr[i].s.f-1, arr[i].s.s-1, val, 1);
		}
		rep(i,0,n){
			ll val=query(1,0,n-1,i,1);
			plls(val);
		}
		newLine;

		
		
	}
	return 0;
}
