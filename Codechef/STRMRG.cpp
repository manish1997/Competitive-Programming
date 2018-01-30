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

int dp[2][5005][5005];
int n,m;
string a,b;

int helper(int P, int start1, int start2){
    int pre;
    if(P==0) pre=a[start1-1]-'a';
    else pre=b[start2-1]-'a';
    int &ans = dp[P][start1][start2];
    // if(ans!=-1) return ans;

    if(start1==n && start2==m){
        return 0;
    }
    if(start1==n){
        if(b[start2]-'a'==pre){
            return dp[P][start1][start2]=helper(1, start1, start2+1);
        }
        else{
            return dp[P][start1][start2]=(1+helper(1, start1, start2+1));
        }
    }
    if(start2==m){
        if(a[start1]-'a'==pre){
            return dp[P][start1][start2]=helper(0, start1+1, start2);
        }
        else{
            return dp[P][start1][start2]=(1+helper(0, start1+1, start2));
        }
    }
    if(a[start1]-'a'==pre) return dp[P][start1][start2]=(helper(0, start1+1, start2));
    if(b[start2]-'a'==pre) return dp[P][start1][start2]=(helper(1, start1, start2+1));
    return dp[P][start1][start2]=(1+min(helper(0, start1+1, start2), helper(1, start1, start2+1)));
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin >> n >> m;
    cin >> a >> b;
    rep(i,0,2)rep(j,0,n+5)rep(k,0,m+5) dp[i][j][k]=-1;

    cout << 1+min(helper(0,1,0),helper(1,0,1)) << endl;
}

int main(){
    clock_t clk;
    srand (time(NULL));
    fast_cin;
    int t=1; 
    cin >> t;
    while(t--){
        solve();
    }
    clk = clock() - clk;  
    cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}