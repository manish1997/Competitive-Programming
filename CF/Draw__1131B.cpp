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
ll diff(pair<ll,ll> a, pair<ll,ll> b){
	pair<ll,ll> x = {b.f, a.f};
	pair<ll,ll> y = {b.s, a.s};
	if(a.s>b.f){
		return 0;
	}
	if(b.s<a.f){
		return 0;
	}
	ll temp = max(a.s,a.f);
	ll temp2= min(b.s,b.f);
	return (temp2-temp+1);
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;cin>>n;
    pair<ll,ll> arr[n+1];
    arr[0]={0,0};

    rep(i,1,n+1){
    	cin>>arr[i].f>>arr[i].s;
    }
    ll ans = 1;
    rep(i,1,n+1){

    	ans += diff(arr[i-1], arr[i]);
    	if(arr[i-1].f==arr[i-1].s){
    		ans--;
    	}
    }
    cout << ans << endl;
    
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