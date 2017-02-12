#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>, bool>  dp;
int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b,a%b);
};
int main() {
	// your code goes here
	int t; scanf("%d",&t);
	while(t--){
		dp.clear();
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(c%gcd(a,b)!=0 || c>max(a,b)){
			cout << "-1" << endl;
			continue;
		};
		int ans1=0;
		int x=0,y=0;
		while(x!=c && y!=c){
			if(x==0) x=a;
			else if(y==b) y=0;
			else {
				y=x+y;
				x=0;
				if(y>b){
					x=y-b;
					y=b;
				};
			};
			ans1++;
		};
		int ans2=0;
		x=0; y=0;
		while(x!=c && y!=c){
			if(x==0) x=b;
			else if(y==a) y=0;
			else {
				y=x+y;
				x=0;
				if(y>a){
					x=y-a;
					y=a;
				};
			};
			ans2++;
		};
		cout << min(ans1,ans2) << endl;
	};
	return 0;
}
