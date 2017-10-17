#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#include <algorithm>
#include <climits>
#define f first
#define s second
#define MAXN 18
#define ll long long
#define INF -1e+16
#define MOD 1000000007
#define si(n) scanf("%d",&n)
#define si2(n1,n2) scanf("%d%d",&n1,&n2)
#define si3(n1,n2,n3) scanf("%d%d%d",&n1,&n2,&n3)
#define sll(n) scanf("%lld",&n)
#define sll2(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll3(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
#define pin(n) printf("%d\n",n)
#define mem(A,i) memset(A, i, sizeof(A))
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)

using namespace std;
ll arr[MAXN];
ll pre[MAXN];
ll n,k;
ll dp[MAXN][13173][2][21];

ll helper(int x, int y, int z, int m){
	if(x==n && m<=k) return 1;
	else if(x==n) return 0;
	// cout << x << endl;
	if(dp[x][y][z][m]!=-1) return dp[x][y][z][m];
	if(z==1){
		ll ans=0;
		rep(i,0,n){
			if((1<<i)&y) continue;
			ans+=helper(x+1, y+(1<<i), z, m+abs(arr[x]-(i+1)));
		}
		return dp[x][y][z][m]=ans;
	} 
	else{
		ll ans=0;
		rep(i,0,n){
			if((1<<i)&y || arr[x]<(i+1)) continue;
			if(arr[x]==(i+1)) ans+=helper(x+1, y+(1<<i), 0, m+abs(arr[x]-(i+1)));
			else ans+=helper(x+1, y+(1<<i), 1, m+abs(arr[x]-(i+1)));
		}
		return dp[x][y][z][m]=ans;
	}
}

int main()
{
	// cout << 20*262145*2*21<<endl;
	int t; cin >> t;
	while(t--){
		memset(dp,-1,sizeof(dp));
    	cin >> n >>k;
    	rep(i,0,n) cin >> arr[i];
    	cout << (helper(0,0,0,0)-1) << endl;
	}

    return 0;
}