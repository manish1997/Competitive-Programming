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
#define MAX 5005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
ll n,K;
ll arr[MAX];
ll dp[MAX][MAX];
ll dist[MAX];


void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n>>K;
    rep(i,1,n+1)cin>>arr[i];
    sort(arr+1,arr+n+1);

    rep(i,1,n+1){
    	for(int j=i; j>=1; j--){
    		if(arr[i]-arr[j]<=5){
    			dist[i]=i-j+1;
    		}
    	}
    }


    rep(i,1,n+1){
    	rep(k,1,i+1){
    		//till ith point, upto k segments
    		dp[i][k]=max(dp[i-1][k], dp[i-1][k-1]+1);
    		dp[i][k]=max(dp[i][k], dp[i-dist[i]][k-1]+dist[i]);
    	}
    }
    cout << dp[n][K] << endl;

    
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