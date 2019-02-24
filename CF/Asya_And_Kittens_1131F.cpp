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
#define MAX 150005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

int Parent[MAX];
vector<int> ans[MAX];

int root(int x){
	if(x!=Parent[x]) Parent[x]=root(Parent[x]);
	return Parent[x];
};

void union1(int x, int y){
	// ans[x].pb(y);
	if(ans[y].size()>ans[x].size()){
		swap(x,y);
	}
	for(auto it: ans[y]){
		ans[x].pb(it);
	}
	Parent[root(y)]=root(x);
};




void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;cin>>n;
	rep(i,0,MAX) {
		Parent[i]=i;
	};
    rep(i,0,MAX) ans[i].pb(i);

    pair<int,int> arr[n-1];

    rep(i,0,n-1){
    	cin>>arr[i].f>>arr[i].s;
    	arr[i].f=root(arr[i].f);
    	arr[i].s=root(arr[i].s);
		union1(arr[i].f, arr[i].s);
    }
    int jad = root(1);
    for(auto it: ans[jad]){
    	cout << it << " ";
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