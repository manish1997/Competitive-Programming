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
bool check;
vector<int> find(int a){
    vector<int> V;
    while(a!=1){
        V.pb(a);
        a/=2;
    }
    V.pb(1);
    return V;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    string s;
    cin >> s;
    if(s=="Qi"){
        check=!check;
        return;
    }
    int a,b;
    si2(a,b);
    // cout << a <<  " " << b << endl;
    vector<int> A=find(a);
    vector<int> B=find(b);
    int i=A.size()-1,j=B.size()-1;


    while(i>=0 && j>=0 && A[i]==B[j]){
        // cout << i << " " << j << " " << A[i] << " " << B[j] << endl;
        i--;
        j--;
    }
    int parent;
    if(i<0) parent=A[0];
    else if(j<0) parent=B[0];
    else parent=B[j+1];


    int plevel=log2(parent);

    int alevel=log2(a);

    int blevel=log2(b);

    int total=alevel-plevel+blevel-plevel+1;

    int red=0;

    
    red+=((alevel-plevel+1)/2);
    if(((plevel%2)==(alevel%2)) && (plevel%2)){
        red+=1;
    }

    
    red+=((blevel-plevel+1)/2);
    if(((plevel%2)==(blevel%2)) && (plevel%2)){
        red+=1;
    }

    if(plevel%2) red--;

    if(s=="Qr"){
        if(check) printf("%d\n", red);
        else printf("%d\n", total-red);
    }
    else{
        if(check) printf("%d\n", total-red);
        else printf("%d\n", red);
    }
}

int main(){
    int t=1; si(t);
    check=true;
    while(t--){
        solve();
    }
    return 0;
}