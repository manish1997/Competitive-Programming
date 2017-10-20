//MANISH KUMAR
//IIT ROORKEE E&C
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
int n,q;
int SEG[4*100002][3];
int lazy[4*100002];
void belazy(int node, int start, int end){
    if(start>end) return;
    lazy[node]%=3;
    if(lazy[node]){
        if(lazy[node]==1){
            int a=SEG[node][0], b=SEG[node][1], c=SEG[node][2];
            SEG[node][1]=a;
            SEG[node][0]=c;
            SEG[node][2]=b;
            if(start!=end){
                lazy[node<<1]+=1;
                lazy[1+(node<<1)]+=1;
            }
        }
        else{
            int a=SEG[node][0], b=SEG[node][1], c=SEG[node][2];
            SEG[node][1]=c;
            SEG[node][0]=b;
            SEG[node][2]=a;
            if(start!=end){
                lazy[node<<1]+=2;
                lazy[1+(node<<1)]+=2;
            }
        }
    }
    lazy[node]=0;
}
int query(int node, int start, int end, int l, int r){
    belazy(node,start, end);
    if(start>end || l>end || r<start) return 0;
    if(start>=l && end<=r){
        return SEG[node][0];
    }
    int mid=(start+end)>>1;
    if(l>mid) return query((node<<1)+1, mid+1, end, l, r);
    else if(r<=mid) return query(node<<1, start, mid, l, r);
    int L=query(node<<1, start, mid, l, r);
    int R=query(1+(node<<1),mid+1,end, l, r);
    return (R+L);
}
void update(int node, int start, int end, int l, int r){
    belazy(node,start, end);
    if(start>end || end<l || start>r) return;
    if(start>=l && end<=r){
        int a=SEG[node][0], b=SEG[node][1], c=SEG[node][2];
        SEG[node][1]=a;
        SEG[node][0]=c;
        SEG[node][2]=b;
        if(start!=end){
            lazy[node<<1]+=1;
            lazy[1+(node<<1)]+=1;
        }
        return;
    }
    int mid=(start+end)>>1;
    update(node<<1, start, mid, l,r);
    update(1+(node<<1),mid+1,end,l,r);
    SEG[node][0]=SEG[node<<1][0]+SEG[1+(node<<1)][0];
    SEG[node][1]=SEG[node<<1][1]+SEG[1+(node<<1)][1];
    SEG[node][2]=SEG[node<<1][2]+SEG[1+(node<<1)][2];
    return;
}
void build(int node, int start, int end){
    if(start>end) return ;
    if(start==end){
        SEG[node][0]=1;
    }
    else{
        int mid=(start+end)>>1;

        build(node<<1, start, mid);
        build(1+(node<<1),mid+1,end);
        SEG[node][0]=SEG[node<<1][0]+SEG[1+(node<<1)][0];
    }
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    si2(n,q);
    build(1,0,n-1);
    while(q--){
        int type,A,B; si3(type,A,B);
        if(type==1){
            pin(query(1,0,n-1,A,B));
        }
        else{
            update(1,0,n-1,A,B);
        }
    }
    
}

int main(){
    int t=1; //si(t);
    while(t--){
        solve();
    }
    return 0;
}