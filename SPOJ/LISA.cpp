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
#define si2(n1,n2) scanf("%d%d",&n1,&n2)
#define si3(n1,n2,n3) scanf("%d%d%d",&n,&n2,&n3)
#define sll(n) scanf("%lld",&n)
#define sll2(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll3(n1,n2,n3) scanf("%lld%lld%lld",&n,&n2,&n3)
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
#define pb push_back

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

char s[104];
int n;
unsigned ll dp[105][105];
bool tempdp[105][105];

unsigned ll helper(int start, int end){
    if(start==end) return s[start]-'0';
    if(tempdp[start][end]==false) return dp[start][end];
    unsigned ll &ans =dp[start][end];
    ans=0;
    for(int i=start; i<end; i++){
        if(s[i]!='*' && s[i]!='+'){
            unsigned ll a=helper(start,i);
            unsigned ll b=helper(i+2, end);
            if(s[i+1]=='+') ans=max(ans, a+b);
            else if(s[i+1]=='*') ans=max(ans, a*b);
        }
    }
    tempdp[start][end]=false;
    return ans;
}

unsigned ll helper2(int start, int end){
    if(start==end) return s[start]-'0';
    if(tempdp[start][end]==false) return dp[start][end];
    unsigned ll &ans =dp[start][end];
    bool temp=false; ans=0;
    for(int i=start; i<end; i++){
        if(s[i]!='*' && s[i]!='+'){
            unsigned ll a=helper2(start,i);
            unsigned ll b=helper2(i+2, end);
            if(s[i+1]=='+') {
                if(!temp) {ans=a+b;temp=true;}
                ans=min(ans, a+b);
            }
            else if(s[i+1]=='*') {
                if(!temp){ans=a*b;temp=true;}
                ans=min(ans, a*b);
            }
        }
    }
    tempdp[start][end]=false;
    return ans;
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    scanf("%s",s);
    n=strlen(s);
    mem(tempdp,true);
    mem(dp,0);
    cout << helper(0,n-1);
    mem(tempdp,true);
    cout << " " << helper2(0,n-1);
}

int main(){
    int t=1; si(t);
    while(t--){
        solve();
    }
    return 0;
}