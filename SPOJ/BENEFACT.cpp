//LONGEST PATH IN A UNDIRECTED TREE
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
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define mem(A,i) memset(A, i, sizeof(A))
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define S second
#define F first
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define newLine printf("\n")
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
int n;
vector<pair<int,int> > adj[50005];
int maxx,far;
void reset(){
    //check if your logic is correct but still wrong answer
    rep(i,0,n+1) adj[i].clear();


}
void dfs(int node, int parent, int cost){
    if(maxx<cost){
        maxx=cost;
        far=node;
    }
    rep(i,0,adj[node].size()){
        if(adj[node][i].first==parent) continue;
        dfs(adj[node][i].first, node, cost+adj[node][i].second);
    }
    return;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    si(n);
    reset();
    rep(i,0,n-1){
        int a,b,c;
        si(a); si(b); si(c);
        a--;b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    far=maxx=0;
    dfs(0,-1,0);
    maxx=0;
    dfs(far,-1,0);
    pin(maxx);
}

int main(){
    int t; si(t);
    while(t--){
        solve();
    }
    return 0;
}