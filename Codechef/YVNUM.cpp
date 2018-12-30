#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
#define MAX 100005
#define mod 1000000007
ll D[50];
ll mod10[MAX];
ll inv10[MAX];


//Modulus Expo
ll expo(ll x, ll n, ll m){
    if(n==0) return 1;
    ll temp=expo(x,n/2,m);
    temp = ((temp%m)*(temp%m))%m;
    if(n%2!=0) temp = ((temp%m)*(x%m))%m;
    return temp;
}
//end Modulus Expo

void solve(){
    string s;
    cin>>s;
    int n=s.length();
    ll val=0;
    for(int i=0; i<n; i++){
        val = (val*10LL + (s[i]-'0'))%mod;
    }
    ll ans=val;
    for(int i=0; i<n-1; i++){
        val=(val - (((s[i]-'0')*mod10[n-1])%mod) + mod)%mod;
        val = (val*10LL + (s[i]-'0'))%mod;
        ans = (ans * mod10[n])%mod;
        ans = (ans + val)%mod;
    }
    cout << ans << endl;
}
int main(){
    int t=1;
    cin>>t;
    mod10[0]=1;
    inv10[0]=1;
    for(int i=1; i<MAX; i++){
        mod10[i]=(mod10[i-1]*10LL)%mod;
        inv10[i]=expo(mod10[i], mod-2, mod);
    }


    while(t--){
        solve();
    }
    return 0;
}
