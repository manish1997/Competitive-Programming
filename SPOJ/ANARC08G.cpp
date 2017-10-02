#include <bits/stdc++.h>
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
int arr[1001][1001];
int k;
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    rep(i,0,n) rep(j,0,n) si(arr[i][j]);
    int ans2=0;
    int ans1=0;
    rep(i,0,n){
        int inflow=0;
        int outflow=0;
        rep(j,0,n) {
            inflow+=arr[i][j];
            outflow+=arr[j][i];
        }
        // if(inflow<outflow) ans2+=(outflow-inflow); 
        //both above and bottom lines will work
        //until unless one is commented ofc :P
        if(inflow>outflow) ans2+=(inflow-outflow);
        ans1+=(inflow+outflow);
    }
    printf("%d. ", k);
    pis(ans1/2);
    pin(ans2);   
}

int main(){
    k=0;
    while(1){
        k++;
        si(n); if(!n) break;
        solve();
    }
    return 0;
}