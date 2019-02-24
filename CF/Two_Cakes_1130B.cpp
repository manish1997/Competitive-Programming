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

ll findbest(pair<ll,ll> a, pair<ll,ll> b){
	ll ans = abs(b.f-a.f)+abs(b.s-a.s);
	ans=min(ans, abs(b.s-a.f)+abs(b.f-a.s));
	return ans;
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n;
    cin>>n;
    pair<ll,ll> arr[n+1];
    rep(i,0,n+1){
    	arr[i]={-1,-1};
    }

    rep(i,0,2*n){
    	ll x;cin>>x;
    	if(arr[x].f==-1){
    		arr[x].f=i;
    	}
    	else{
    		arr[x].s=i;
    	}
    }
    ll ans = 0;
    arr[0]={0,0};

    rep(i,1,n+1){
    	ans+=findbest(arr[i], arr[i-1]);
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