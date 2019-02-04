#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define mod 1000000007
#define MAX 100005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
struct treenode{
	pair<ll,ll> child[2];
	treenode(){
		child[0]=child[1]={-1,-1};
	}
};

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n,k,A,B;
    cin>>n>>k>>A>>B;
    ll arr[k];
    map<ll,treenode*> M;
    ll N = 1ll<<n;
    map<ll,pair<ll,ll> > Z;


    rep(i,0,k){
    	cin>>arr[i];
    	arr[i]--;
    	Z[arr[i]+N].second++;
    }

    for(auto it: Z){
		ll node = (it).first;
		ll avengers = (it).second.second;
		ll childMin = (it).second.first;
		if(M.find(node/2)==M.end()) M[node/2] = new treenode();
		M[node/2]->child[node%2].second=avengers;
		M[node/2]->child[node%2].first=(avengers*B*1LL);
	}

    ll currLen = 2;

    while(M.begin()->first!=1){
    	map<ll, treenode*> M2;
    	for(auto it: M){
    		ll node = (it).first;
    		pair<ll,ll> leftChild = (it).second->child[0];
    		pair<ll,ll> rightChild = (it).second->child[1];
    		ll avengers = (leftChild.second==-1)?0:leftChild.second;
    		avengers += (rightChild.second==-1)?0:rightChild.second;
    		ll childMin = (leftChild.first==-1)?A:leftChild.first;
    		childMin += (rightChild.first==-1)?A:rightChild.first;
    		ll currMin = (avengers==0)?A:(B*avengers*currLen);
    		if(M2.find(node/2)==M2.end()) M2[node/2] = new treenode();
    		M2[node/2]->child[node%2].second = avengers;
    		M2[node/2]->child[node%2].first = min(childMin, currMin);
    	}
    	M=M2;
    	currLen*=2LL;
    }

    for(auto it: M){
    		ll node = (it).first;
    		pair<ll,ll> leftChild = (it).second->child[0];
    		pair<ll,ll> rightChild = (it).second->child[1];
    		ll avengers = (leftChild.second==-1)?0:leftChild.second;
    		avengers += (rightChild.second==-1)?0:rightChild.second;
    		ll childMin = (leftChild.first==-1)?A:leftChild.first;
    		childMin += (rightChild.first==-1)?A:rightChild.first;
    		ll currMin = (avengers==0)?A:(B*avengers*currLen);
    		currMin = min(currMin, childMin);
    		cout << min(B*N*k, currMin) << endl;
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