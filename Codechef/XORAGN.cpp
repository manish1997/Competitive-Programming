
#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define MAX 1000005
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


void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;
    ll ans=0;
    cin>>n;
    rep(i,0,n){
    	ll x;cin>>x;
    	x*=2LL;
    	ans^=x;
    }
    tr1(ans);
    
}

int main(){
    fast_cin;
    int t=1; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}