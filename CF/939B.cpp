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
ll arr[100004];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n,k;
    cin>>n>>k;
    ll ans=1+1e18;
    ll ind=0;
    rep(i,1,k+1){
        cin>>arr[i];
        if((n%arr[i])<ans){
            ans=n%arr[i];
            ind=i;
        }
    }
    cout << ind << " " << (n/arr[ind]) << endl;
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