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
vector<int> arr[500][10][2];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n,m;
    cin>>n>>m;
    rep(i,0,n){
    	rep(j,0,m){
    		int curr;cin>>curr;
    		rep(k,0,10){
    				arr[i][k][(curr>>k)&1].push_back(j);
    		}
    	}
    }
    rep(bit,0,10){
    	int both=0;
    	int onlyone=0;
    	rep(i,0,n){
    		if(arr[i][bit][0].size() > 0 && arr[i][bit][1].size() > 0){
    			both++;
    		}
    		else if(arr[i][bit][1].size()>0){
    			onlyone++;
    		}
    	}
    	if(onlyone%2){
    		//answer exists, take all where only one and keep 0 otherwise
    		cout << "TAK\n";
    		rep(i,0,n){
	    		if(arr[i][bit][0].size() > 0){
		    		cout << arr[i][bit][0].back()+1 << " ";
	    		}
	    		else{
	    			cout << arr[i][bit][1].back()+1 << " ";
	    		}
	    	}
	    	return;
    	}
    	else{
    		if(both>0){
    			//take only one and keep all others same
    			cout << "TAK\n";
    			rep(i,0,n){
		    		if(arr[i][bit][0].size() > 0 && arr[i][bit][1].size()>0 && both){
			    		cout << arr[i][bit][1].back()+1 << " ";
			    		both=0;
		    		}
		    		else if(arr[i][bit][0].size()>0){
		    			cout << arr[i][bit][0].back()+1 << " ";
		    		}
		    		else{
		    			cout << arr[i][bit][1].back()+1 << " ";
		    		}
		    	}
		    	return;
    			
    		}
    	}
    }
    cout <<"NIE\n";
    
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