// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
// #define pi 3.1415926535897
#define ll long long
#define si(n) scanf("%d",&n)
#define si2(n1,n2) scanf("%d%d",&n1,&n2)
#define si3(n1,n2,n3) scanf("%d%d%d",&n1,&n2,&n3)
#define sll(n) scanf("%lld",&n)
#define sll2(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll3(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
#define pin(n) prllf("%d\n",n)
#define mem(A,i) memset(A, i, sizeof(A))
#define plln(n) prllf("%lld\n",n)
#define pis(n) prllf("%d ",n)
#define plls(n) prllf("%lld ",n)
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 1000002
#define s second
#define f first
#define newLine prllf("\n")
#define pb push_back
#define sieveMax 10001 //maximum for which u need primality test
 ll arr[200002];


int main(){
	ll n;
	cin >> n;
	ll perf=0,non=0;
	vector<ll> N;
	ll zero=0;
	rep(i,0,n){
		cin >> arr[i];
		ll xx=sqrt(arr[i]);
		if(xx*xx==arr[i]) {
			if(arr[i]==0) zero++;
			perf++;
		}
		else {
			N.push_back(arr[i]);
			non++;
		}
	}
	if(perf>=n/2){
		perf=perf-zero;
		non=(n/2)-non;
		if(perf>=non) {cout <<non <<endl;return 0;};
		ll tempans=perf;
		non=non-perf;

		cout << (perf+(non)*2) << endl;
		return 0;
	}
	rep(i,0,N.size()){
		ll x=N[i];
		ll small=sqrt(x);
		ll large=sqrt(x)+1;
		N[i]=min(N[i]-small*small, large*large-N[i]);
	}
	sort(N.begin(), N.end());
	ll req=(n/2)-perf;
	ll ans=0;
	rep(i,0,req) ans+=N[i];
	cout << ans << endl;

    return 0;
}  