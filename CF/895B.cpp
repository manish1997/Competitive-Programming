// #include <bits/stdc++.h>
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
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define P pair<int,int>
#define PP pair<P,int>
#define mod 1000000007
#define MAX 500005
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
ll n,x,k;
ll arr[100005];
ll BS(ll left, ll right, ll start){
    ll end=n-1;
    ll tem=start;
    while(start<=end){
        ll mid=(start+end)>>1;
        if(arr[mid]>=left) end=mid-1;
        else start=mid+1;
    }
    ll ff=end+1;
    start=tem;
    end=n-1;
    while(start<=end){
        ll mid=(start+end)>>1;
        if(arr[mid]<=right) start=mid+1;
        else end=mid-1;
    }
    ll ss=start-1;
    if(ff>ss) return 0;
    return (ss-ff+1);
}
int check(int a, int b){
    int f=0;
    // cout << a << " " << b << " " << x << endl;
    rep(i,a,b+1) {
        if((i%x)==0) f++;
    }
    // cout << f << endl;
    if(f==k) return 1;
    return 0;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    sll3(n,x,k);
    rep(i,0,n) sll(arr[i]);
    sort(arr,arr+n);
    //find first number >=ai and divisble by x
    //(ai%x)+ai

    ll ans=0;
    rep(i,0,n){
        // cout << arr[i] << " ";

        ll first=(x-(arr[i]%x))+arr[i];
        if(arr[i]%x==0) first=arr[i];
        if(k==0){
            ans+=BS(arr[i], first-1, 0);
        }
        else{
            // cout << first+(k-1)*x << " " << first+(k*x)-1<<endl;
            ans+=BS(first+(k-1)*x, first+(k*x)-1, 0);
        }
    }
    // cout << endl;
    plln(ans);
    // ans=0;
    // rep(i,0,n)
    // rep(j,0,n){
    //     if(arr[i]<=arr[j]) ans+=check(arr[i],arr[j]);
    // }
    // plln(ans);
}
 
int main(){
    int t=1; //si(t);
    while(t--){
        solve();
    }
    return 0;
}    
