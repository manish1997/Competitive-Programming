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
#define MAX 200005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
// int arr[MAX];
// map<int,int> M;
ll k;
vector<ll> V[MAX];
map<ll, pair<ll,ll> > M;

void solve(){
    //solve the problem. You can and you will :) give your best shot..
	cin>>k;
	bool ans=false;
	rep(i,1,k+1){
		ll ni;cin>>ni;
		ll curr=0;
		rep(j,0,ni){
			ll x;cin>>x;
			V[i].pb(x);
			curr+=x;
		}
		rep(j,0,ni){
			if(M.find(curr-V[i][j])!=M.end() && M[curr-V[i][j]].f!=i){
				cout <<"YES\n";
				cout << M[curr-V[i][j]].f << " " << M[curr-V[i][j]].s << endl;
				cout << i << " " << j+1 << endl;
				return;
			}
			M[curr-V[i][j]]={i, j+1};
		}
	}
	cout << "NO";


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