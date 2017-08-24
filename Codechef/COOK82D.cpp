//TODO: SQRT Decomposition will give TLE, couldn't get hash2ing approach
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
ll n,m;
bool ans;
bool answer[MAX];
int arr[100002];
ll pre[1000002][8];
ll preHash[8];
ll pow2[8][100002];
int main() {
	sll(n); sll(m);
	rep(j,2,7)
	for(int i=0; i<100002; i++){
		if(i==0) pow2[j][i]=1;
		else{
			pow2[j][i]=(pow2[j][i-1]*j)%mod;
		}
	}
	for(int i=1; i<=m; i++){
		ll x,y; sll(x); sll(y);
		rep(j,2,7){
			if(arr[x]==1){
				preHash[j]=(preHash[j]-pow2[j][x])%mod;
				while(preHash[j]<0) preHash[j]+=mod;
				arr[x]=0;
			}
			else{
				preHash[j]=(preHash[j]+pow2[j][x])%mod;
				arr[x]=1;
			}
			if(arr[y]==1){
				preHash[j]=(preHash[j]-pow2[j][y])%mod;
				while(preHash[j]<0) preHash[j]+=mod;
				arr[y]=0;
			}
			else{
				preHash[j]=(preHash[j]+pow2[j][y])%mod;
				arr[y]=1;
			}
			pre[i][j]=preHash[j];
		}
	}
	int qq;
	si(qq);
	for(int i=1; i<=qq; i++){
		int a,b;
		si(a); si(b);
		bool pp=true;
		rep(j,2,7) if(pre[a-1][j]!=pre[b][j]) pp=false;
		if(pp) printf("Yes\n");
		else printf("No\n");
	}
}