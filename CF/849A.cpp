#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;
#define ll long long
#define si(n) cin >> n
#define sll(n) cin >> n
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
#define MAX 100005
#define newLine printf("\n")
int n; int arr[100];
int main(){
	//memset(dp,-1,sizeof(dp));
	si(n);
	rep(i,0,n) si(arr[i]);
	if(arr[0]%2!=0 && arr[n-1]%2!=0 && n%2!=0) printf("Yes\n");
	else printf("No\n");
	return 0;
}