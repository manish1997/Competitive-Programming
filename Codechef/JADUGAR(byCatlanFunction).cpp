#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define mod 1000000007
#define MAX 10000005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
ll Bpows[MAX];
ll Apows[MAX];
ll Kpows[MAX];
ll fact[MAX];
ll invfact[MAX];
ll inv[MAX];
ll ans[MAX];

ll expo(ll x, ll n, ll m){
    if(n==0) return 1;
    ll temp=expo(x,n/2,m);
    temp = ((temp%m)*(temp%m))%m;
    if(n%2!=0) temp = ((temp%m)*(x%m))%m;
    return temp;
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll N,K,A,B;
    cin>>N>>K>>A>>B;
    Bpows[0]=Apows[0]=1;
    Kpows[0]=1;
    fact[0]=1;
    rep(i,1,MAX){
    	Bpows[i]=(Bpows[i-1]*B)%mod;
    	Kpows[i]=(Kpows[i-1]*K)%mod;
    	Apows[i]=(Apows[i-1]*A)%mod;
    	fact[i]=(fact[i-1]*i)%mod;	
    }
    invfact[MAX-1]=expo(fact[MAX-1], mod-2, mod);
    ll temp=invfact[MAX-1];
    inv[MAX-1]=(fact[MAX-2]*temp)%mod;
    temp=(temp*(MAX-1))%mod;

    repDown(i,MAX-2,0){
    	invfact[i]=(invfact[i+1]*(i+1LL))%mod;
    	inv[i]=(fact[i-1]*temp)%mod;
    	temp=(temp*i)%mod;
    }
    dp[1]=K;
    





}

int main(){
    fast_cin;
    int t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}