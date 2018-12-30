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
    map<ll,bool> M;
    M[(n*(n+1LL))/2];
    M[1];
    vector<ll> F;

    for(ll i=2; i*i<=n; i++){
        if(n%i) continue;
        F.pb(i);
        F.pb(n/i);
    }
    for(int i=0; i<F.size(); i++){
        ll curr=F[i];
        ll a=1;
        ll an=n+1LL;
        ll terms = (n/curr)+1;
        M[(((a+an)*terms)/2LL)-(n+1LL)];
    }
    for(auto it:M){
        cout << it.f << " ";
    }
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