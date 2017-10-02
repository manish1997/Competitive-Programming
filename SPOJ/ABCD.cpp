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
#define P pair<int,int>
#define PP pair<P,int>
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
char s[100005];
int n;
P helper(int a, int b){
    int arr[4]; mem(arr,0);
    arr[a]=arr[b]=1;
    P p={-1,-1};
    rep(i,0,4) {
        if(arr[i]) continue;
        if(p.f==-1) p.f=i;
        else p.s=i;
    }
    return p;
}
void solve(){
    // reset();
    //solve the problem. You can and you will :) give your best shot..
    si(n);
    scanf("%s",s);
    int len=2*n;
    char a,b='q';
    for(int i=0; i<len; i+=2){
        P temp=helper(s[i]-'A', s[i+1]-'A');
        if(b!=(temp.f+'A')){
            a='A'+temp.f;
            b='A'+temp.s;
        }
        else{
            a=temp.s+'A';
            b=temp.f+'A';
        }
        printf("%c%c",a,b);
    }

}

int main(){
    int t=1;// si(t);
    while(t--){
        solve();
    }
    return 0;
}