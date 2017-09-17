#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define rep(i,n) for(ll i=1; i<=n; i++)
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

ll n,q, block;
ll arr[200002];
struct query{
	ll L,R,ind;
};
query queries[200002];
ll frequency[1000002];
ll ans[200002];
bool comp(query A, query B){
	if( A.L / block != B.L / block ) return A.L < B.L;
	return A.R < B.R;
};
ll answer=0;

void add(ll index){
	ll K=frequency[arr[index]];
	answer+=((2*K)*arr[index] + arr[index]);
	frequency[arr[index]]++;
	
};

void del(ll index){
	frequency[arr[index]]--;
	ll K=frequency[arr[index]];
	answer-=2*K*arr[index]+arr[index];
};

ll L,R, currentL, currentR;

ll checkAns( ll i ){
	
		L=queries[i].L;
		R=queries[i].R;
		
		while(currentL<L){
			del(currentL);
			currentL++;
		};
		while(currentL>L){
			add(currentL-1);
			currentL--;
		};
		
		while(currentR<R){
			add(currentR+1);
			currentR++;
		};
		while(currentR>R){
			del(currentR);
			currentR--;
		};
		
		return answer;
};


int main() {
	// your code goes here
	//optimizar_io
	//cin >> n >> q;
	scanf("%lld%lld", &n, &q);
	block=sqrt(n);
	//rep(i,n) cin >> arr[i];
	rep(i,n) scanf("%lld", &arr[i]);
	memset(frequency,0,sizeof(frequency));
	
	rep(i,q) {
		scanf("%lld%lld", &queries[i].L, &queries[i].R);//cin >> queries[i].L >> queries[i].R;
		queries[i].ind=i;
	};
	
	sort(queries+1, queries+q+1, comp);
	
	currentL=queries[1].L;
	currentR=queries[1].R;
	
	for(ll i=currentL; i<=currentR; i++)	add(i);
	
	ans[queries[1].ind]=answer;
	
	for(ll i=2; i<=q; i++){
		ans[queries[i].ind]=checkAns(i);
	};
	//for(ll i=1; i<=q; i++) cout << ans[i] << '\n';
		for(ll i=1; i<=q; i++) printf("%lld\n", ans[i]);
	return 0;
}