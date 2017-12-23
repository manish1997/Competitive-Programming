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
#define MAX 300005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
int c[MAX];
int ans[MAX];
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n,k;
    cin >> n >> k;
    priority_queue<pair<int,int> > PQ;
    rep(i,1,1+n){
        cin >> c[i];
        if(i<=k) PQ.push({c[i],i});
    }
    rep(i,k+1,k+n+1){
        if(i<=n) PQ.push({c[i],i});
        ans[(PQ.top().s)]=i;
        PQ.pop();
    }

    ll temp=0;
    rep(i,1,n+1){
        temp+= 1LL*(ans[i]-i)*c[i];
    }
    tr1(temp);
    rep(i,1,n+1) cout << ans[i] <<" ";
}

int main(){
    fast_cin;
	clock_t clk;
	clk = clock();
	srand (time(NULL));
    int t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
    clk = clock() - clk;	
	cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}