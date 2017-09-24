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
#define si3(n1,n2,n3) scanf("%d%d%d",&n,&n2.&n3)
#define sll(n) scanf("%lld",&n)
#define sll2(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll3(n1,n2,n3) scanf("%lld%lld%lld",&n,&n2.&n3)
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
int arr[1000005];
void solve(){
    reset();
    //solve the problem. You can and you will :) give your best shot..
    int a,b; si(a); si(b);
    pin(arr[b]-arr[a-1]);
}

int main(){
    int t; si(t);
    bool prime;
    int ans=0;
    for(int i=1; i*i<=1e6; i++){
        ll sum=0;
        int num=i*i;
        rep(j,1,i+1){
            if((num%j)==0){
                sum+=j;
                if(i!=j) sum+=(num/j);
            }
        }
        prime=true;
        rep(j,2,sqrt(sum)+1){
            if((sum%j)==0){
                prime=false;
                break;
            }
        }
        if(prime) arr[num]=1;
    }
    arr[1]=0;
    arr[2]=1;
    rep(i,1,1+1e6) arr[i]+=arr[i-1];

    while(t--){
        solve();
    }
    return 0;
}