//#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define mem(A,i) memset(A, i, sizeof(A))
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define S second
#define F first
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define newLine printf("\n")
int n,m;
string S[1001];
bool visited[1001][1001];

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
bool valid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}
void touch(int r, int c){
    if(valid(r,c) && visited[r][c]==false){
        visited[r][c]=true;
        if(S[r][c]=='E') touch(r,c+1);
        if(S[r][c]=='W') touch(r,c-1);
        if(S[r][c]=='S') touch(r+1,c);
        if(S[r][c]=='N') touch(r-1,c);
        if(valid(r,c+1) && S[r][c+1]=='W') touch(r,c+1);
        if(valid(r,c-1) && S[r][c-1]=='E') touch(r,c-1);
        if(valid(r-1,c) && S[r-1][c]=='S') touch(r-1,c);
        if(valid(r+1,c) && S[r+1][c]=='N') touch(r+1,c);
    }
}
void solve(){
    reset();
    //solve the problem. You can and you will :) give your best shot..
    si(n); si(m);
    rep(i,0,n) cin >> S[i];
    int ans=0;
    rep(i,0,n) rep(j,0,m){
        if(visited[i][j]==false){
            ans++;
            touch(i,j);
            // rep(k,0,n) {
            //     rep(p,0,m) cout << visited[k][p];
            //     cout << endl;
            // }
            // cout << endl;
        }


    }
    pin(ans);
}

int main(){
    int t=1; //si(t);
    while(t--){
        solve();
    }
    return 0;
}