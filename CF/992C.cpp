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
#define MAX (1<<17)+5
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
//GCD
ll gcd(ll a, ll b){
    if ( a==0 ) return b;
    return gcd ( b%a, a );
}
//end GCD

//Modulus Expo
ll expo(ll x, ll n, ll m){
    if(n==0) return 1;
    ll temp=expo(x,n/2LL,m);
    temp = ((temp%m)*(temp%m))%m;
    if(n%2LL!=0) temp = ((temp%m)*(x%m))%m;
    return temp;
}
//end Modulus Expo

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    // int n;cin>>n;
    ll x,k;
    cin>>x>>k;
    if(x==0){
        cout<<0<<endl;
        return;
    }
    
    ll ans=0;
    ll pow2k=expo(2LL, k, mod);
    ans=((x%mod)*pow2k)%mod;
    ans=(ans*2LL)%mod;
    ans=(ans-pow2k+mod)%mod;
    ans=(ans+1LL)%mod;
    cout<<ans<<endl;





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