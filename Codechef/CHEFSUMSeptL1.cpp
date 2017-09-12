#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <map>
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
#define MAX 100005
#define s second
#define f first
#define newLine printf("\n")
int n;
ll arr[100002];
ll suff[100002];
ll pre[100002];
int main(){
	int t; si(t);
	while(t--){
		si(n);
		rep(i,1,n+1) sll(arr[i]);
		arr[0]=0LL;
		arr[n+1]=0LL;
		rep(i,1,n+1) pre[i]=arr[i]+pre[i-1];
		for(int i=n; i>=1; i--) suff[i]=arr[i]+suff[i+1];
		int ans=1;
		ll sum=pre[1]+suff[1];
		rep(i,2,n+1){
			if(suff[i]+pre[i]<sum){
				sum=suff[i]+pre[i];
				ans=i;
			}
		}
		pin(ans);
	}
	return 0;
}