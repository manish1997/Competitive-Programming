// #include <bits/stdc++.h>
//Working on this.
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
int dp[100002][202];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    string s1,s2;
    cin >> s1 >> s2;
    int n=s1.length();
    int m=s2.length();
    int a,b,k;
    cin >> a >> b >> k;
    if(a==0){
        pin(0);
        return;
    }

    rep(i,0,202) V[0][i]=i*a;
    rep(i,0,n+1) V[i][0]=i*a;
    for(int i=1; i<=n; i++){
        for(int j=min(i+k,m); j>=i-k && j>=0; j--){
            //i-(j)
            if(s1[i-1]==s2[j-1]){
                V[i][j-i+k]=V[i-1][j-i+k];
            }
            else{
                V[i][j-i+k]=V[i-1][j-i+k]+b;
                V[i][j-i+k]=min(V[i][j-i+k], V[i-1][j-i+k+1]+a);
                V[i][j]=min(V[i][j],V[i][j-i+k]+a);
            }
        }
    }
    cout << V[n][m] << endl;

    
}

int main(){
    int t=1; si(t);
    while(t--){
        solve();
    }
    return 0;
}