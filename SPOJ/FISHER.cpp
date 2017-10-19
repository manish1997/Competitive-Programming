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
#define P pair<int,int>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define INF 100000
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

int n,t;
int t2[51][51];
int toll[51][51];
P dp[51][1002];
bool visited[52];

void reset(){
    //check if your logic is correct but still wrong answer
    rep(i,0,51) rep(j,0,1002) dp[i][j]={-1,-1}; 
    mem(visited,false);
}
P helper(int start, int rem){
    if(rem<0) return {INF,INF};
    if(start==n-1) return {0,0};
    if(dp[start][rem].f!=-1) return dp[start][rem];
    P &ans = dp[start][rem];
    ans={INF,INF};
    visited[start]=true;
    rep(i,0,n){
        if(visited[i]==false){
            P temp=helper(i,rem-t2[start][i]);
            if(temp.f+toll[start][i]<ans.f){
                ans.f=temp.f+toll[start][i];
                ans.s=temp.s+t2[start][i];
            }
            // else if(temp.f+toll[start][i]==ans.f){
            //     if(temp.s+t2[start][i]<ans.s){
            //         ans.s=temp.s+t2[start][i];
            //     }
            // }
        }
    }
    visited[start]=false;
    return ans;
}
void solve(){
    reset();
    //solve the problem. You can and you will :) give your best shot..
    rep(i,0,n)rep(j,0,n)si(t2[i][j]);
    rep(i,0,n)rep(j,0,n)si(toll[i][j]);
    pis(helper(0,t).f); pin(helper(0,t).s);
}
int main(){
    while(si2(n,t)!=EOF){
        if(n==0 && t==0) break;
        solve();
    }
    return 0;
}