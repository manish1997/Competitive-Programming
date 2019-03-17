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
#define MAX 100005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n,m;
    cin>>n>>m;
    int diag = n+m-1;
    vector<vector<int> > diag1(n+m-1, vector<int>());
    vector<vector<int> > diag2(n+m-1, vector<int>());

    rep(i,0,n){
        rep(j,0,m){
            int x;cin>>x;
            diag1[i+j].pb(x);
        }
    }

    rep(i,0,n){
        rep(j,0,m){
            int x;cin>>x;
            diag2[i+j].pb(x);
        }
    }

    rep(i,0,n+m-1){
        sort(diag1[i].begin(),diag1[i].end());
        sort(diag2[i].begin(),diag2[i].end());
    }

    rep(i,0,n+m-1){
        if(diag1[i]!=diag2[i]){
            cout <<"NO";
            return;
        }
    }
    
    cout<<"YES";
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