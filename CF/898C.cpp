// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
// #define pi 3.1415926535897
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

bool suffix(string a, string b){
    if(a.length()>b.length()) return false;
    int alen=a.length()-1;
    int blen=b.length()-1;
    for(int i=alen; i>=0; i--, blen--) if(a[i]!=b[blen]) return false;
    return true;
}
void solve(){
    map<string,map<string,bool> > M;
    int n; cin >> n;
    rep(qq,0,n){
        string name; cin >> name;
        int k; cin >> k;
        rep(i,0,k){
            string number; cin >> number;
            M[name][number];
        }
    }
    vector<string> anss[M.size()];
    int k=0;
    vector<string> name;
    for(auto it: M){
        map<string,bool> temp=it.second;
        for(auto it2:temp){
            anss[k].push_back(it2.f);
        }
        name.pb(it.f);
        k++;
    }
    cout << M.size() << endl;
    k=0;
    rep(k,0,M.size()){
        cout << name[k] << " ";
        vector<string> curr=anss[k];
        vector<string> tempans;

        for(int i=0; i<curr.size(); i++){
            bool ans=true;
            for(int j=0; j<curr.size(); j++){
                if(j==i) continue;
                if(suffix(curr[i], curr[j])) {
                    ans=false;
                    break;
                }
            }
            if(ans) tempans.pb(curr[i]);
        }
        cout << tempans.size() << " ";
        rep(o,0,tempans.size()) cout << tempans[o] << " ";

        cout << endl;
    }
}

int main(){
    int t=1;
    //si(t);
    while(t--) solve();
    return 0;
}  