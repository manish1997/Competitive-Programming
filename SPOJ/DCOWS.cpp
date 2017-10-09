#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e15
ll dp[5002][5002];
int B[5002],G[5002];
int n,m;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)scanf("%d",&B[i]);
    for(int i=0; i<m; i++)scanf("%d",&G[i]);
    sort(B,B+n); sort(G,G+m);
    for(int i=n; i>=0; i--) dp[i][m]=INF;
    for(int i=m; i>=0; i--) dp[n][i]=0;
    for(int i=n-1; i>=0; i--){
    	for(int j=m-1; j>=0; j--){
    		if(n-i>m-j) dp[i][j]=INF;
    		else dp[i][j] = min(dp[i][j+1],abs(B[i]-G[j])+dp[i+1][j+1]);
    	}
    }
    printf("%lld\n",dp[0][0]);
    return 0;
}
