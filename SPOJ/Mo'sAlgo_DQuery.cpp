#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sll(n) scanf("%lld", &n)

ll block,n,d;
pair<ll,pair<ll,ll>> queries[200001]; 
ll arr[30001]; 

bool comp(pair<ll,pair<ll,ll>> A, pair<ll,pair<ll,ll>> B){
	if((A.second.first/block)!=(B.second.first/block)){
		return A.second.first<B.second.first;
	};
	return A.second.second<B.second.second;
};

ll answer=0;
ll countFre[1000001]; 

void add(ll position){
	countFre[arr[position]]++;
	if(countFre[arr[position]]==1) answer++; 
};

void remov(ll position){
	countFre[arr[position]]--;
	if(countFre[arr[position]]==0) answer--; 
};

int main() {
	sll(n);
	block=sqrt(n);
	for(ll i=0; i<n; i++) sll(arr[i]);
	sll(d);
	for(ll i=0; i<d; i++){
		queries[i].first=i;
		sll(queries[i].second.first);
		sll(queries[i].second.second);
		queries[i].second.first--;
		queries[i].second.second--;
	};
	sort(queries, queries+d, comp);
	memset(countFre, 0, sizeof(countFre));
	ll L,R, currentL, currentR;
	currentL=queries[0].second.first;
	currentR=queries[0].second.second;
	
	ll ans[d+1]; 
	
	for(int i=currentL; i<=currentR; i++) add(i); 
	
	ans[queries[0].first]=answer; 
	
	for(ll i=1; i<d; i++){
		L=queries[i].second.first;
		R=queries[i].second.second;
		while(currentL>L) {
			add(currentL-1);
			currentL--;	
		};
		while(currentL<L){
			remov(currentL);
			currentL++;
		};
		while(currentR<R){
			add(currentR+1);
			currentR++;
		};
		while(currentR>R){
			remov(currentR);
			currentR--;
		};
		ans[queries[i].first]=answer;
	};
	
	for(int i=0; i<d; i++) printf("%lld\n", ans[i]);
	
	return 0;
};
