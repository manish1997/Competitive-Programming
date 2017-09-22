//#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define mem(A,i) memset(A, i, sizeof(A))
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define newLine printf("\n")
ll gcd ( ll  a, ll b ){
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}
string inputString(){
    string i="";
    int temp=getchar();
    while(temp<'a'||temp>'z')
        temp=getchar();
    while(temp>='a'&&temp<='z')
    {
        i+=(char)temp;
        temp=getchar();
    }
    return i;
}

ll expo(ll x, ll n, ll m){
	if(n==0) return 1;
	ll temp=expo(x,n/2,m);
	temp = ((temp%m)*(temp%m))%m;
	if(n%2!=0) temp = ((temp%m)*(x%m))%m;
	return temp;
}

long long add(long long &x, long long y){
        x=x+y;
        x%=mod;
        if(x<0) x+=mod;
        return x;
}
ll dp[4][100100],n,arr[100100];
void reset(){
    //check if your logic is correct but still wrong answer
    mem(dp,0);
    mem(arr,0);
}
void solve(){
    reset();
    //solve the problem. You can and you will :) give your best shot..
    sll(n);
    rep(i,0,n) sll(arr[i]);
    repDown(i,n-1,0){
        dp[1][i]=arr[i]+dp[0][i+2];
        dp[2][i]=arr[i]+arr[i+1]+dp[0][i+4];
        dp[3][i]=arr[i]+arr[i+1]+arr[i+2]+dp[0][i+6];
        dp[0][i]=max(dp[1][i],max(dp[2][i], dp[3][i]));
    }
    plln(dp[0][0]);    
}

int main(){
    int t; si(t);
    while(t--){
        solve();
    }
    return 0;
}