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
vector<int> V;
vector<int> ans;
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;
    cin >> n;
    int temp=1+1e9;
    rep(i,0,n){
        int x; cin >> x;
        V.pb(x);
        temp=min(x,temp);
    }
    rep(i,0,n)if(V[i]==temp)ans.pb(i);
    ll tem=n+2;
    rep(i,1,ans.size()){
        tem=min(tem, ans[i]-ans[i-1]);
    }
    cout << tem << endl;
}

int main(){
    fast_cin;
	//clock_t clk;
	//clk = clock();
	//srand (time(NULL));
    int t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
    //clk = clock() - clk;	
	//cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}