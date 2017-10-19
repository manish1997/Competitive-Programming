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
#define INF 1e7
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
int n,m;
int arr[101][101];
int dp[101][101];
bool valid(int i, int j){
    return (i<=n && j<=m && i>=1 && j>=1);
}
int dx[4],dy[4];
void makezero(int x, int y){
    dp[x][y]=0;
    rep(i,0,4)
        if(valid(x+dx[i], y+dy[i]) && 
            dp[x+dx[i]][y+dy[i]]!=0 && 
            arr[x+dx[i]][y+dy[i]]>=arr[x][y])
            makezero(x+dx[i],y+dy[i]);
}

bool vis[102][102];
bool vis2[102][102];
vector<pair<int,int> > V;
int findmin(int x, int y){
    if(dp[x][y]==0) return arr[x][y];
    V.pb({x,y});
    vis[x][y]=true;
    dp[x][y]=2;
    int ans=INF;
    rep(i,0,4){
        int xx=x+dx[i], yy=y+dy[i];
        if(vis[xx][yy]==false){
            ans=min(ans, findmin(xx,yy));
        }
    }
    return ans;
}
bool enclosed(int x, int y, int z){
    if(valid(x,y)==true && arr[x][y]>z) return true;
    if(valid(x,y)==false || dp[x][y]==0) return false;
    if(arr[x][y]>z) return true;
    vis2[x][y]=true;
    rep(i,0,4){
        int xx=x+dx[i],yy=y+dy[i];
        if(vis2[xx][yy]) continue;
        if(enclosed(xx,yy,z)==false) return false;
    }
    return true;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    si2(n,m);
    mem(dp,-1);
    mem(vis,false);
    rep(i,1,n+1) rep(j,1,m+1) si(arr[i][j]);

    rep(i,1,n+1)rep(j,1,m+1){
        if(dp[i][j]==-1){
            mem(vis2,false);
            if(enclosed(i,j, arr[i][j])==false){
                dp[i][j]=0;
            }
        }
    }

    int ans=0;
    rep(i,1,n+1)rep(j,1,m+1){
        if(dp[i][j]!=-1) continue;
        V.clear();
        int minn=findmin(i,j);
        rep(k,0,V.size()){
            ans+=(minn-arr[V[k].f][V[k].s]);
        }
    }
    pin(ans);
}

int main(){
    dx[0]=1;dy[0]=0;
    dx[1]=-1;dy[0]=0;
    dx[2]=0;dy[2]=1;
    dx[3]=0;dy[3]=-1;
    int t=1; si(t);
    while(t--){
        solve();
    }
    return 0;
}