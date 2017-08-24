#include <iostream>
#include <cstring>
using namespace std;
int main(){
	string s="7316717653//Clip//963450";
	//Can be solved using simple window of 13 numbers. I chose DP as
	// it will solve for all lengths<=k and I wanted to implement bottom
	// up for learning purpose
	long long dp[1000][14];
	memset(dp,0,sizeof(dp));
	for(int i=0; i<s.length(); i++) dp[i][1]=s[i]-'0';
	for(int j=2; j<=13; j++){
		for(int i=0; i<s.length(); i++){
			if(i) dp[i][j]=dp[i-1][j-1]*(s[i]-'0');
		}
	}
	long long ans=0;
	for(int i=0; i<s.length(); i++) ans=max(ans, dp[i][13]);
		cout <<ans;
	return 0;
}