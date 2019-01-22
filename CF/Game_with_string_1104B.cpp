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

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    string s="";
    char x;
    int cnt=0;
    while(cin>>x){
    	// cout << x;
    	if(s.length()==0){
    		s.pb(x);
    		continue;
    	}
    	if(s.back()==x){
    		s.pop_back();
    		cnt++;
    		continue;
    	}
    	s.push_back(x);
    }
    // cout << endl;
    if(cnt%2){
    	cout <<"Yes";
    }
    else{
    	cout <<"No";
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