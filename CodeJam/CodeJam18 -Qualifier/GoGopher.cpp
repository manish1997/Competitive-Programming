//NOT Submitted in contest.. To be checked via local testing tool
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
#define MAX 1000005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
bool arr[1002][1002];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int a;
    cin>>a;
    // mem(arr,false);
    if(a==10){
    	rep(i,0,1000/6){
    		cout << 2 << " " << 2 << endl;
    		int x,y;
    		cin>>x>>y;
    		if(x==0) return;
    		// arr[x][y]=true;
    	}
    	rep(i,0,1000/6){
    		cout << 2 << " " << 3 << endl;
    		int x,y;
    		cin>>x>>y;
    		if(x==0) return;
    		// arr[x][y]=true;
    	}
    	rep(i,0,1000/6){
    		cout << 3 << " " << 2 << endl;
    		int x,y;
    		cin>>x>>y;
    		if(x==0) return;
    		// arr[x][y]=true;
    	}
    	rep(i,0,1000/6){
    		cout << 3 << " " << 3 << endl;
    		int x,y;
    		cin>>x>>y;
    		if(x==0) return;
    		// arr[x][y]=true;
    	}
    	rep(i,0,1000/6){
    		cout << 4 << " " << 2 << endl;
    		int x,y;
    		cin>>x>>y;
    		if(x==0) return;
    		// arr[x][y]=true;
    	}
    	rep(i,0,1000/6){
    		cout << 4 << " " << 3 << endl;
    		int x,y;
    		cin>>x>>y;
    		if(x==0) return;
    		// arr[x][y]=true;
    	}
    }
    else{
		for(int j=2; j<=69; j+=3){
			rep(i,0,1000/23){
				cout << 2 << " " << j << endl;
				int x,y;
				cin>>x>>y;
				if(x==0) return;
				// arr[x][y]=true;
			}
		}
    }
    return;
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
