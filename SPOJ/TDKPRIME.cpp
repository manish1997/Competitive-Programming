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
#define MAX 100005
#define s second
#define f first
#define newLine printf("\n")
#define pb push_back

//Start Segmented Sieve of Eras^%&*sac
vector<int> Prime;
void segmentedSieve(){
    #define segMax 100000000 //till point you want to find Primes
    #define rootSegMax 10000 //root of segMax
    #define maxPrimes 5000000 // define it as INT_MAX if you
    //don't want to add any limit and only wants to find all Primes
    bool neverMakeThisName[rootSegMax];
    mem(neverMakeThisName,true);
    for(int i=2; i*i<=rootSegMax; i++){
        if(neverMakeThisName[i]==true) {
            for(int j=i*i; j<rootSegMax; j+=i){
                neverMakeThisName[j]=false;
            }
        }
    }
    rep(i,2,rootSegMax) {
        if(neverMakeThisName[i]) {
            Prime.pb(i);
        }
    }

    int low=rootSegMax;
    int high=rootSegMax+low;
    int tempMax=Prime.size();

    while(Prime.size() < maxPrimes && low<segMax){
        mem(neverMakeThisName,true);
        rep(i,0,tempMax){
            int st=Prime[i]*ceil(1.0*low/Prime[i]);
            for(int j=st; j<high; j+=Prime[i]){
                neverMakeThisName[j-low]=false;
            }
        }
        rep(i,0,rootSegMax){
            if(Prime.size() < maxPrimes && neverMakeThisName[i]){
                Prime.pb(i+low);
            }
        }
        low+=rootSegMax;
        high+=rootSegMax;
    }
}
//End Segmented Sieve of Eras^%&*sac

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
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int k; si(k);
    pin(Prime[k-1]);
}

int main(){
    int t=1; si(t);
    segmentedSieve();
    while(t--){
        solve();
    }
    return 0;
}