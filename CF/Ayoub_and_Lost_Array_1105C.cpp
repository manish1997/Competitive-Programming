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
    ll n,l,r;
    cin>>n>>l>>r;
    ll arr[3];
    arr[0]=(r-l+1)/3;
    arr[1]=(r-l+1)/3;
    arr[2]=(r-l+1)/3;
    if(((r-l+1)%3)==1){
    	arr[r%3]++;
    }
    else if(((r-l+1)%3)==2){
    	arr[r%3]++;
    	arr[(r-1)%3]++;
    }
    ll dp[2][3];
    dp[0][0]=arr[0]%mod;
    dp[0][1]=arr[1]%mod;
    dp[0][2]=arr[2]%mod;
    for(int i=1; i<n; i++){
    	dp[1][0]=(((dp[0][0]*arr[0])%mod)+((dp[0][1]*arr[2])%mod)+((dp[0][2]*arr[1])%mod))%mod;
    	dp[1][1]=(((dp[0][0]*arr[1])%mod)+((dp[0][1]*arr[0])%mod)+((dp[0][2]*arr[2])%mod))%mod;
    	dp[1][2]=(((dp[0][0]*arr[2])%mod)+((dp[0][1]*arr[1])%mod)+((dp[0][2]*arr[0])%mod))%mod;
    	dp[0][1]=dp[1][1];
    	dp[0][2]=dp[1][2];
    	dp[0][0]=dp[1][0];
    }

    cout << dp[0][0] << endl;
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