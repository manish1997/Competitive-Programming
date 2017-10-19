// #include <bits/stdc++.h>
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
int n;
ll arr[100002];
ll ptr1,ptr2;
ll ans;

void solve(){
    //solve the problem. You can and you will :) give your best shot..

    rep(i,1,n+1) sll(arr[i]);
    ans=0;
    ptr1=ptr2=0;
    rep(i,1,n+1){
        ptr1=max(ptr1,i);
        ptr2=max(ptr2,i);
        if(arr[i]>0){
            while(ptr1<=n){
                if(arr[ptr1]>0) {
                    ptr1++;
                    continue;
                }
                if(-1*arr[ptr1]>arr[i]){
                    arr[ptr1]+=arr[i];
                    ans+=(arr[i]*(ptr1-i));
                    break;
                }
                else{
                    ans+=(-1*arr[ptr1]*(ptr1-i));
                    arr[i]+=arr[ptr1];
                    arr[ptr1]=0;
                }
                ptr1++;
            }
        }
        else if(arr[i]<0){
            if(ptr1>i) continue;
            while(ptr2<=n){
                if(arr[ptr2]<0){
                    ptr2++;
                    continue;
                }
                if(arr[ptr2]>(-1*arr[i])){
                    arr[ptr2]+=arr[i];
                    ans+=(-1*arr[i]*(ptr2-i));
                    break;
                }
                else{
                    ans+=(arr[ptr2]*(ptr2-i));
                    arr[i]+=arr[ptr2];
                    arr[ptr2]=0;
                }
                ptr2++;
            }
        }
    }
    plln(ans);
}

int main(){
    while(true){
        si(n);
        if(n==0)break;
        solve();
    }
    return 0;
}