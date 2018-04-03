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
    int n,k,m;
    cin>>n>>k>>m;
    vector<pair<string,int> > curr(n);
    rep(i,0,n){
    	cin>>curr[i].f;
    }
    rep(i,0,n){
    	cin>>curr[i].s;
    }
    vector<ll> minn(k);
    map<string,int> M;
    rep(i,0,k){
    	int x;
    	int anss=1e9+1;

    	cin>>x;
    	rep(j,0,x){
    		int idx;cin>>idx;
    		idx--;
    		M[curr[idx].f]=i;
    		anss=min(anss, curr[idx].s);
    	}
    	minn[i]=anss;
    }
    ll ans=0;
    rep(i,0,m){
    	string a;cin>>a;
    	int grp=M[a];
    	ans+=(ll)minn[grp];
    }
    cout<<ans<<endl;
    

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