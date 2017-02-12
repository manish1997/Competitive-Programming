#include <bits/stdc++.h>
using namespace std;

int curr[2000];
int agnesh[2000];
int dp[2001][2001];
int helper(int n, int n_){
	if(n<0 || n_<0) return 0;
	if(dp[n][n_]!=-1) return dp[n][n_];
	if(curr[n_]==agnesh[n]){
		return dp[n][n_]=(1+helper(n-1,n_-1));
	};
	return dp[n][n_]=max(helper(n-1, n_), helper(n,n_-1));
};

int main() {
	int t;
	cin >> t;
	while(t--){
		memset(dp,-1,sizeof(dp));
		int x,n=0;
		while(true){
			scanf("%d",&x);
			if(x) agnesh[n++]=x;
			else break;
		};
		scanf("%d",&x);
		int n_=0;
		int answer=-1;
		while(x){
			curr[n_++]=x;
			while(true){
				scanf("%d",&x);
				if(x) curr[n_++]=x;
				else break;
			};
			answer=max(answer,helper(n-1,n_-1));
			scanf("%d",&x);
			n_=0;
			if(x) memset(dp,-1,sizeof(dp));
		};
		 
		cout << answer << endl;
		
		
	};
	return 0;
}
