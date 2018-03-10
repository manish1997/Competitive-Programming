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
string s;
vector<int> ans;
 
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>s;
    ans.resize(s.length(), 0);
    // tr2(s, s.length());
    vector<vector<int> > V(26);
    rep(i,0,s.length()) V[s[i]-'a'].pb(i);
    int odd=0, even=0;
    rep(i,0,26) if(V[i].size()%2) odd++;
    if(odd>1){
    	tr1(-1);
    	return;
    }
	rep(i,0,26){
		if(V[i].size()%2){
			ans[s.length()/2]=V[i].back();;
			V[i].pop_back();
			break;
		}
	}
    int start=0;
    int end=s.length()-1;
    rep(i,0,26){
    	while(V[i].size()){
    		ans[start]=V[i].back();
    		V[i].pop_back();
    		ans[end]=V[i].back();
    		V[i].pop_back();
    		end--;
    		start++;
    	}
    }
    rep(i,0,s.length()) cout << ans[i]+1 << " ";
    cout << endl;
 
}
 
int main(){
    // fast_cin;
    int t=1; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
} 