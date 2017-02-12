#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[15][100];

int main() {
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=14; i++){
		dp[i][0]=1;
	//	cout << dp[i][0] << " ";
		for(int j=1; j<100; j++){
			for(int k=j; k>=(j-i+1) && k>=0; k--){
				dp[i][j]+=dp[i-1][k];
			};
		//	cout << dp[i][j] << " ";
		};
//		cout << endl;
	};
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		cout << dp[a][b] << endl;
	};
	return 0;
}
