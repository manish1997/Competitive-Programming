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
int B[104];
int G[104];
int n,m;
int dp[104][103];

int helper(int b, int g){
    // cout << b << " " << g << endl;
    if(b>n || g>m) return 0;
    if(dp[b][g]!=-1)return dp[b][g];
    int &ans = dp[b][g];
    ans=0;
    int k=g;
    bool possible=true;
    while(k<=m){
        if(abs(G[k]-B[b])<=1){
            break;
        }
        else if((B[b]<G[k])){
            possible=false;
            break;
        }
        k++;
    }
    // cout << "k "<< k << endl;
    if(k==(m+1)){
        ans=0;
        return ans;
    }
    if(possible==false){
        return ans=helper(b+1,g);
    }
    // cout << possible << endl;
    return (ans=1+helper(b+1,k+1));
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    si(n);
    mem(dp,-1);

    rep(i,1,n+1)si(B[i]);
    si(m);
    rep(i,1,m+1) si(G[i]);
    sort(B+1,B+n+1);
    sort(G+1,G+m+1);

    pin(helper(1,1));
 
}

int main(){
    // cout << 70*(log2(1e5)+1) <<endl;
    int t=1; //si(t);
    while(t--){
        solve();
    }
    return 0;
}