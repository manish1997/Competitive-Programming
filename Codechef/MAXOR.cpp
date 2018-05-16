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
#define MAX 1000005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
int arr[1000006];
ll dp[1000006][25];
// int MX=19;

ll get(int i,int j){
	if(j==-1) return arr[i];
	return dp[i][j];
};

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;
    cin>>n;
    mem(arr,0);
    mem(dp,0);
    int maxx=-1;
    rep(i,0,n){
    	int x;cin>>x;
    	arr[x]++;
    	maxx=max(maxx, x);
    }
    ll ans=0;
    if(maxx==0){
    	cout << ((ll)arr[maxx]*((ll)arr[maxx]-1LL))/2LL << endl;
    	return;
    }
    int MX=log2(maxx);

    for(int mask=0; mask<=maxx; mask++){
    	for(int j=0; j<=MX; j++){
    		if(mask&(1<<j)) dp[mask][j]=get(mask, j-1)+get(mask^(1<<j), j-1);
    		else dp[mask][j]=get(mask,j-1);
    	}
    	ll cnt=dp[mask][MX];
    	ans=ans+((ll)arr[mask]*(cnt-(ll)arr[mask]))+((ll)arr[mask]*((ll)arr[mask]-1LL))/2;
    }
    cout << ans << endl;


}

int main(){
    fast_cin;
    int t=1; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}