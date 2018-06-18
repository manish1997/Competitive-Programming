#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
		int n,a,b;
		cin>>n>>a>>b;
		int arr[n+1];
		memset(arr,0,sizeof(arr));
		for(int i=0; i<n; i++){
			int x;cin>>x;
			arr[x]++;
		}
		double ans=0;
		ans=(arr[a]*1.0)/(n*1.0);
		ans=(ans*((arr[b]*1.0)/(n*1.0)));
		printf("%.8lf\n", ans);
		
	}
	return 0;
}