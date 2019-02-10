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
ll dp[5005][5005];
vector<int> A;
int findAns(int start, int end){
	if(start==end){
		return 0;
	}
	if(dp[start][end]!=-1) return dp[start][end];
	if(A[start]==A[end]){
		return dp[start][end]=(1+findAns(start+1, end-1));
	}
	return dp[start][end]=(1+min(findAns(start, end-1), findAns(start+1, end)));
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;
    cin>>n;
    A.clear();
    int arr[n];
    rep(i,0,n){
    	cin>>arr[i];
    }
    mem(dp,-1);
    // int dp[5005];
    // rep(i,0,5005) dp[i]=1;
    // dp[arr[0]-1]=0;
    // vector<int> A;
    A.push_back(arr[0]);
    for(int i=1; i<n; i++){
    	if(arr[i]!=arr[i-1]){
    		A.pb(arr[i]);
    	}
    }

    cout << findAns(0,A.size()-1) << endl;
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