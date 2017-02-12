#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
int n;
#define ll long long
int main() {
	
	while(true){
		si(n);
		if(!n) break;
		vector<ll> C(n);
		vector<ll> P(n);
		for(int i=0; i<n; i++) sll(C[i]);
		for(int i=0; i<n; i++) sll(P[i]);
		sort(C.begin(), C.end());
		sort(P.begin(), P.end());
		reverse(P.begin(), P.end());
		ll answer=0;
		for(int i=0; i<n; i++){
			answer += (P[i]*C[i]);
		};
		printf("%lld\n",answer);
	};
	
	return 0;
}
