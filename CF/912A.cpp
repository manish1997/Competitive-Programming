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
#define MAX 1000005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    ll n,k;
    cin>>n>>k;
    repDown(i,62,0){
        if((1LL<<i)&n){
            ll ans=0;
            ans=1LL<<i;
            ll curr=1LL;
            for(ll m=i-1; curr<k && m>=0; m--){
                ans+=(1LL<<m);
                curr++;
            }
            cout<<ans<<endl;
            return;
        }
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