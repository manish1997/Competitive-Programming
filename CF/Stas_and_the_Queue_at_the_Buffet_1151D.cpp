#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define MAX 100005
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
    vector<pair<ll,ll> > V;
    ll ans = 0;
    
    rep(i,0,n){
    	ll a,b;cin>>a>>b;
    	ans+=(n*b-a);
    	V.pb({a-b,i});
    }
    sort(V.begin(), V.end());
    for(ll i=0; i<n; i++){
    	ans+=(V[i].first*(n-i));
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