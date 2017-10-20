//MANISH KUMAR
//IIT ROORKEE E&C
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
int n,m,xm,ym,xc1,yc1,xc2,yc2;
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    si2(xm,ym);si2(xc1,yc1);si2(xc2,yc2);
    //visualize grid by uncommenting below lines
    //^ is a cat while * is a mouse
    // rep(i,1,n+1){
    //     rep(j,1,m+1){
    //         if(i==xm && j==ym) printf("*");
    //         else if(i==xc1 && j==yc1) printf("^");
    //         else if(i==xc2 && j==yc2) printf("^");
    //         else printf(".");
    //     }
    //     newLine;
    // }
    int md,cd1,cd2,cd;
    rep(i,1,m+1){
        md = abs(1-xm)+abs(i-ym);
        cd1=abs(1-xc1)+abs(i-yc1);
        cd2=abs(1-xc2)+abs(i-yc2);
        if(md<cd1 && md<cd2){
            printf("YES\n");
            return;
        }
        md = abs(n-xm)+abs(i-ym);
        cd1=abs(n-xc1)+abs(i-yc1);
        cd2=abs(n-xc2)+abs(i-yc2);
        if(md<cd1 && md<cd2){
            printf("YES\n");
            return;
        }
    }

    rep(i,1,n+1){
        md = abs(i-xm)+abs(1-ym);
        cd1=abs(i-xc1)+abs(1-yc1);
        cd2=abs(i-xc2)+abs(1-yc2);
        if(md<cd1 && md<cd2){
            printf("YES\n");
            return;
        }
        md = abs(i-xm)+abs(m-ym);
        cd1=abs(i-xc1)+abs(m-yc1);
        cd1=abs(i-xc2)+abs(m-yc2);
        if(md<cd1 && md<cd2){
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
    return;

    
}

int main(){
    si2(n,m);
    int t=1; si(t);
    while(t--){
        solve();
    }
    return 0;
}