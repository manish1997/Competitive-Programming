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
#define MAX 100015
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
ll BIT[2][MAX];
vector<int> adj[MAX];
int m;
void update(int idx, ll val, int i){
    while(idx<=(m+10)){
        BIT[i][idx]+=val;
        idx+=(idx&-idx);
    }
}
ll query(int idx, int i){
    ll ans=0;
    while(idx>0){
        ans+=BIT[i][idx];
        idx-=(idx&-idx);
    }
    return ans;
}
int tt;
int dfsorder[MAX];
int subtree[MAX];
int level[MAX];
void dfs(int node, int l){
    subtree[node]=1;
    level[node]=l;
    dfsorder[node]=tt++;
    rep(i,0,adj[node].size()) {
        dfs(adj[node][i],l+1);
        subtree[node]+=subtree[adj[node][i]];
    }
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    mem(BIT,0);
    rep(h,0,2) rep(i,0,m+10) BIT[h][i]=0;
    rep(i,0,m+10) adj[i].clear();
    si(m);
    // int t=0;
    pair<int,ll> queries[m+2];
    int type,val;
    int c=2;
    rep(i,0,m){
        si2(type,val);
        val++;
        queries[i]={type,val};
        if(!type){
             adj[val].pb(c++);
             queries[i]={type,c-1};
        }
    }
    tt=1;
    dfs(1,0);
    c--;
    rep(i,1,c+1) update(dfsorder[i],1LL,level[i]%2);
    repDown(i,m-1,0){
        if(queries[i].f==0){
            int node=dfsorder[queries[i].s];
            update(node,-1LL,level[queries[i].s]%2);
        }
        else{
            int node=queries[i].s;
            ll ans=0;
            rep(h,0,2) {
                ll val1=query(dfsorder[node]+subtree[node]-1, h)-query(dfsorder[node]-1, h);
                ans+=((val1*(val1-1))/2);
            }
            queries[i].s=ans;
        }
    }
    rep(i,0,m) if(queries[i].f==1) plln(queries[i].s);
}

int main(){
    int t=1; si(t);
    while(t--){
        solve();
    }
    return 0;
}