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
    int V[4];
    cin >> V[0] >> V[1] >> V[2] >> V[3];
    // bool ans=true;
    int ans[4];
    mem(ans,-1);

    rep(i,0,2){
        int low=V[i];
        int high=2*V[i];
        int limit=(i>0)?ans[i-1]:10000;
        repDown(j,min(high,limit),low){
            if(j>2*V[3] && j>=V[3]){
                ans[i]=j;
                break;
            }
        }
    }
    rep(i,2,3){
        int low=V[i];
        int high=2*V[i];
        int limit=(i>0)?ans[i-1]:10000;
        repDown(j,min(high,limit),low){
            if(j<=2*V[3] && j>=V[3]){
                ans[i]=j;
                break;
            }
        }
    }
    rep(i,0,3) if(ans[i]==-1) {
        printf("-1\n");
        return;
    }
    rep(i,0,3) printf("%d ", ans[i]);

}

int main(){
    fast_cin;
	// clock_t clk;
	// clk = clock();
	// srand (time(NULL));
    int t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
 //    clk = clock() - clk;	
	// cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}