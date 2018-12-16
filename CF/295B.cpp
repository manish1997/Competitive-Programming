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
#define MAX 502
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);


ll dist[MAX][MAX];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n;
    cin>>n;
    ll temp[n+1][n+1];
    rep(i,1,n+1){
        rep(j,1,n+1){
            cin>>temp[i][j];
        }
    }
    map<ll,ll> M;
    map<ll,ll> rev;
    rep(i,0,n){
        ll x;cin>>x;
        M[n-i]=x;
        rev[x]=n-i;
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            dist[i][j]=temp[M[i]][M[j]];
        }
    }

    vector<ll> ans;
    for(ll k=1; k<=n; k++){
        ll sum=0;
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=n; j++){
                dist[i][j]=min(dist[i][j], 
                                dist[i][k]+dist[k][j]);
                if(i<=k && j<=k){
                    sum+=dist[i][j];
                }
            }
        }
        ans.pb(sum);
        
    }
    repDown(i,ans.size()-1,0){
        cout << ans[i] << " ";
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