
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
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

ll m,n;
ll A[MAX], B[MAX];
pair<ll,ll> coeffs[MAX];


void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>m>>n;
    ll result=0;
    rep(i,1,m+1){
        cin>>A[i];
        result=(result+(((((m*coeffs[n-1].f)%mod)*A[i])%mod)%mod))%mod;
    }
    rep(i,1,m+1){
        cin>>B[i];
        result=(result+(((((m*coeffs[n-1].s)%mod)*B[i])%mod)%mod))%mod;
    }
    tr1(result);
}

int main(){
    fast_cin;
    int t=1; 
    cin >> t;
    coeffs[0]={1LL,0LL};
    coeffs[1]={0LL,1LL};
    rep(i,2,MAX){
        coeffs[i].f=(coeffs[i-1].f+coeffs[i-2].f)%mod;
        coeffs[i].s=(coeffs[i-1].s+coeffs[i-2].s)%mod;
    }
    while(t--){
        solve();
    }
    return 0;
}