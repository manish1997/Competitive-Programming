//#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <algorithm>
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
ll n,a,b;
ll n_;
ll arr[35];
ll A[2][131082];
// ll a2[131082];
ll cnt[2];
ll ans;
void helper(int num){
    rep(i,0,1<<n_){
        ll sum=0;
        rep(j,0,n_){
            if(i&(1<<j)) sum+=arr[j];
        }
        A[num][cnt[num]++]=sum;
    }
}
ll lower_limit(int start, int end, ll val){
    while(start<=end){
        int mid=(start+end)>>1;
        if(A[1][mid]>=val) end=mid-1;
        else start=mid+1;
    }
    return end+1;
}
ll upper_limit(int start, int end, ll val){
    while(start<=end){
        int mid=(start+end)>>1;
        if(A[1][mid]<=val) start=mid+1;
        else end=mid-1;
    }
    return start-1;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    sll3(n,a,b);
    if(n==1){
        sll(arr[0]);
        int ans=0;
        if(arr[0]<=b && arr[0]>=a) ans+=1;
        if(b>=0 && a<=0) ans+=1;
        pin(ans);
        return;
    }
    rep(i,0,n/2) sll(arr[i]);
    n_=n/2;
    cnt[0]=0;
    helper(0);
    sort(A[0],A[0]+cnt[0]);
    rep(i,n/2,n) sll(arr[i-(n/2)]);
    cnt[1]=0;
    n_=n-n/2;
    helper(1);
    sort(A[1],A[1]+cnt[1]);
    ans=0;
    rep(i,0,cnt[0]) {
        ll curr=A[0][i];
        ll temp1=lower_limit(0,cnt[1]-1, a-curr);
        ll temp2=upper_limit(0,cnt[1]-1, b-curr);
        if(temp1>temp2) continue;
        ans+=(temp2-temp1+1);
    }
    plln(ans);
}

int main(){
    int t=1; //si(t);
    while(t--){
        solve();
    }
    return 0;
}