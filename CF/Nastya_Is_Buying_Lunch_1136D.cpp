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
#define MAX 500005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
int n,m;
map<pair<int,int>, bool> M;
int arr[MAX];
vector<int> adj[MAX];
int loc[MAX];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n>>m;
    rep(i,1,n+1){
    	cin>>arr[n-i+1];
    	loc[arr[n-i+1]]=n-i+1;
    }
    rep(i,0,m){
    	int b,a;cin>>b>>a;
    	//a connected to b
    	M[{a,b}];
    	if(loc[a]>loc[b]){
    		continue;
    	}
    	adj[loc[a]].pb(loc[b]);
    }
    sort(adj[1].begin(), adj[1].end());
    vector<int> temp;
    rep(i,0,adj[1].size()){
    	temp.pb(adj[1][i]);
    	adj[1][i]=arr[adj[1][i]];
    }

    int reach = 2;
    rep(i,0,adj[1].size()){
    	int temploc = temp[i];
    	while(true){
    		if(temploc==reach){
    			reach++;
    			break;
    		}
    		//only m changes so (m) total time for this loop
    		if(M.find({arr[temploc-1], arr[temploc]})!=M.end()){
    			swap(arr[temploc-1], arr[temploc]);
    			temploc--;
    		}
    		else{
    			break;
    		}
    	}
    }
    cout << reach-2 << endl;
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