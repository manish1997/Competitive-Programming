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
ll fact[200002];
ll inv[200002];
ll dp[2005];
//Modulus Expo
ll expo(ll x, ll n, ll m){
    if(n==0) return 1;
    ll temp=expo(x,n/2,m);
    temp = ((temp%m)*(temp%m))%m;
    if(n%2!=0) temp = ((temp%m)*(x%m))%m;
    return temp;
}
//end Modulus expo
vector<pair<int,int> > V;
ll F(int i, int j){
	ll n=V[j].f-V[i].f;
	ll r=V[j].s-V[i].s;
	ll ans=(fact[n+r]*inv[r])%mod;
    ans=(ans*inv[n])%mod;
    return ans;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    
    int h,w;cin>>h>>w;
    h--;w--;
    int n;cin>>n;
    V.resize(n);
    rep(i,0,n){
    	cin>>V[i].f>>V[i].s;
    	V[i].f--;
    	V[i].s--;
    }

    sort(V.begin(), V.end());
    V.pb({h,w});
    rep(i,0,V.size()){
    	ll n=V[i].f+V[i].s;
    	ll r=V[i].s;
    	dp[i]=(fact[n]*inv[r])%mod;
    	dp[i]=(dp[i]*inv[n-r])%mod;
    	rep(j,0,i){
    		if(V[j].f<=V[i].f && V[j].s<=V[i].s){
    			dp[i]=(dp[i]-((dp[j]*F(j,i))%mod)+mod)%mod;
    		}
    	}
    }
    cout << dp[V.size()-1] << endl;
}

int main(){
    fast_cin;
    int t=1; 
    cin >> t;
    fact[0]=1;
    rep(i,1,200002){
    	fact[i]=(i*fact[i-1])%mod;
    }
    ll temp=expo(fact[200001], mod-2, mod);
    inv[200001]=temp;
    repDown(i,200000,0){
    	inv[i]=(inv[i+1]*(i+1))%mod;
    }
    while(t--){
        solve();
    }
    return 0;
}