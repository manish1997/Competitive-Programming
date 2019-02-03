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
ll n,m,total;



map<pair<ll,ll>, ll> M;

long long cost[MAX];
long long quantity[MAX];



void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n>>m;
    rep(i,1,n+1){
    	cin>>quantity[i];
    }
    rep(i,1,n+1){
    	cin>>cost[i];
    }
    rep(i,1,n+1){
    	M[{cost[i],i}]=quantity[i];
    }



    ll ans=0;

    rep(ccc,0,m){
    	int type,quant;
    	cin>>type>>quant;

    	ll currans = 0;
    	if(M.find({cost[type],type})!=M.end()){
    		ll value = M[{cost[type],type}];

    		if(value>quant){
    			M[{cost[type],type}]-=quant;
    			currans+=(quant*cost[type]);
    			quant = 0;
    		}
    		else{
    			quant-=value;
    			currans+=(value*cost[type]);
    			M.erase({cost[type],type});
    		}
    	}

    	for(auto it=M.begin(); quant && it!=M.end(); ){
    		int value = (*it).s;
    		type = (*it).f.s;

    		if(quant<value){
    			M[(*it).f]-=quant;
    			currans+=(quant*cost[type]);
    			quant = 0;
    			it++;
    		}
    		else{
    			quant-=value;
    			currans+=(value*cost[type]);
    			M.erase(it++);
    		}
    	}
    	if(quant){
    		cout << 0 << endl;
    		continue;
    	}
    	cout << currans << endl;
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