#include <iostream>
#include <algorithm>
using namespace std;
#define si(n) scanf("%d",&n)
int t,n;
#define P pair<int,int>
#define S second
#define F first
P arr[100001];

bool comp(P A, P B){
	if(A.S==B.S) return A.F<B.F;
	return A.S<B.S;
};

int main(){
	si(t);
	while(t--){
		si(n);
		for(int i=0; i<n; i++) {
			si(arr[i].F); si(arr[i].S);
		};
		sort(arr,arr+n, comp);
		int prevPoint=0;
		long long answer=0;
		for(int i=0; i<n;){
			int currR=arr[i].S;
			while(i<n && arr[i].S==currR){
				if(arr[i].F>=prevPoint) {
					prevPoint=arr[i].S;
					answer++;
				};
				i++;
			};
		};
		printf("%lld\n",answer);
		
	};
	
	return 0;
};
