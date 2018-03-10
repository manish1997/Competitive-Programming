#include <bits/stdc++.h>
using namespace std;
#define ll long long

int INTlog2(unsigned long long number){
    int logval=0;
    while(number>>=1) logval++;
    return logval;
}
int main() {
	unsigned ll n,k;
	cin>>n>>k;
	if(k==1) cout << n << endl;
	else cout << (1LL<<(INTlog2(n)+1LL))-1 << endl;
	return 0;
}