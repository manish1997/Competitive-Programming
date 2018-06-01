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
#define MAX 105
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

ll N, K, x1, Y1, C, D, E1, E2, F;

ll X[MAX];
ll Y[MAX];
ll A[MAX];
vector<vector<ll> > subarrays;
ll pown[105][25];

ll power(ll x){
    ll ans=0;
    rep(i,0,subarrays.size()){
        vector<ll> curr=subarrays[i];
        rep(j,0,curr.size()){
            ans+=(curr[j]*(pown[j+1][x]))%mod;
        }
    }
    return ans;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>N>> K>> x1>> Y1>> C>> D>> E1>> E2>> F;
    X[1]=x1;
    Y[1]=Y1;
    A[1]=(x1+Y1)%F;
    subarrays.clear();

    rep(i,2,N+1){
        X[i]=((C*X[i-1])+(D*Y[i-1])+E1)%F;
        Y[i]=((D*X[i-1])+(C*Y[i-1])+E2)%F;
        A[i]=(X[i]+Y[i])%F;
    }
    rep(len, 1, N+1){
        int start=1;
        int end=start+len-1;
        while(end<=N){
            vector<ll> temp;
            rep(j,start,end+1)temp.pb(A[j]);
            subarrays.push_back(temp);
            start++;
            end++;
        }
    }
    ll ans=0;
    rep(i,1,K+1){
        ans=(ans+power(i))%mod;
    }
    cout << ans << endl;

}

int main(){
    fast_cin;
    int t=1; 
    cin >> t;
    rep(i,1,105){
        rep(j,1, 21){
            if(j==1) pown[i][j]=i;
            else pown[i][j]=(pown[i][j-1]*i)%mod;
        }
    }
    rep(i,1,t+1){
        cout <<"Case #"<<i <<": ";
        solve();
    }
    return 0;
}