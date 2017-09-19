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
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define S second
#define F first
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
int n;
string s;
int dp[2][5001];
void reset(){
    //check if your logic is correct but still wrong answer
    mem(dp,-1);
}
int helper(int start, int end){
    if(start<0) return (n-end);
    if(end>=n) return (start+1);
    if(dp[start][end]!=-1) return dp[start][end];
    int &ans =dp[start][end];
    ans=5005;
    if(s[start]==s[end]) return ans=helper(start-1,end+1);
    ans=min(ans, 1+helper(start-1,end));
    ans=min(ans, 1+helper(start, end+1));
    return ans;
}
void solve(){
    //reset();
    //solve the problem. You can and you will :) give your best shot..
    si(n); cin >> s;

    //Top Down recursion (0.82 sec)
    //need to change space to 5001*5001 for top down to work
    //dp[i][j]==minimum to make ((0--i)||(j--(n-1))) a palindrome
    // int ans=5005;
    // rep(i,0,s.length()) ans=min(ans,helper(i,i));
    // rep(i,0,s.length()-1) ans=min(ans, helper(i,i+1));
    // pin(ans);
    //end Top Down

    //Bottom UP memoization (0.22 sec)
    //Bottom UP memoization with space optimization (0.16 sec)
    
    dp[0][n]=1;
    repDown(i,n-1,0) 
        if(s[i]==s[0]) dp[0][i]=n-i-1; 
        else dp[0][i]=min((1+n-i), 1+dp[0][i+1]);

    int ans=5005;
    ans=min(ans, dp[0][0]);
    ans=min(ans, dp[0][1]);

    rep(start,1,n){
        dp[1][n]=start+1;
        repDown(end,n-1,start){
            if(s[start]==s[end]) {
                dp[1][end]=dp[0][end+1];
            }
            else{
                dp[1][end]=1+dp[0][end];
                dp[1][end]=min(dp[1][end], 1+dp[1][end+1]);
            }
            dp[0][end+1]=dp[1][end+1];
        }
        ans=min(ans, dp[1][start]);
        ans=min(ans, dp[1][start+1]);
    }
    
    // rep(i,0,s.length()) ans=min(ans,dp[i][i]);
    // rep(i,0,s.length()-1) ans=min(ans, dp[i][i+1]);
    pin(ans);
}

int main(){
    int t=1; //si(t);
    while(t--){
        solve();
    }
    return 0;
}