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
ll gcd ( ll  a, ll b )
{
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}
int main(){

	ll n,k;
	cin >> n >> k;
	if(k==0 || n==k){
		cout << "0 0" << endl;
		return 0;
	}
	cout <<"1 ";
	int divs=n/3;
	if(k<=(divs)){
		cout << (k*2) << endl;
		return 0;
	}
	int ans=divs*2;
	k-=divs;
	// << ans << " " << k << endl;
	int rem=n%3;
	if(rem==1){
		k-=1;
		cout << (ans-k) << endl;
	}
	else if(rem==2){
		ans+=1;
		k-=1;
		cout << (ans-k) << endl;
	}
	else{
		cout << (ans-k) << endl;
	}



	return 0;
}