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
bool valid(int x, int y){
	return (x>=0 && y>=0 && x<8 && y<8);
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int r,c,k;
    cin>>r>>c>>k;
    r--;c--;
    bool vis[8][8];
    mem(vis,false);
    vis[r][c]=true;

    for(int i=0; i<k; i++){
    	bool temp[8][8];
    	mem(temp,false);

    	for(int xx=0; xx<8; xx++){
    		for(int yy=0; yy<8; yy++){
	    		if(vis[xx][yy]){

	    			for(int x=-1; x<=1; x++){
			    		for(int y=-1; y<=1; y++){
			    			int nextx=xx+x;
			    			int nexty=yy+y;
			    			if(valid(nextx, nexty)){
			    				temp[nextx][nexty]=true;
			    			}

			    		}
			    	}

			    }
    		}
    	}

    	for(int x=0; x<8; x++){
    		for(int y=0; y<8; y++){
    			vis[x][y]=temp[x][y];
    		}
    	}
    }
    int ans=0;
    for(int x=0; x<8; x++){
		for(int y=0; y<8; y++){
			ans+=(vis[x][y]==true);
		}
	}
	cout << ans << endl;

    
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