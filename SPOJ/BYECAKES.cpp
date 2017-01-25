#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int given[4];
int reqfor1[4];
int ans[4];
int cakeFormed[4];
int main() {
	while(true){
		for(int i=0; i<4; i++) scanf("%d",&given[i]);
		for(int i=0; i<4; i++) scanf("%d",&reqfor1[i]);
		
		if(given[0]==-1) break;
		int maxCakeFormed=-1;
		for(int i=0; i<4; i++){
			ans[i]=0;
			if(given[i]%reqfor1[i]!=0){
				ans[i]+=(reqfor1[i]-given[i]%reqfor1[i]);
				given[i]+=(reqfor1[i]-given[i]%reqfor1[i]);
			};
			cakeFormed[i]=given[i]/reqfor1[i];
			maxCakeFormed=max(maxCakeFormed, cakeFormed[i]);
		};
		for(int i=0; i<4; i++){
			int gap=maxCakeFormed-cakeFormed[i];
			ans[i]+=gap*reqfor1[i];
			printf("%d ", ans[i]);
		};
		printf("\n");
	};
	return 0;
};
