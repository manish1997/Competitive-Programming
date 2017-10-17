// #include <bits/stdc++.h>
//Couldn't do it in live contest. Should have focused more on
// modulus than thinking of greedy solution.
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
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define P pair<int,int>
#define PP pair<P,int>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define newLine printf("\n")
#define pb push_back
#define sieveMax 10001 //maximum for which u need primality test

//Sieve Start
vector<int> Prime;
void sieve(){
	bool neverMakeThisName[sieveMax];
    mem(neverMakeThisName,false);
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
int n,m;
vector<ll> V[1000002];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    si(n);
    ll x;
    rep(i,1,n+1){
        V[i].clear();
        si(m);
        V[i].pb(0LL);
        rep(j,1,m+1){
            sll(x);
            V[i].pb(x);
        }
        V[i][0]=V[i].back();
    }
    if(n==1){
        pin(0);
        return;
    }
    ll m1=-1e7,m2=-1e7;
    rep(i,1,V[1].size()){
        m1=max(m1,V[1][i]);
        m2=max(m2,-V[1][i]);
    }


    rep(i,2,n+1){
        ll ans=0;
        ll temp1=-1;
        ll temp2=-1;
        rep(j,1,V[i].size()){
            if(j==1){
                ans=max(m1-(i-1)*V[i][j], m2+(i-1)*V[i][j]);
                temp1=ans+i*V[i][j-1];
                temp2=ans-i*V[i][j-1];
                continue;
            }
            ll temp=max(m1-(i-1)*V[i][j], m2+(i-1)*V[i][j]);
            temp1=max(temp1,temp+i*V[i][j-1]);
            temp2=max(temp2,temp-i*V[i][j-1]);
            ans=max(temp,ans);
        }
        if(i==n) plln(ans);
        m1=temp1;
        m2=temp2;
    }


    
}

int main(){
    int t=1; si(t);
    while(t--){
        solve();
    }
    return 0;
}