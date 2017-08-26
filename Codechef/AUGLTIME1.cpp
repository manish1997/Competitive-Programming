#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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
int dp[1000][1000][512];
ll arr[65];
ll n,m;
ll helper(ll n, ll k){
	if(n==1) return k;
	if(k%2==0) return helper(n-1, k/2);
	return (arr[n-1])+helper(n-1,(k-1)/2);
}
int main(){
	int t; si(t);
	arr[0]=1;
	for(int i=1; i<=63; i++) arr[i]=arr[i-1]*2;


	while(t--){
		unsigned long long n, k;
		cin >> n >> k;
		cout << helper(n,k) << endl;
	}
	return 0;
}