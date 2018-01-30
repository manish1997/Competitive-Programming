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
vector<vector<ll> > V;

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;cin>>n;
    V.resize(n);
    rep(i,0,n)V[i].resize(n);
    rep(i,0,n){
        rep(j,0,n){
            cin>>V[i][j];
        }
        sort(V[i].begin(),V[i].end());
    }
    ll maxx=V[n-1][n-1];
    ll ans=maxx;
    int last=n-1;
    repDown(i,n-2,0){
        int j=n-1;
        while(j>=0 && V[i][j]>=maxx){
            j--;
        }
        if(j==-1){
            cout << -1 << endl;
            return;
        }
        maxx=V[i][j];
        ans+=maxx;
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