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
string s[3];
bool check(char C){
    string toch; rep(i,0,3) toch.pb(C);
    rep(i,0,3) if(s[0]==toch) return true;
    rep(i,0,3){
        string tem="";
        rep(j,0,3) tem.pb(s[j][i]);
        if(tem==toch) return true;
    }
    string temp="";
    rep(i,0,3) temp.pb(s[i][i]);
    if(temp==toch) return true;
    temp.clear();
    rep(i,0,3) temp.pb(s[i][2-i]);
    if(temp==toch) return true;
    return false;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    rep(i,0,3) cin >> s[i];
    int o=0,x=0;
    rep(i,0,3){
        rep(j,0,s[i].length()) if(s[i][j]=='X') x++;
        else if(s[i][j]=='O') o++;
    }
    if(x==o+1){
        //O shouldn;t be in the winning position
        if(check('O')) printf("no\n");
        else printf("yes\n");

    }
    else if(x==o){
        //X shouldn't be in winning position
        if(check('X')) printf("no\n");
        else printf("yes\n");
    }
    else{
        printf("no\n");
    }
}

int main(){
    int t=1; si(t);
    int a[9];
    char dummy;

    while(t--){
        solve();
        if(t!=0)
        scanf("%c",&dummy);
    }
    return 0;
}