#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll unsigned long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 998244353
#define mod2 1000000033
#define MAX 1003
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n;
    cin>>n;

    ll fact[n+1];
    fact[0]=1LL;
    for(ll i=1; i<=n; i++){
        fact[i]=(i*fact[i-1])%mod;
    }
    ll ans=fact[n];
    ll temp=1LL;
    for(ll i=n; i>=1; i--){
        temp=(temp*i)%mod;
        ans=(ans+((fact[n]-temp+mod)%mod))%mod;
    }
    cout << ans << endl;
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