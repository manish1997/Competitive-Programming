#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long int
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define mod2 1000000033
#define MAX 100003
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

pair<ll,ll> dp[10004][55];

pair<ll,ll> add(pair<ll,ll> curr, pair<ll,ll> temp){
    pair<ll,ll> ans;
    ans.f = (curr.f*temp.s)%mod;
    ans.f = (ans.f + ((curr.s*temp.f)%mod))%mod;
    ans.s = (curr.s*temp.s)%mod;
    return ans;
}

pair<ll,ll> mul(pair<ll,ll> curr, pair<ll,ll> temp){
    pair<ll,ll> ans;
    ans.f= (curr.f*temp.f)%mod;
    ans.s= (curr.s*temp.s)%mod;
    return ans;
}

//Modulus Expo
ll expo(ll x, ll n, ll m){
    if(n==0) return 1;
    ll temp=expo(x,n/2,m);
    temp = ((temp%m)*(temp%m))%m;
    if(n%2!=0) temp = ((temp%m)*(x%m))%m;
    return temp;
}
//end Modulus Expo


void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n,k;cin>>n>>k;
    vector<pair<ll,int>> pfs;
    for(ll i=2; i*i<=n; i++){
        if(n%i) continue;
        int cnt=0;
        while((n%i)==0){
            cnt++;
            n/=i;
        }
        pfs.push_back({i,cnt});
    }
    if(n>1){
        pfs.push_back({n,1});
    }

    ll num=1,den=1;
    for(int i=0; i<pfs.size(); i++){
        pair<ll,ll> ans={0,1};
        ll number=pfs[i].f;
        ll z=pfs[i].s;
        for(int j=0; j<=z; j++) dp[0][j]={0,1};
        dp[0][z]={1,1};

        for(int curr=1; curr<=k; curr++){
            for(int stage = 0; stage<=z; stage++){
                //dp[curr][stage] using dp[curr-1]
                pair<ll,ll> temp = {0,1};
                for(int prev=stage; prev<=z; prev++){
                    //dp[curr-1][prev]*1/prev+1
                    temp = add(temp, mul(dp[curr-1][prev], {1,prev+1}));
                }
                dp[curr][stage]=temp;
                if(curr==k){
                    ans=add(ans, {(dp[curr][stage].f*expo(number, stage, mod))%mod,dp[curr][stage].s});
                }
            }
        }
        num=(num*ans.f)%mod;
        den=(den*ans.s)%mod;
    }
    num=(num*expo(den,mod-2, mod))%mod;
    cout << num << endl;
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