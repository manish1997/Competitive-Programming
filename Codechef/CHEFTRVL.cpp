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
#define INF (1<<30)-1
#define BIT 29
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> adj[MAX];
int arr[MAX];
int level[MAX];
ll odd[2],even[2];

void bfs(int node, int p, int curr){
	if(curr%2){
		odd[arr[node]]++;
	}
	else{
		even[arr[node]]++;
	}
	level[node]=curr;
	rep(i,0,adj[node].size()){
		if(adj[node][i]!=p){
			bfs(adj[node][i], node, curr+1);
		}
	}
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;cin>>n;
    rep(i,0,MAX)adj[i].clear();

    rep(i,0,n-1){
    	int a,b;
    	cin>>a>>b;
    	a--;b--;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    rep(i,0,n){
    	cin>>arr[i];
    	int cnt=0;
    	//because parity of
    	//numbers of one's in axorb
    	// is same as (parityofaones)^(parityofbones)
    	//because taking xor stays all one's or 
    	//-2*k, so odd/even doesn't change
    	rep(j,0,BIT+1){
    		if((arr[i]>>j)&1) cnt++;
    	}
    	if(cnt%2) arr[i]=1;
    	else arr[i]=0;
    }
    if(n==1){
    	cout << 0 << endl;
    	return;
    }
    mem(odd,0);
    mem(even,0);
    bfs(0,-1,1);
    ll ans=0;
    rep(i,0,n){
		if(level[i]%2){
			//all elements at odd levels
			//now has distance with 0 parity with ith
			//so we need to differ parity in arr[i]s
			ans+=odd[(arr[i]+1)%2];
			//all elements at even levels
			//now has distance with 1 parity with ith
			//so we need to maintain same parity in arr[i]s
			ans+=even[arr[i]];
		}
		else{
			ans+=even[(arr[i]+1)%2];
			ans+=odd[arr[i]];
		}
    }
    cout << (ans>>1LL) << endl;




}

int main(){
    fast_cin;
    int t=1; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}