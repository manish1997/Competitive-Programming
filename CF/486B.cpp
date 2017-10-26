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
int n,m;
int arr[105][105];
int ans[104][103];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    si2(n,m);

    int A[105];
    int B[105];
    mem(A,1);
    mem(B,1);

    rep(i,0,n)
        rep(j,0,m){
            si(arr[i][j]);
            if(arr[i][j]==0){
                A[i]=0;
                B[j]=0;
            }
        }

    rep(i,0,n) rep(j,0,m) ans[i][j]=1;
    rep(i,0,n){
        rep(j,0,m){
            if(A[i]==0 || B[j]==0) ans[i][j]=0;
        }
    }

    mem(A,0);
    mem(B,0);

    rep(i,0,n){
        rep(j,0,m){
            if(ans[i][j]==1) {
                A[i]=1;
                B[j]=1;
            }
        }
    }
    bool ans2=true;
    rep(i,0,n) rep(j,0,m){
        if(arr[i][j]){
            if(A[i]==0 && B[j]==0) {
                ans2=false;
                break;
            }
        }
    }

    if(!ans2) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    rep(i,0,n) {
        rep(j,0,m){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}

int main(){
    int t=1; //si(t);
    while(t--){
        solve();
    }
    return 0;
}