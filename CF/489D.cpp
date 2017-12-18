#include <iostream>
#include <cmath>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define si2(n1,n2) scanf("%d%d",&n1,&n2)
#define pin(n) printf("%d\n",n)
#define pis(n) printf("%d ",n)
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(int i=start; i<end; i++)
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

bool check[3002][3002];
vector<int> adj[3002];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n,m;
    si2(n,m);
    rep(i,0,m){
        int a,b; si2(a,b);
        check[a][b]=true;
        adj[a].pb(b);
    }
    int res=0;
    rep(i,1,n+1){
        rep(j,1,n+1){
            //ith node and jth node are fixed now
            int r=0;
            if(i==j) continue;
            rep(k,0,adj[i].size()){
                int l=adj[i][k];
                if(l!=i && l!=j && check[l][j]){
                    r++;
                }
            }
            res+=((r*(r-1))/2);
        }
    }
    pin(res);

}

int main(){
    // cout << 70*(log2(1e5)+1) <<endl;
    int t=1; //si(t);
    while(t--){
        solve();
    }
    return 0;
}