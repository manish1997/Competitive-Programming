#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%i64d\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define S second
#define F first
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define newLine printf("\n")
#define BLOCK 1000
#define MAX 1000050
#define MAXN 100005
int n, m;
int dp[52][3][3][3];
int helper(int ind, int cnt){
	if(ind==m){
		
	}
}
int main(){
	int t; si(t);
	while(t--){
		memset(dp,0,sizeof(dp));
		si(n); si(m);
		if(n==1){

		}
		else if(n==2){

		}
		else{
			if(m>=4){
				pin(helper(2,0));
			}
			if(m==3){
				pin(5);
				continue;
			}
			if(m==2){
				pin(4);
				continue;
			}
			if(m==1){
				pin(1);
				continue;
			}

		}
	}
	return 0;
}