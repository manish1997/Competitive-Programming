// (x1+x2+x3)=-a;
// (x1*x2+x1*x3+x2*x3)=b;
// (x1*x2x3)=-c;
// (x1+x2+x3)^2= x1^2 + x2^2 + x3^2 + 2*(b);
// therefore 
// x1^2 + x2^2 + x3^2 = (-a)^2 - 2*(b) = a*a-2*b;

#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long answer=a*a;
		answer-=(2*b);
		printf("%lld\n",answer);
	};
	return 0;
}
