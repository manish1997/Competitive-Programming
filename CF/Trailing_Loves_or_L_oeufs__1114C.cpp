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
#define MAX 100005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    //solve the problem. You can and you will :) give your best shot..
	ll n,b;
	cin>>n>>b;
	vector<pair<ll,ll> > pfs;
	ll curr= 2;
	while(curr*curr<=b){
		if(b%curr){
			curr++;
			continue;
		}
		ll cnt=0;
		while((b%curr)==0){
			b/=curr;
			cnt++;
		}
		pfs.pb({curr,cnt});
		curr++;
	}
	if(b>1){
		pfs.pb({b,1});
	}
	ll ans = -1;
	// cout << pfs.size() << endl;

	for(ll i=0; i<pfs.size(); i++){
		ll temp = n;
		
		curr = pfs[i].f;

		ll tempans = 0;

		// cout << temp << " " << curr<< endl;

		while(temp>=curr){
			tempans+=(temp/curr);
			if(curr>ceil(temp/(pfs[i].f))){
				break;
			}
			// cout << curr << " " <<  pfs[i].f << endl;
			curr*=pfs[i].f;
			// cout << curr << endl;
		}
		tempans/=pfs[i].s;
		// cout << tempans << endl;
		if(ans==-1){
			ans=tempans;
		}
		ans=min(ans, tempans);
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