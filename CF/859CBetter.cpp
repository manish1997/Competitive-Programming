#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	int arr[n+1];
	int dp[n+1];
	int suff[n+1];
	for(int i=0; i<n; i++) cin >> arr[i];
	suff[n-1]=arr[n-1];
	dp[n-1]=arr[n-1];
	for(int i=n-2; i>=0; i--){
		suff[i]=suff[i+1]+arr[i];
		dp[i]=max(arr[i]+suff[i+1]-dp[i+1], dp[i+1]);
	}
	cout <<suff[0]-dp[0] << " " <<  dp[0]<< endl;
	return 0;
}