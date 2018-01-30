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

void solve(){
    //solve the problem. You can and you will :) give your best shot..
	vector<vector<char> > V(9, vector<char> (9,'.'));
	rep(i,0,9){
		rep(j,0,9){
			cin >> V[i][j];
		}
	}
	int x,y;
	cin >> x >> y;
	x--;
	y--;
	int fx=x/3, fy=y/3;
	fx=x-3*fx;
	fy=y-3*fy;
	bool ans=false;
	rep(i,3*fx,3*fx+3){
		rep(j,3*fy,3*fy+3){
			if(V[i][j]=='.'){
				ans=true;
				V[i][j]='!';
			}
		}
	}
	if(!ans){
		rep(i,0,9) rep(j,0,9) if(V[i][j]=='.') V[i][j]='!';
	}
	rep(i,0,9){
		rep(j,0,9){
			printf("%c", V[i][j]);
			if(j==2 || j==5) printf(" ");
		}
		if(i==2 || i==5) printf("\n\n");
		else printf("\n");
	}
	printf("\n");
    
}

int main(){
    fast_cin;
	//clock_t clk;
	//clk = clock();
	//srand (time(NULL));
    int t=1; 
    cin >> t;
    while(t--){
        solve();
    }
    //clk = clock() - clk;	
	//cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}