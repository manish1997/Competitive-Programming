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

vector<int> V[5005];
int mapOfOne[5005];
int mapOfTwo[5005*5005];

void solve(){
    //solve the problem. You can and you will :) give your best shot.
    int n,q;
    cin>>n>>q;
    rep(i,1,q+1){
    	int l,r;cin>>l>>r;
    	rep(j,l,r+1) if(V[j].size()<3) V[j].push_back(i);
    }
    ll total = 0;
    
    rep(i,0,5005){
    	if(!V[i].empty()){
    		total++;
    	}
    	if(V[i].size()>2 || V[i].empty()) continue;
    	if(V[i].size()==1){
    		mapOfOne[V[i][0]]++;
    	}
    	if(V[i].size()==2){
    		int id = V[i][0]*5006 + V[i][1];
    		mapOfTwo[id]++;
    	}
    }
    ll ans = 0;
    rep(i,1,q+1){
    	rep(j,i+1,q+1){
    		//excluding i and j
    		ll temp = total;
    		temp-=mapOfOne[i];
    		temp-=mapOfOne[j];
    		temp-=mapOfTwo[i*5006+j];
    		ans = max(ans, temp);
    	}
    }
    cout << ans;
    return;
    
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