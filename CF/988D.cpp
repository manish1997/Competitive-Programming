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
ll arr[MAX];
ll n;
map<ll,ll> M;
//no more than three elements on a straight line
//can have distance in powers of 2 for every pair of points
void solve(){
    //solve the problem. You can and you will :) give your best shot..
	cin>>n;
	rep(i,0,n){
		cin>>arr[i];
		M[arr[i]]=true;
	}
	sort(arr,arr+n);
	rep(i,0,n){
		ll curr=arr[i];
		for(ll j=1; j<=2e9; j*=2LL){
			if(M.find(curr-j)!=M.end() && M.find(curr+j)!=M.end()){
				tr1(3);
				cout << curr-j << " " << curr << " " << curr+j << endl;
				return;
			}
		}
	}
	rep(i,0,n){
		ll curr=arr[i];
		for(ll j=1; j<=2e9; j*=2LL){
			if(M.find(curr+j)!=M.end()){
				tr1(2);
				cout << curr << " " << curr+j << endl;
				return;
			}
		}
	}
	tr1(1);
	cout<<arr[0]<<endl;
	

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