#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll expo(ll x, ll n, ll m){
    if(n==0) return 1;
    ll temp=expo(x,n/2,m);
    temp = ((temp%m)*(temp%m))%m;
    if(n%2!=0) temp = ((temp%m)*(x%m))%m;
    return temp;
}

int main() {
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		ll ans=expo(2,n,1000000007);
		ans=expo(ans,__builtin_popcount(n),1000000007);
		cout << ans << endl;
	}
	
	return 0;
}