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
vector<int> adj[MAX];
int parent[MAX];
pair<int,int> edges[MAX];

int root(int idx){
	if(idx!=parent[idx]) parent[idx]=root(parent[idx]);
	return parent[idx];
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n,m,d;
    cin>>n>>m>>d;
    rep(i,0,m){
    	int a,b;cin>>a>>b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    	edges[i]={a,b};
    }
    unordered_map<int,bool> padosi;
    rep(i,0,adj[1].size()) padosi[adj[1][i]];
    rep(i,0,MAX) parent[i]=i;

    bool visited[MAX];
    mem(visited,false);

    visited[1]=true;

    for(auto it:padosi){
    	int curr = it.f;
    	queue<int> Q;
    	Q.push(curr);
    	while(!Q.empty()){
    		int temp = Q.front();
    		Q.pop();
    		if(visited[temp]) continue;
    		visited[temp]=true;
    		if(padosi.find(temp)!=padosi.end()){
    			parent[temp]=curr;
    		}
    		for(auto i: adj[temp]){
    			if(i!=1 && visited[i]==false){
    				Q.push(i);
    			}
    		}
    	}
    }


    unordered_map<int,vector<int>> M;
    for(auto it:padosi){
    	M[parent[it.f]].pb(it.f);
    }
    if(M.size()>d){
    	cout <<"NO";
    	return;
    }

    vector<pair<int,int> > V;
    int rem = d-M.size();

    rep(i,0,MAX) parent[i]=i;

    for(auto it:M){
    	parent[it.f]=1;
    	V.pb({1,it.f});
    }
   	for(auto it:M){
   		vector<int> tem = it.s;
   		for(auto i: tem){
   			if(i!=it.f && rem>0){
   				parent[i]=1;
   				V.pb({1,i});
   				rem--;
   			}
   			if(rem==0) break;
   		}
		if(rem==0) break;
   	}
   	if(rem>0){
   		cout <<"NO";
   		return;
   	}

    cout <<"YES"<<endl;
    
    rep(i,0,m){
    	if(edges[i].f==1 || edges[i].s==1){
    		continue;
    	}
    	int roota=root(edges[i].f);
    	int rootb = root(edges[i].s);
    	if(roota==rootb) continue;
    	V.pb(edges[i]);
    	if(roota==1){
    		parent[rootb]=roota;
    	}
    	else{
    		parent[roota]=rootb;
    	}
    }

    for(auto it:V){
    	cout << it.f << " " << it.s << endl;
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