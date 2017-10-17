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
char s[1000002];
int n;
int SEG[4*1000002][2];

void build(int node, int start, int end){
    if(start==end){
        if(s[start]=='(') SEG[node][0]=1;
        else SEG[node][1]=1;
    }
    else{
        int mid=(start+end)>>1;
        build(node<<1, start, mid);
        build(1+(node<<1), mid+1, end);
        int ropen=SEG[1+(node<<1)][0];
        int rclose=SEG[1+(node<<1)][1];
        int lopen=SEG[node<<1][0];
        int lclose=SEG[node<<1][1];

        SEG[node][0]=ropen+lopen-min(lopen,rclose);
        SEG[node][1]=lclose+rclose-min(rclose,lopen);
    }
}
pair<int,int> query(int node, int start, int end, int l, int r){
    if(start>end || l>end || r<start) return {0,0};
    if(l<=start && r>=end){
        return {SEG[node][0],SEG[node][1]};
    }
    int mid=(start+end)>>1;
    if(l>mid) return query(1+(node<<1),mid+1, end, l, r);
    else if(r<=mid) return query(node<<1, start, mid, l, r);

    pair<int,int> arr1=query(node<<1, start, mid, l, r);
    int lopen,lclose,ldone;
    int ropen,rclose,rdone;
    pair<int,int> arr2=query(1+(node<<1), mid+1, end, l, r);
    lopen=arr1.f;
    lclose=arr1.s;
    ropen=arr2.f;
    rclose=arr2.s;
    int open=ropen+lopen-min(lopen,rclose);
    int close=lclose+rclose-min(lopen,rclose);
    return {open,close};
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    scanf("%s",s);
    n=strlen(s);
    build(1,0,n-1);
    int t; si(t);
    while(t--){
        int a,b;
        si2(a,b);
        a--;b--;
        pair<int,int> T=query(1,0,n-1,a,b);
        pin(b-a+1-T.f-T.s);// << endl;
    }


    
}

int main(){
    int t=1; //si(t);
    while(t--){
        solve();
    }
    return 0;
}