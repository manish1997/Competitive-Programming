#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	// your code goes here
	int t; cin >> t;
	while(t--){
		double X;
		ll K;
		cin >> X >> K;
		ll tt=(ll)log2(K);
		tt=pow(2,tt);
		double ans=(K-tt);
		ans=(ans*2)+1;
		tt*=2;
		X=X/tt;
		printf("%.10lf\n",X*ans);
	}
	return 0;
}