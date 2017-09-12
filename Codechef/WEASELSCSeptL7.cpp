//Only for k=0.. in TODO
#include <bits/stdc++.h>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) prllf("%d\n",n)
#define plln(n) prllf("%i64d\n",n)
#define pis(n) prllf("%d ",n)
#define plls(n) prllf("%lld ",n)
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define S second
#define F first
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define newLine prllf("\n")
ll n,k;
ll arr[100001];
int main(){
	int t; si(t);
	while(t--){
		sll(n); sll(k);
		rep(i,0,n) sll(arr[i]);


		stack<int> S;
		arr[n]=0;
		ll ans=0;
		//S.push(0);
		rep(i,0,n+1){
			if(S.empty() || arr[i]>arr[S.top()]){
				S.push(i);
				continue;
			}
			
			while(!S.empty() && arr[S.top()]>=arr[i]){
				ll temp=arr[S.top()];
				S.pop();
				ll le=0;
				if(!S.empty()) le=S.top()+1;
				ans=max(ans, temp*(i-le));
			}
			S.push(i);
		}
		cout << ans << endl;



	}
	
	return 0;
}