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
#define MAX 505
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

int A[MAX][MAX], B[MAX][MAX];
void change(int x, int y){
	A[x][y]+=1;
	A[x][y]%=2;
	A[x+1][y]+=1;
	A[x+1][y]%=2;
	A[x][y+1]+=1;
	A[x][y+1]%=2;
	A[x+1][y+1]+=1;
	A[x+1][y+1]%=2;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n,m;
    cin>>n>>m;
    rep(i,0,n)rep(j,0,m) cin>>A[i][j];
    rep(i,0,n)rep(j,0,m) cin>>B[i][j];
    bool ans = true;

    rep(i,0,n)rep(j,0,m) if(A[i][j]!=B[i][j]) ans=false;
    
    if(ans){
    	cout<<"Yes";
    	return;
    }

    if(n==1||m==1){
    	cout<<"No";
    	return;
    }

    //solution starts
    rep(j,0,m-1){
    	rep(i,0,n-1){
    		if(A[i][j]!=B[i][j]){
    			change(i,j);
    		}
    	}
    }
    ans = true;
    rep(i,0,n)rep(j,0,m) if(A[i][j]!=B[i][j]) ans=false;
	if(ans){
    	cout<<"Yes";
    }
    else{
    	cout <<"No";
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