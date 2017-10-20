//MANISH KUMAR
//IIT ROORKEE E&C
// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <set>
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
    while((temp<'A'||temp>'Z') && temp!='.')
        temp=getchar();
    while((temp>='A'&&temp<='Z') || temp=='.' )
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
string s[102];
string found="ALLIZZWELL";
int dx[3] = {1,0,-1};
int dy[3] = {1,0,-1};
bool valid(int x, int y){
    return (x<n && y<m && x>=0 && y>=0);
}

set<pair<int,int> > S;
bool helper(int x, int y, int start){
    if(start==found.length()-1 && s[x][y]==found[start]) return true;
    if(s[x][y]!=found[start]) return false;
    S.insert({x,y});
    rep(i,0,3){
        rep(j,0,3){
            if(i==1 && j==1) continue;
            int xx=x+dx[i];
            int yy=y+dy[j];
            if(valid(xx,yy) && 
                S.count({xx,yy})==0 && 
                s[xx][yy]==found[start+1]){
                if(helper(xx,yy,start+1)) return true;
            }
        }
    }
    S.erase({x,y});
    return false;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    si2(n,m);
    rep(i,0,n) cin >> s[i];
    rep(i,0,n) rep(j,0,m){
        S.clear();
        if(helper(i,j,0)) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
    return;
}

int main(){
    int t=1; si(t);
    while(t--){
        solve();
    }
    return 0;
}