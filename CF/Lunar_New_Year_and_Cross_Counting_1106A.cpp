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
bool valid(int x, int y){
	return (x>=0 && y>=0 && x<n && y<n);
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..

    cin>>n;
    char arr[n][n];
    rep(i,0,n)rep(j,0,n)cin>>arr[i][j];
    int ans=0;
    for(int i=1; i<n-1; i++){
    	for(int j=1; j<n-1; j++){
    		// cout << arr[i][j] << endl;
    		if(arr[i][j]==arr[i-1][j-1]){
    			if(arr[i][j]==arr[i+1][j+1]){
    				if(arr[i][j]==arr[i+1][j-1]){
    					if(arr[i][j]==arr[i-1][j+1]){
    						if(arr[i][j]=='X'){
    							ans++;
    						}
    					}
    				}
    			}
    		}
    	}
    }
    cout << ans << endl;

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