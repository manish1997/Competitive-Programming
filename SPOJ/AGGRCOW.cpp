#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define slld(n) scanf("%lld", &n)
#define rep(i,n) for(int i=0; i<n; i++)
ll C,n;
ll arr[100001];
bool check(ll gap){
	ll start=arr[0];
	ll end=arr[n-1];
	ll cows=C-2;
	for(int i=1; i<n && cows; i++){
		if((arr[i]-start)>=gap){
			start=arr[i];
			cows--;
		};
	};
	if(!cows && (end-start)>=gap) return true;
	return false;
};
ll answer(){
	ll start=0;
	ll end=arr[n-1];
	while(start<=end){
		int mid=(start+end)/2;
		if(check(mid)){
			start=mid+1;
		}
		else{
			end=mid-1;
		};
	};
	return (start-1);
	
};
int main() {
	ll t;
	slld(t);
	while(t--){
		slld(n);slld(C);
		rep(i, n) slld(arr[i]);
		sort(arr, arr+n);
		cout << answer() << endl;
	};
	return 0;
}
