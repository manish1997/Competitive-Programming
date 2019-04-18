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
#define MAX 1005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
ll n,h;
ll arr[MAX];

bool possible(int idx){
	vector<ll> temp(0);
	rep(i,1,idx+1) temp.pb(arr[i]);
	sort(temp.begin(), temp.end());
	ll currHeight = 0;
	for(int i=(int)temp.size()-1; i>=0; i-=2){
		if(i==0){
			currHeight+=temp[i];
		}
		else{
			currHeight+=max(temp[i], temp[i-1]);
		}
	}
	return currHeight<=h;

}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n;
    cin>>h;
    rep(i,1,n+1)cin>>arr[i];

    ll start =1,end=n;
    while(start<=end){
    	ll mid=(start+end)>>1;
    	if(possible(mid)){
    		start=mid+1;
    	}
    	else{
    		end=mid-1;
    	}
    }
    cout << end << endl;

    
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