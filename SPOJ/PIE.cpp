//#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define mem(A,i) memset(A, i, sizeof(A))
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define S second
#define F first
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define newLine printf("\n")
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
int arr[10005];
double allowed[10005];

double volume(int h){
    return pi*(double)h*h;
}
void reset(){
    //check if your logic is correct but still wrong answer

}
bool check(double vol){
    int i=0;
    int f=0;
    rep(i,0,n) allowed[i]=volume(arr[i]);
    while(i<n){
        double th=allowed[i];
        if(th>=vol){
            allowed[i]-=vol;
            f++;
        }
        else{
            i++;
        }
        if(f>=m) return true;
    }
    if(f<m) return false;
    return true;
}
void solve(){
    reset();
    //solve the problem. You can and you will :) give your best shot..
    si(n); si(m);
    m++;
    rep(i,0,n) si(arr[i]);
    sort(arr,arr+n);
    double maxx=0;
    rep(i,0,n) maxx+=volume(arr[i]);
    maxx/=m;
    maxx=ceil(maxx);
    double minn=0;
    while(abs(minn-maxx)>=0.0001){
        double mid=(minn+maxx)/2;
        if(check(mid)) minn=mid+.0001;
        else maxx=mid-0.0001;
    }
    printf("%.4f\n", minn-.0001);
}

int main(){
    int t; si(t);
    while(t--){
        solve();
    }
    return 0;
}