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


void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll l,r,x,y;
    cin>>l>>r>>x>>y;
    //lcm should be y
    map<pair<ll,ll>, bool> M;
    vector<ll> pos;
    ll root=sqrt(y);
    for(ll i=1; i<=root; i++){
        if(y%i==0){
            if(i>=l && i<=r) pos.pb(i);
            if((i*i)!=y){
                if(y>=l*i && y<=r*i) pos.pb(y/i);
            }
        }
    }
    ll ans=0;
    rep(i,0,pos.size()){
        rep(j,0,pos.size()){
            ll GCD=gcd(pos[i], pos[j]);
            if(GCD==x && ((pos[i]*pos[j])/GCD)==y){
                ans++;
            }
        }
    }
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