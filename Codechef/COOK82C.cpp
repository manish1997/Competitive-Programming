//TODO: not correct. toDO.
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
//multiset<ll> M;
int main(){
	sll(n);
	sll(m);
	ll y;
	ll x;
	ll ans=INT_MAX;
	rep(y,1,101){
		rep(x,1,10001){
			//cout <<y << x << endl;
			if(pow(y,6)==(pow(x,6)+8*pow(x,4)-6*(pow(x,2))+8)){
				cout << y << " " << x << endl;
			}
		}
	}
	cout << ans << endl;
	return 0;
}