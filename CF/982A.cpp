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

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    string s;
    int n;cin>>n;
    cin>>s;
    // int n=s.length();
    bool possible=false;
    bool neg=false;
    rep(i,0,s.length()){
    	if(s[i]=='0'){
    		if((i-1<0 || s[i-1]=='0') && (i+1>=n || s[i+1]=='0')){
    			possible=true;
    			break;
    		}
    	}
    	else{
    		if(i-1>=0 && s[i-1]=='1') neg=true;
    		if(i+1<n && s[i+1]=='1') neg=true;
    		if(neg) break;
    	}
    }
    if(neg|| possible){
    	cout <<"NO";
    }
    else cout << "YES";
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