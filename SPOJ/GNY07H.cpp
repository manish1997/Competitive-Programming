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
#define si3(n1,n2,n3) scanf("%d%d%d",&n1,&n2,&n3)
#define sll(n) scanf("%lld",&n)
#define sll2(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll3(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
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
#define sieveMax 10000001 //maximum for which u need primality test

//Sieve Start
vector<int> Prime;
void sieve(){
	bool neverMakeThisName[sieveMax];
    neverMakeThisName[0]=neverMakeThisName[1]=true;
    for(int i=4; i<sieveMax; i+=2) neverMakeThisName[i]=true;

    for(int i=3; i<=sqrt(sieveMax); i+=2)
        if(neverMakeThisName[i]==false) {
            for(int j=i*i; j<sieveMax; j+=i) neverMakeThisName[j]=true;
        }

    rep(i,0,sieveMax) if(neverMakeThisName[i]==false) Prime.pb(i);
}
//Sieve End
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
ll n;
ll dp[25][6];
ll helper(int start, int ptr){
    // if(start<0) return 0;
    // if(start==0 && ptr!=5) return 1;
    // else if(start==0) return 0;
    // ll &ans=dp[start][ptr];
    // if(ans!=-1LL) return ans;
    // ans=0LL;
    // if(ptr==0){
    //     rep(i,0,5) ans+=helper(start-1,i);
    // }
    // else if(ptr==1){
    //     ans+=helper(start-1,0);
    //     ans+=helper(start-1,5);
    // }
    // else if(ptr==2){
    //     ans+=helper(start-1,0);
    //     ans+=helper(start-1,3);
    // }
    // else if(ptr==3){
    //     ans+=helper(start-1,0);
    //     ans+=helper(start-1,2);
    // }
    // else if(ptr==4){
    //     ans+=helper(start-1,0);
    // }
    // else{
    //     ans+=helper(start-1,1);
    // }
    // return ans;
    //
    mem(dp,0);
    dp[0][0]=dp[0][1]=1;
    dp[0][2]=dp[0][3]=1;
    dp[0][4]=1;
    rep(i,1,25){
        dp[i][1]=dp[i-1][0]+dp[i-1][5];
        dp[i][2]=dp[i-1][0]+dp[i-1][3];
        dp[i][3]=dp[i-1][0]+dp[i-1][2];
        dp[i][4]=dp[i-1][0];
        dp[i][5]=dp[i-1][1];
        rep(j,0,5) dp[i][0]+=dp[i-1][j];
    }
}
int tc;
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    sll(n);
    if(n<=0){
        pis(tc); 
        pin(1);
        return;
    }
    pis(tc); plln(dp[n-1][0]);
}

int main(){
    int t=1; si(t);
    tc=0;
    helper(0,0);
    while(t--){
        tc++;
        solve();
    }
    return 0;
}