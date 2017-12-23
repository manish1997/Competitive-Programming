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
#define inf 1e8
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n,a,b; cin >> n >> a >> b;
    int curr=n;
    int at=0,bt=0;
    int ans=0;
    rep(i,0,6){
        while(curr>0 && (at<4 || bt<2)){
            bool flag=true;
            if(at<4 && curr>=a){
                curr-=a;
                at++;
                flag=false;
            }

            if(bt<2 && curr>=b){
                curr-=b;
                bt++;
                flag=false;
            }
            if(flag) break;
        }
        //cout << bt << " " << at << endl;
        ans++;
        if(bt==2 && at==4){
            tr1(ans);
            return;
        }
        curr=n;
    }
    return;

}

int main(){
    fast_cin;
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