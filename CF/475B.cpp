// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
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
int n,m;
bool visited[22][22];
vector<pair<int,int> > adj[22][22];

bool valid(int i, int j){
    return (i>=1 && i<=n && j>=1 && j<=m);
}
void bfs(int x, int y){
    visited[x][y]=true;
    rep(i,0,adj[x][y].size()){
        if(visited[adj[x][y][i].f][adj[x][y][i].s]==false){
            bfs(adj[x][y][i].f,adj[x][y][i].s);
        }
    }
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    si2(n,m);
    string s; cin >> s;
    rep(i,0,s.length()){
        if(s[i]=='>'){
            rep(j,0,m-1){
                adj[i][j].push_back({i,j+1});
            }
        }
        else{
            repDown(j,m-1,1) {
                adj[i][j].pb({i,j-1});
            }
        }
    }
    cin >> s;
    rep(j,0,s.length()){
        if(s[j]=='v'){
            rep(i,0,n-1){
                adj[i][j].pb({i+1,j});
            }
        }
        else{
            repDown(i,n-1,1){
                adj[i][j].pb({i-1,j});
            }
        }
    }
    // rep(i,0,n)rep(j,0,m){
    //     cout << "i & j " << i << " " << j << endl;
    //     rep(k,0,adj[i][j].size()) cout << adj[i][j][k].f << " " << adj[i][j][k].s << endl;

    // }

    rep(i,0,n){
        rep(j,0,m){
            mem(visited,false);
            bfs(i,j);
            rep(k,0,n){
                rep(l,0,m){
                    if(visited[k][l]==false){
                        printf("NO\n");
                        return;
                    }
                }
            }

        }
    }
    printf("YES\n");
    return;

}
 
int main(){
    // cout << 70*(log2(1e5)+1) <<endl;
    int t=1; //si(t);
    while(t--){
        solve();
    }
    return 0;
} 
