//http://www.math.harvard.edu/~engelwar/MathS305/PolynomialDifferenceTables.pdf
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
#define pis(n) printf("%lld ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define S second
#define F first
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define vi vector<ll>
#define vll vector<ll>
#define newLine printf("\n")
#define pb push_back

vector<vi> V;
ll n, r;
ll gcd ( ll  a, ll b ){
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}
string inputString(){
    string i="";
    ll temp=getchar();
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
    V.clear();

}
void solve(){
    reset();
    //solve the problem. You can and you will :) give your best shot..
    sll(n); sll(r);
    vi temp(n);
    rep(i,0,n) sll(temp[i]);
    V.pb(temp);
    ll i=0;
    while(1){
        temp.clear();
        bool eq=true;
        ll base=V[i][0];
        rep(j,1,V[i].size()){
            if(base!=V[i][j]){
                eq=false;
            }
            temp.push_back(V[i][j]-V[i][j-1]);
        }
        if(eq) break;
        V.pb(temp);
        i++;
    }
    rep(j,0,r) V[i].pb(V[i][0]);
    i--;
    while(i>=0){
        ll len=V[i].size();
        rep(j,1,len+r){
            ll ans=V[i+1][j-1]+V[i][j-1];
            if(j<len) V[i][j]=ans;
            else V[i].pb(ans);
        }
        i--;
    }
    rep(j,n,V[0].size()) pis(V[0][j]);
    newLine;
}

int main(){
    int t; si(t);
    while(t--){
        solve();
    }
    return 0;
}