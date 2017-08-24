#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
int ans=10001;
bool prime[1000000];
int N=1000000;
int sieve(){
	prime[0]=prime[1]=false;
	memset(prime,true,sizeof(prime));
	for(int i=2; i<=sqrt(N); i++){
		if(prime[i]){
			for(int j=i*i; j<N; j+=i) prime[j]=false;
		}
	}
	int cnt=0;
	for(int i=2; i<N; i++) if(prime[i] && (++cnt)==ans) return i;
		return 0;
}
int main(){
	cout << sieve();
	return 0;
}