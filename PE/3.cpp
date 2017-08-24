#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool prime[1000001];
vector<long long> P;
void sieve(){
	memset(prime, false, sizeof(prime));
	prime[0]=prime[1]=true;
	for(long long i=2; i<=sqrt(1000001); i++){
		if(!prime[i])for(long long j=i*i; j<1000001; j+=i){
			prime[j]=true;
		}
	}
	for(long long j=2; j<1000001; j++) if(prime[j]==false) P.push_back(j);
}

int main(){
	sieve();
	long long x=600851475143;
	long long last=-1;
	cout << P.size() << endl;
	for(int i=0; i<P.size(); i++){
		if(x%P[i]) continue;
		cout << P[i] << endl;
		while(x%P[i]==0) x=x/P[i];
		last=P[i];
	}
	if(x>1) last=x;
	cout << last << endl;
	return 0;
}