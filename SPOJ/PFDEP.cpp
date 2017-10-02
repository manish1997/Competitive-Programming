//#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define si(n) scanf("%d",&n)
#define si2(n1,n2) scanf("%d%d",&n1,&n2)
#define si3(n1,n2,n3) scanf("%d%d%d",&n,&n2,&n3)
#define sll(n) scanf("%lld",&n)
#define sll2(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll3(n1,n2,n3) scanf("%lld%lld%lld",&n,&n2,&n3)
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
void reset(){
    //check if your logic is correct but still wrong answer

}
int n;
vector<int> adj[102];
int deg[102];

void solve(){
    reset();
    //solve the problem. You can and you will :) give your best shot..
    int m;
    mem(deg,0);
    si2(n,m);
    rep(i,0,m){
        int c; si(c);
        int k; si(k);
        rep(j,0,k){
            int p; si(p);
            adj[p].push_back(c);
            deg[c]++;
        }
    }
    priority_queue<int> PQ;
    rep(i,1,n+1) if(deg[i]==0) PQ.push(-i);
    while(!PQ.empty()){
        int curr=-PQ.top();
        PQ.pop();
        printf("%d ", curr);
        rep(i,0,adj[curr].size()) {
            deg[adj[curr][i]]--;
            if(!deg[adj[curr][i]]) PQ.push(-adj[curr][i]);
        }
    }

}

int main(){
    int t=1;// si(t);
    while(t--){
        solve();
    }
    return 0;
}