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
#define MAX 200005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
ll n,k;
ll a[MAX],b[MAX];
priority_queue<pair<ll,ll> > PQ;
vector<int> adj[MAX];
vector<int> tempAdj[MAX];

bool check(ll number){

	ll A[MAX];
	rep(i,0,MAX){
		tempAdj[i].resize(adj[i].size());
		rep(j,0,adj[i].size()) tempAdj[i][j]=adj[i][j];
	}
	rep(i,0,MAX) A[i]=a[i];

	int minIdx = 0;


	rep(i,0,k){
		//extract minimum days left to charge it
		while(minIdx<k-1 && tempAdj[minIdx].empty()) minIdx++;
		if(minIdx==k-1) break;

		int idx = tempAdj[minIdx].back();
		tempAdj[minIdx].pop_back();

		pair<ll,ll> curr;
		curr.f=minIdx;
		curr.s=idx;
		if(i>curr.f) return false;
		//current fuel in curr.s is a[curr.s]
		//after giving number fuel, new fuel amount = number + a[curr.s]
		//days we have added for this battery = (number + a[curr.s])/b[curr.s]
		ll pos = (curr.f+((number+A[curr.s])/b[curr.s]));
		if(pos<MAX) tempAdj[pos].pb(curr.s);
		A[curr.s] = (number+A[curr.s])%b[curr.s];
	}
	rep(i,0,k-1){
		if(!tempAdj[i].empty()) return false;
	}
	return true;

}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
	cin>>n>>k;
	

	rep(i,0,n){
		cin>>a[i];
	}
	rep(i,0,n){
		cin>>b[i];
		if((a[i]/b[i])<MAX)adj[a[i]/b[i]].pb(i);
		a[i]=a[i]%b[i];
	}
	ll start = 0;
	ll end = 1e14;
	while(start<=end){

		ll mid = (start+end)>>1LL;
		if(check(mid)) end=mid-1;
		else start=mid+1;
	}
	if(start>1e14){
		cout<<-1;
	}
	else {
		cout << start << endl;
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