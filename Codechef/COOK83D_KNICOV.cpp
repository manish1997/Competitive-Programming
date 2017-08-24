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
#define inf 1<<30
int n, m;
int dp[52][8][8][8][8];
bool check(int K3, int A1, int K1){
	if(K3&1){
		A1|=2;
	}
	if(K3&2){
		A1|=5;
	}
	if(K3&4){
		A1|=2;
	}
	if((A1|K1)==7) return true;
	return false;
}
int helper(int ind, int A1, int K1, int A2, int K2){
	if(ind==m){
		if((A1|K1)==7 && (A2|K2)==7) return 0;
		return inf;
	}
	int &res = dp[ind][A1][K1][A2][K2];
	if(res!=-1) return res;
	res=inf;
	int A3=0;
	if(K2&1) A3|=4;
	if(K2&(1<<2)) A3|=1;
	if(K1&1) A3|=2;
	if(K1&(1<<1)) A3|=5;
	if(K1&(1<<2)) A3|=2;
	rep(i,0,8){
		if(!check(i,A1,K1)) continue;
		int temp=A2;
		int cnt=0;
		if(i&1){
			A2|=4;
			cnt+=1;
		}
		if(i&4){
			A2|=1;
			cnt+=1;
		}
		if(i&2) cnt+=1;

		res=min(res, cnt+helper(ind+1, A2, K2, A3, i));
		A2=temp;
	}
	return res;
}
int main(){
	int t; si(t);
	while(t--){
		memset(dp,-1,sizeof(dp));
		si(n); si(m);
		if(n==1){
			pin(m);
		}
		else if(n==2){
			pin((m/6)*4+(min(m%6,2)*2));
		}
		else{
			if(m>=4){
				pin(helper(2,0,0,0,0));
			}
			if(m==3){
				pin(4);
				continue;
			}
			if(m==2){
				pin(4);
				continue;
			}
			if(m==1){
				pin(3);
				continue;
			}

		}
	}
	return 0;
}
