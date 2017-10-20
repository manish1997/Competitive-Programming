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
#define rep(i, start, end2) for(int i=start; i<end2; i++)
#define repDown(i, start, end2) for(int i=start; i>=end2; i--)
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
int n;
int end2[26];
int start[26];
int same[26];
string s[100002];
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    si(n);
    rep(i,0,n){
        s[i]=inputString();
        if(s[i][0]==s[i][s[i].length()-1]){
            same[s[i][0]-'a']++;
        }
        else{
            end2[s[i][s[i].length()-1]-'a']++;
            start[s[i][0]-'a']++;
        }
    }
    int even=0,odd=0,deg;
    char e;
    rep(i,0,n){
        deg=0;
        if(s[i][0]==s[i][s[i].length()-1]){
            e=s[i][0];
            deg+=start[e-'a'];
            deg+=end2[e-'a'];
        }
        else{
            e=s[i][s[i].length()-1];
            deg+=start[e-'a']+same[e-'a'];
            e=s[i][0];
            deg+=end2[e-'a']+same[e-'a'];
        }
        cout << s[i] << " " << deg << endl;
        if(deg==0){
            printf("NO\n");
            return;
        }
        if(deg%2) odd++;
        else even++;

    }
    // cout << even << endl;
    if(odd==2 || odd==0) printf("YES\n");
    else printf("NO\n");

    
}

int main(){
    int t=1; si(t);
    while(t--){
        solve();
    }
    return 0;
}