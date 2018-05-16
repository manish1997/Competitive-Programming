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
ll dp[105][104];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n,q;
    cin>>n>>q;
    char c[n][n];
    rep(i,0,n)rep(j,0,n)cin>>c[i][j];
	pair<int,int> ans={0,0};
    ll temp=0;

    rep(i,0,n){
    	rep(j,0,n){
    		if(c[i][j]=='#') continue;
    		int count=0;
    		rep(k,j,n){
    			if(c[i][k]=='.') count++; else break;
    		}
    		if(count>=q){
    			count=0;
    			rep(k,j,n){
	    			if(count<q) dp[i][k]++;
	    			else break;
	    			count++;
	    		}
    		}
    		count=0;
    		rep(k,i,n) if(c[k][j]=='.') count++; else break;
    		if(count>=q){
    			count=0;
    			rep(k,i,n){
    				if(count<q) dp[k][j]++;
    				else break;
    				count++;
    			}
    		}
    	}
    }
    rep(i,0,n){
    	rep(j,0,n){
    		if(c[i][j]=='#') continue;
    		if(dp[i][j]>temp){
    			temp=dp[i][j];
    			ans={i,j};
    		}
    	}
    }
    cout << ans.f+1 << " " << ans.s+1 << endl;
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