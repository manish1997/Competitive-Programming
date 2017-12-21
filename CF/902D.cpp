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

int ans[200][200];


void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;
    cin >> n;
    ans[1][1]=1;
    ans[0][0]=1;
    if(n==1){
        tr1(1);
        cout << "0 1" << endl;
        tr1(0);
        cout << "1" << endl;
        return;
    }
    rep(i,2,n+1){
        rep(j,0,200) ans[i][j]=ans[i-1][j];
        int temp=ans[i][0];
        repDown(j,198,0){
            ans[i][j+1]=ans[i][j];
        }
        ans[i][0]=0;
        rep(j,0,200) ans[i][j]+=ans[i-2][j];
    }
    int first=-1;
    repDown(i,199,0) if(ans[n][i]%2){
        first=i;
        break;
    }
    tr1(first);
    rep(i,0,first+1) cout << (ans[n][i]%2) << " ";
    cout << endl;
    repDown(i,199,0) if(ans[n-1][i]%2){
        first=i;
        break;
    }
    tr1(first);
    rep(i,0,first+1) cout << (ans[n-1][i]%2) << " ";
}

int main(){
	clock_t clk;
	clk = clock();
	srand (time(NULL));
    int t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
    clk = clock() - clk;	
	cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}