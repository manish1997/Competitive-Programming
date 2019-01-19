#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long


void solve(){
    int n;cin>>n;
    ll dp[n+1];
    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    dp[0]=0;
    for(int i=0; i<n; i++){
        dp[i+1]=(((2*dp[i])%mod)-dp[arr[i]-1]+2+mod)%mod;
    }
    cout << dp[n] << endl;
}

int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }


    return 0;
}