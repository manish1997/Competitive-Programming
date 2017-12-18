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
int n,s;
string dp1[101][905];

string dp2[101][905];

string findlargest(int rem, int sum){
    if(sum<0) return "no";
    if(rem==0 && sum!=0) return "no";
    if(rem==0) return "yes";

    if(dp1[rem][sum]!="") return dp1[rem][sum];
    int low=0;
    if(rem==n) low=1;
    string ans="";

    for(int i=9; i>=low; i--){
        if(findlargest(rem-1, sum-i)[0]!='n'){
            return dp1[rem][sum]=(to_string(i)+findlargest(rem-1,sum-i));
        }
    }
    return dp1[rem][sum]="no";
}
string findsmall(int rem, int sum){
    if(sum<0) return "no";
    if(rem==0 && sum!=0) return "no";
    if(rem==0) return "yes";

    if(dp2[rem][sum]!="") return dp2[rem][sum];
    int start=0;
    if(rem==n) start=1;
    string ans="";

    for(int i=start; i<=9; i++){

        if(findsmall(rem-1, sum-i)[0]!='n'){
            return dp2[rem][sum]=(to_string(i)+findsmall(rem-1,sum-i));
        }

    }
    return dp2[rem][sum]="no";
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    si2(n,s);
    if(n==1 && s==0){
        printf("0 0\n");
        return;
    }
    if(s==0){
        printf("-1 -1\n");
        return;
    }

    string large=findlargest(n,s);
    if(large[0]=='n'){
        printf("-1 -1\n");
        return;
    }
    rep(i,0,3) large.pop_back();
    // cout << large << endl;
    string small=findsmall(n,s);
    // cout << small << endl;
    rep(i,0,3) small.pop_back();
    cout << small << " " << large << endl;
}

int main(){
    // cout << 70*(log2(1e5)+1) <<endl;
    int t=1; //si(t);
    while(t--){
        solve();
    }
    return 0;
}