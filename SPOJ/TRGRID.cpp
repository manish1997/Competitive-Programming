#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <climits>
#define ll long long
using namespace std;


int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		if(n>m){
			if(m%2==0) printf("%s\n","U");
			else printf("%s\n","D");
		}
		else {
			if(n%2!=0) printf("%s\n","R");
			else printf("%s\n","L");
		};
		
	};
	return 0;
};
