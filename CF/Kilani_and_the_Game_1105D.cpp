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
#define MAX 1007
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
int n,m, p;
ll s[10];
char arr[MAX][MAX];
queue<pair<int,int>> Q[10];

bool valid(int x, int y){
	return (x>=0 && y>=0 && x<n && y<m && arr[x][y]=='.');
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n>>m>>p;
    for(int i=1; i<=p; i++){
    	cin>>s[i];
    }
    rep(i,0,n){
    	rep(j,0,m){
    		cin>>arr[i][j];
    		if(arr[i][j]<='9' && arr[i][j]>='1'){
    			Q[arr[i][j]-'0'].push({i,j});
    		}
    	}
    }
    while(true){
    	bool breakit = true;
    	for(int i=1; i<=p; i++){
    		queue< pair<pair<int,int>,int> > temp;

    		while(!Q[i].empty()){
    			temp.push({Q[i].front(), 0});
    			Q[i].pop();
    		}

    		while(!temp.empty()){
    			pair<int,int> current = temp.front().first;
    			int currents = temp.front().second;

    			temp.pop();

    			if(currents>=s[i]){
    				//can't move forward
    				continue;
    			}

    			for(int x=-1; x<=1; x++){
    				for(int y=-1; y<=1; y++){
    					if(abs(x)+abs(y)!=1) continue;
    					int nextx= x+current.f;
    					int nexty= y+current.s;
    					if(valid(nextx, nexty)){
    						arr[nextx][nexty]=i+'0';
    						Q[i].push({nextx, nexty});
    						temp.push({{nextx, nexty}, currents+1});
    					}
    				}
    			}
    		}
    		if(Q[i].size()) breakit=false;
    	}
    	if(breakit) break;
    }
    int ans[10];
    mem(ans,0);

    rep(i,0,n){
    	rep(j,0,m){
    		if(arr[i][j]<='9' && arr[i][j]>='1')ans[arr[i][j]-'0']++;
    	}
    }
    for(int i=1; i<=p; i++) cout << ans[i] << " ";
    	cout << endl;


    
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