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

#define segMax 100000000 //till point you want to find Primes. Preferebly pow(10,x)
#define rootSegMax 46350 //root of segMax
bool prime[rootSegMax];
vector<ll> Prime; //contains prime numbers uptop segMax
void segmentedSieve(){
    for(ll i = 3; i*i <= rootSegMax; i+=2){
        if(prime[i]==false) {
            for(ll j = i*i; j < rootSegMax; j += i){
                prime[j] = true;
            }
        }
    }
    Prime.pb(2LL);
    for(ll i = 3; i < rootSegMax; i+=2){
        if(prime[i]==false) {
            Prime.push_back(i);
        }
    }
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

long long add(long long &x, long long y){
        x=x+y;
        x%=mod;
        if(x<0) x+=mod;
        return x;
}
bool pr(int x){
    int rt=sqrt(x);
    for(int i=0; i<=Prime.size() && Prime[i]<=rt; i++){
        if(x%Prime[i]==0) return false;
    }
    return true;
}


bool arr[1000001];
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n,m;
    sll2(m,n);

    rep(i,0,min(n-m+1,1000001LL)) arr[i]=false;

    for(ll i=0; i<Prime.size() && Prime[i]*Prime[i]<=n; i++){
        ll st=ceil(((1.0*m)/Prime[i]))*Prime[i];
        for(ll j=st; j<=n; j+=Prime[i]) if(j!=Prime[i]) arr[j-m]=true;
    }

    rep(i,m,n+1){
        if(i==1) continue;
        if(i==2 || i==3){
            printf("%lld\n", i);
            continue;
        }
        if(arr[i-m]==false){
            printf("%lld\n",i);
        }
    }
}

int main(){
    int t=1; si(t);
    segmentedSieve();
    // rep(i,0,Prime.size()) printf("%lld ", Prime[i]);
    while(t--){
        solve();
    }
    return 0;
}