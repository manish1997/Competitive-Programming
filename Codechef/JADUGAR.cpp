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
long long dp[10000001];
//Modulus Expo
ll expo(ll x, ll n, ll m){
    if(n==0) return 1;
    ll temp=expo(x,n/2,m);
    temp = (temp*temp)%m;
    if(n%2!=0) temp = (temp*x)%m;
    return temp;
}
//end Modulus Expo

ll expon[10000001];
//good way to find inv upto big values
//find inv of all divided basically n!
//come down from n, now 1/n=fact(n-1)*(inv(n!))
ll fact[10000001];
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll N,K,A,B;
    cin>>N>>K>>A>>B;
    dp[1]=K;
    dp[2]=((A*dp[1])%mod+((B*((dp[1]*dp[1])%mod))%mod))%mod;
    ll abk=(A+((2*((B*K)%mod))%mod))%mod;
    ll aa=(A*A)%mod;
    dp[0]=0;
    
    rep(i,3,N+1){
    	dp[i]=(((abk*((2*i-3+mod)%mod))%mod)*dp[i-1])%mod;
    	dp[i]=(dp[i]-((((aa*(i-3))%mod)*dp[i-2])%mod))%mod;
    	dp[i]=(dp[i]+mod)%mod;
    	dp[i]=(dp[i]*expon[i])%mod;
    }
    cout<<dp[N]<<endl;
    
}

int main(){
    fast_cin;
    int t=1; 
    // cin >> t;
    fact[0]=1;
    rep(i,1,10000001) fact[i]=(fact[i-1]*i)%mod;
    ll temp=expo(fact[10000000], mod-2, mod);

    repDown(i,10000000,1){
    	expon[i]=(temp*fact[i-1])%mod;
    	temp=(temp*i)%mod;
    }


    while(t--){
        solve();
    }
    return 0;
}