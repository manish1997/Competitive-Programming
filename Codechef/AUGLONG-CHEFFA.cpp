#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define S second
#define F first
#define P pair<int,int>
#define PP pair<P,int>
#define mod 1000000007
ll dp[150][125][125];
ll n;
ll arr[150];
bool check(int ind){
	for(int i=ind; i<150; i++) if(arr[i]) return false;
		return true;
}
ll A,B,I;
ll helper(ll ind, ll a, ll b){
	if((a==0 && b==0) && check(ind)) return 1;
	//cout << dp[ind][a][b] << endl;
	if(dp[ind][a][b]!=-1) return dp[ind][a][b];
	ll ans=helper(ind+1, b, arr[ind+1]);
	if(a>0 && b>0){
		for(ll i=1; i<=min(a,b); i++){
			arr[ind]-=i;
			arr[ind+1]+=i;
			ans=(ans+(helper(ind+1, arr[ind], arr[ind+1])%mod))%mod;
			arr[ind]+=i;
			arr[ind+1]-=i;
		}
	}
	return dp[ind][a][b]=ans;
}
int main() {
	int t; si(t);
	//rep(i,1,50) cout << "50" << " ";
	while(t--){
		A=0;
		B=0;
		I=0;
		memset(arr,0,sizeof(arr));
		memset(dp, -1, sizeof(dp));
		sll(n);
		rep(i,1,n+1){
			sll(arr[i]);
		}
		if(n==1){
			plln(1LL);
			continue;
		}
		plln(helper(2,arr[1],arr[2]));
		// plln(A);
		// plln(B);
		// plln(I);
	}
 
	return 0;
} 
