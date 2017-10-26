#include <bits/stdc++.h>
using namespace std;
bool prime(int x){
	for(int i=2; i<=sqrt(x); i++) if(x%i==0) return false;
	return true;
}
int main() {
	int n; cin >> n;
	long long  ans=0;
	
	while(n--){
		string inp; cin >> inp;
		int x=0;
		for(int i=0; i<inp.length(); i++){
			x+=(inp[i]-'0');
		}
		long long K=0LL;
		if(prime(x)) K=1LL;
		
		ans=(ans*2LL)+K;
	}
	cout << ans << endl;
	return 0;
}