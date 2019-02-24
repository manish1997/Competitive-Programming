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
ll n,m;

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n>>m;
    vector<int> v[n];
    rep(i,0,m){
    	int a,b;cin>>a>>b;
    	a--;b--;
    	v[a].push_back(b);
    }

    int maxx = 0;

    rep(i,0,n){
    	//standing at ith station
    	maxx=max(maxx, (int)v[i].size());
    	rep(j,0,v[i].size()){
    		if(v[i][j]>i){
    			v[i][j]-=i;
    		}
    		else{
    			v[i][j]=(n-(i-v[i][j]));
    		}
    	}
    	sort(v[i].begin(), v[i].end());
    }

    if(maxx==0){
    	rep(i,0,n) cout << 0 << " ";
    	return;
    }


    rep(start,0,n){
    	int curr=start;
    	int idx=start;
    	rep(i,0,n){
    		if(v[curr].size()==maxx){
    			idx=curr;
    		}
    		curr=(curr+1)%n;
    	}
    	//start --- idx
    	ll ans = idx>=start? idx-start: n-(start-idx);
    	ans+=(maxx-1)*n;

    	int destt=v[idx][0];

    	for(int i=(idx+1)%n; i!=start; i=(i+1)%n){
    		if(v[i].size()!=maxx-1 || v[i].empty() ){
    			continue;
    		}
    		//dist between idx and i
    		int destByi = v[i][0];
    		int destToidx = (idx>=i)?idx-i:(n-(i-idx));
    		if(destToidx<destByi){
    			destt=max(destt, destByi-destToidx);
    		}
    	}

    	for(int i=start; i!=idx; i=(i+1)%n){
    		if(v[i].size()!=maxx || v[i].empty() ){
    			continue;
    		}
    		//dist between idx and i
    		int destByi = v[i][0];
    		int destToidx = (idx>=i)?idx-i:(n-(i-idx));
    		if(destToidx<destByi){
    			destt=max(destt, destByi-destToidx);
    		}
    	}
    	ans+=destt;
    	cout << ans << " ";
    	
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