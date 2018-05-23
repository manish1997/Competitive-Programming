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
int n;
int parent[MAX];
bool qans[2*MAX];
pair<int,pair<int,int> > queries[2*MAX];

int root(int u){
	if(u!=parent[u]) parent[u]=root(parent[u]);
	return parent[u];
}
void join(int u, int v){
	u=root(u);v=root(v);
	if(u==v) return;
	parent[u]=v;
}
int q;
void run(int eq){
    rep(i,1,n+1) parent[i]=i;
    bool ans=true;
    queue<pair<int,int> > Q;
    int u,v;
    rep(i,0,q){
        if(queries[i].f==eq){
        	u=queries[i].s.f;
        	v=queries[i].s.s;
            Q.push({u,v});
            if(ans){
                if(root(u)!=root(v)){
                    ans=false;
                }
                else Q.pop();
            }
        }
        else{
            u=queries[i].s.f;
        	v=queries[i].s.s;
        	join(u,v);
        	ans=true;
        	while(ans && !Q.empty()){
        		if(root(Q.front().f)!=root(Q.front().s)) ans=false;
        		else Q.pop();
        	}
        }
        qans[i]&=ans;
    }
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n;
    rep(i,1,n+1) parent[i]=i;
    cin>>q;
    rep(i,0,q) cin>>queries[i].f >> queries[i].s.f >> queries[i].s.s;
    mem(qans,true);
    run(1);
    run(2);
    rep(i,0,q){
        if(qans[i]) cout <<"YES\n";
        else cout <<"NO\n";
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