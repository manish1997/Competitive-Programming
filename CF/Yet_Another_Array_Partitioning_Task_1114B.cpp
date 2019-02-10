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
bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.s<b.s;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n,m,k;
    cin>>n>>m>>k;
    pair<ll,ll> arr[n];
    rep(i,0,n){
    	cin>>arr[i].f;
    	arr[i].s=i;
    }
    bool temp[n];
    mem(temp,false);
    sort(arr,arr+n);
    ll ans = 0;
    for(int i=n-1; i>=n-m*k; i--){
    	ans+=arr[i].f;
    	temp[arr[i].s]=true;
    }
    sort(arr,arr+n,comp);
    cout << ans << endl;
    int currCount = 0;
    int partition = 1;
    for(int i=0; i<n; i++){
    	if(temp[arr[i].s]){
    		currCount++;
    	}
    	if(partition<k && currCount==m){
    		cout << (i+1) << " ";
    		currCount = 0;
    		partition++;
    	}
    }


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