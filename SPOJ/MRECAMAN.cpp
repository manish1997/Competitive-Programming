#include <iostream>
#include <unordered_map>
using namespace std;
long long answer[500005];
unordered_map<long long, bool> M;
int main() {
	// your code goes here
	answer[0]=0;
	for(int i=1; i<=500000; i++){
		long long temp=answer[i-1]-i;
		if(temp>0 && M.find(temp)==M.end()) {
			answer[i]=temp;
		}
		else{
			temp=answer[i-1]+i;
			answer[i]=temp;
		};
		M[temp]=true;
	};
	while(true){
		int x; scanf("%d",&x);
		if(x==-1) break;
		printf("%lld\n", answer[x]);
	};
	return 0;
}
