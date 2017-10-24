#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <unordered_map>
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
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define P pair<int,int>
#define PP pair<P,int>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define newLine printf("\n")
#define pb push_back
#define sieveMax 100005 //maximum for which u need primality test

//Sieve Start
vector<int> Prime;

bool neverMakeThisName[sieveMax];
// mem(neverMakeThisName,false);
void sieve(){
    neverMakeThisName[0]=neverMakeThisName[1]=true;
    for(int i=2; i<=sqrt(sieveMax); i++){
        if(neverMakeThisName[i]==false){
            for(int j=i*i; j<sieveMax; j+=i) neverMakeThisName[j]=true;
        }
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
int arr[20005];
unordered_map<int,priority_queue<int> > mapp;

void eliminate(int x){
    int temp=x;
    int i=0;
    while(i<Prime.size() && Prime[i]*Prime[i]<=x){
        int xx=0;
        while(temp%Prime[i]==0){
            xx++;
            temp/=Prime[i];
        }
        if(xx) mapp[Prime[i]].push(xx);
        i++;
    }
    if(temp>1){
        mapp[temp].push(1);             
    }
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;
    si(n);
    mapp.clear();
    rep(i,0,n) {
        si(arr[i]);
        eliminate(arr[i]);
    }
    ll ans=1;
    for(auto it=mapp.begin(); it!=mapp.end(); it++){
        priority_queue<int> &PQ=it->second;
        while(!PQ.empty() && PQ.size()>1){
            int a=PQ.top();
            PQ.pop();
            int b=PQ.top();
            PQ.pop();
            a--;
            b--;
            if(a>0) PQ.push(a);
            if(b>0) PQ.push(b);
        }
        if(!PQ.empty() && PQ.top()) ans=(ans*expo(it->first, it->second.top(), mod))%mod;
    }
    cout << ans << endl;
}

int main(){
    int t=1; si(t);
    sieve();
    while(t--){
        solve();
    }
    return 0;
}