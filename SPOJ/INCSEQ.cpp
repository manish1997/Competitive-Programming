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
#define s second
#define f first
#define newLine printf("\n")
#define pb push_back
#define sieveMax 10000001 //maximum for which u need primality test
bool neverMakeThisName[sieveMax];
vector<int> Prime;


void sieve(){
    neverMakeThisName[0]=neverMakeThisName[1]=true;
    for(int i=4; i<sieveMax; i+=2) neverMakeThisName[i]=true;

    for(int i=3; i<=sqrt(sieveMax); i+=2)
        if(neverMakeThisName[i]==false) {
            for(int j=i*i; j<sieveMax; j+=i) neverMakeThisName[j]=true;
        }

    rep(i,0,sieveMax) if(neverMakeThisName[i]==false) Prime.pb(i);
}

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

int add(int &x, int y){
        x=x+y;
        x%=5000000;
        if(x<0) x+=5000000;
        return x;
}

#define MAX 10005
int n,k;
int arr[MAX];
int dp[MAX];
int BIT[52][10*MAX];
int maxx;
void update(int num, int idx, int val){
    while(idx<=maxx) {
        add(BIT[num][idx],val);
        idx+=(idx&-idx);
    }
}
int query(int num, int idx){
    int res=0;
    while(idx>0){
        add(res,BIT[num][idx]);
        idx-=(idx&-idx);
    }
    return res;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    si(n); si(k);
    maxx=-1;
    rep(i,0,n) {
        si(arr[i]);
        arr[i]++;
        dp[i]=1;
        maxx=max(maxx,arr[i]);
    }
    rep(i,2,k+1){
        rep(j,0,n){
            update(i, arr[j],dp[j]);
            dp[j]=query(i, arr[j]-1);
        }
    }
    int ans=0;
    rep(i,0,n) add(ans,dp[i]);
    pin(ans);
}

int main(){
    int t=1;// si(t);
    while(t--){
        solve();
    }
    return 0;
}