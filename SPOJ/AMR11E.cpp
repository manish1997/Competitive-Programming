#include <iostream>
using namespace std;

int countPrimeFactors(int n){
	int curr=2;
	int answer=0;
	while(n!=1){
		int temp=n;
		while(n%curr==0){
			n=n/curr;
		};
		if(temp!=n) answer++;
		curr++;
		if(answer>=3) return true;
	};
	return false;
	
};


int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	int k=1;
	int ans[1002];
	int curr=1;
	while(k<=1000){
		if(countPrimeFactors(curr)){
			ans[k]=curr;
			k++;
		};
		curr++;
	};
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	};
	return 0;
}
