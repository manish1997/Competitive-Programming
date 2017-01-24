#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sll(n) scanf("%lld", &n)
ll BIT[60001];
ll posOfLast[2000001];
ll n,d;
pair<ll,pair<ll,ll>> queries[200001];
ll arr[60001];
ll ans[200001];
bool comp(pair<ll,pair<ll,ll>> A, pair<ll,pair<ll,ll>> B){
	return A.second.second<B.second.second;
};

void updateBIT(ll index, ll val){
	while(index<=n){
		BIT[index]+=val;
		index+= (index&-index);
	};
};
ll queryBIT(ll index){
	ll answer=0;
	while(index>0){
		answer+=BIT[index];
		index-=(index&-index);
	};
	return answer;
};
int main() {
	// your code goes here
	sll(n);
	for(ll i=1; i<=n; i++) sll(arr[i]);
	sll(d);
	for(ll i=0; i<d; i++){
		queries[i].first=i;
		sll(queries[i].second.first);
		sll(queries[i].second.second);
	};
	sort(queries, queries+d, comp);
	memset(posOfLast, -1, sizeof(posOfLast));
	memset(BIT,0, sizeof(BIT));
	
	ll posInQuery=0;
	
	for(ll i=1; i<=n; i++){
		if(posOfLast[arr[i]]!=-1) {
			updateBIT(posOfLast[arr[i]], -1);
		};
		posOfLast[arr[i]]=i;
		updateBIT(i,1);
		while(posInQuery<d && queries[posInQuery].second.second==i){
			int temp=(queries[posInQuery].second.first)-1;
			ans[queries[posInQuery].first]=queryBIT(i);
			ans[queries[posInQuery].first]-=queryBIT(temp);
			//cout << queries[posInQuery].second.first << " " << queries[posInQuery].second.second << endl;
			posInQuery++;
		};
	};
	
	for(int i=0; i<d; i++) printf("%lld\n", ans[i]);
	
	return 0;
};
