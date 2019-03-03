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
int M[200101];

unordered_map<int,bool> temp;

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;cin>>n;

    rep(i,0,n){
    	int x;cin>>x;
    	M[x]=1;
    	temp[x];
    }
    ll sum = 2;
    ll ans = 0;

    for(sum; sum<=200000-1; sum++){
    	//is it possible to divide in sum parts
    	ll curr = 0;
    	for(auto it: temp){
    		int val = it.first;
    		int target = sum-val;
    		if(target >0 && M[target]!=0){
    			curr++;
    		}
    	}
    	ans=max(ans, curr/2);
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