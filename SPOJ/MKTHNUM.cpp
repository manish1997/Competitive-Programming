//#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <map>
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
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define logM 20
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
int n,m;
int arr[MAX];
int SEG[24*MAX]; //[4*MAX+MAX*logM]
int RM[MAX];
int nodes=0;
int left2[24*MAX];
int right2[24*MAX];
int head[MAX];
int newleaf(int value){
    int p=++nodes;
    SEG[p]=value;
    left2[p]=0;
    right2[p]=0;
    return p;
}
int newparent(int l, int r){
    int p=++nodes;
    SEG[p]=SEG[l]+SEG[r];
    left2[p]=l;
    right2[p]=r;
    return p;
}

int build(int start, int end){
    if(start==end){
        return newleaf(0);
    }
    else{
        int mid=(start+end)>>1;
        return newparent(build(start,mid), build(mid+1, end));
    }
}
int query(int r1, int r2, int k, int l, int r){
    if(l==r) return l;
    int mid=(l+r)>>1;
    int cn=SEG[left2[r1]]-SEG[left2[r2]];
    if(cn>=k){
        return query(left2[r1], left2[r2], k, l, mid);
    }
    else{
        return query(right2[r1], right2[r2], k-cn, mid+1, r);
    }
}

int update(int node, int start, int end, int idx, int val){
    if(start == end){
        return newleaf(SEG[node]+val);
    }
    else{
        int mid=(start+end)>>1;
        if(idx<=mid) 
            return 
                newparent(update(left2[node], start, mid, idx, val), right2[node]);
        else return
            newparent(left2[node], update(right2[node], mid+1, end, idx, val));

    }
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    si2(n,m);
    map<int,int> M;
    rep(i,1,n+1) {
        si(arr[i]);
        M[arr[i]];
    }
    int cnt=0;
    for(auto it=M.begin(); it!=M.end(); it++){
        it->second=cnt++;
        RM[it->second]=it->first;
    }
    head[0]=build(0,n-1);
    rep(i,1,n+1) head[i]=update(head[i-1], 0, n-1, M[arr[i]], 1);
    rep(i,0,m){
        int a,b,k;
        si3(a,b,k);
        int ans=query(head[b], head[a-1], k, 0, n-1);
        pin(RM[ans]);
    }
}

int main(){
    int t=1; //si(t);
    // pin(16*MAX*logM);
    nodes=0;
    while(t--){
        solve();
    }
    return 0;
}