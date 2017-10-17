//NOT CORRECT.. WORKING ON THIS
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
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define newLine printf("\n")
#define pb push_back
#define sieveMax 10000001 //maximum for which u need primality test

//Sieve Start
vector<int> Prime;
void sieve(){
    bool neverMakeThisName[sieveMax];
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
int n; 
int B[55];
ll ans=0;
pair<ll,ll> dp[52][52][2501];
void helper(){

    for(int i=0; i<=B[1]; i++){
        dp[1][i][i]={1,1};
    }
    for(int i=2; i<=n; i++){
        for(int curr=0; curr<=B[i]; curr++){
            for(int GCD=0; GCD<=50; GCD++){
                for(int SUM=0; SUM<=2500; SUM++){

                    if(dp[i-1][GCD][SUM].f || dp[i-1][GCD][SUM].s){

                        if(GCD==0){
                            dp[i][GCD][SUM]={1,1};
                            if(i==n) add(ans,dp[i][GCD][SUM].f);
                            continue;
                        }

                        int good=dp[i-1][GCD][SUM].f;
                        int total=dp[i-1][GCD][SUM].s;

                        int sum=SUM+curr;

                        int gc=gcd(GCD,curr);

                        int tm=sum/gc;
                        if((tm&(tm-1))==0){
                            add(dp[i][gc][sum].f,total);
                            add(dp[i][gc][sum].s,total);
                        }
                        else{
                            add(dp[i][gc][sum].s,total);
                        }
                        // if(i==n) add(ans,dp[i][gc][sum].f);
                    }
                }
            }

        }

    }

}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    si(n);
    rep(i,1,1+n) si(B[i]);
    helper();
    cout << ans << endl;
}

int main(){
    int t=1; //si(t);
    while(t--){
        solve();
    }
    return 0;
}