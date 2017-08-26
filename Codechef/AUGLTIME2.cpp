#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%lld\n",n)
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
ll arr[26];
bool A[26];
int main(){
	int t; si(t);
	while(t--){
		rep(i,0,26) sll(arr[i]);
		memset(A,false, sizeof(A));
		string s; cin >> s;
		rep(i,0,s.length()){
			A[s[i]-'a']=true;
		}
		ll ans=0;
		rep(i,0,26){
			if(A[i]==false) ans+=arr[i];
		}
		plln(ans);


	}
	return 0;
}