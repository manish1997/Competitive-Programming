//#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define mem(A,i) memset(A, i, sizeof(A))
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define S second
#define F first
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define newLine printf("\n")
pair<int,int> dp[55];
int n;
int arr[55];
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
void reset(){
    //check if your logic is correct but still wrong answer
    rep(i,0,55) dp[i]={-1,-1};
}
pair<int,int> helper(int start){
    if(start==n) return {0,0};
    if(start==(n-1)) return {arr[start],0};
    if(dp[start].first!=-1) return dp[start];
    //assume X has first chance and he takes start's value
    //helper(start+1).first
    pair<int,int> temp=helper(start+1);
    if((temp.s+arr[start])>temp.f) return dp[start]={temp.s+arr[start], temp.f};
    return dp[start]={temp.f, temp.s+arr[start]};
}
void solve(){
    reset();
    //solve the problem. You can and you will :) give your best shot..
    si(n);
    rep(i,0,n) si(arr[i]);
    pair<int,int> ans=helper(0);
    cout << ans.second << " " << ans.first << endl;
}

int main(){
    int t; t=1;
    while(t--){
        solve();
    }
    return 0;
}