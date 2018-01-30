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
double xis[1005];
double yis[1005];
double r;
int n;

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin >> n >> r;
    rep(i,0,n){
        cin>>xis[i];
    }
    yis[0]=r;
    rep(i,1,n){
        double ansy=r;
        rep(j,0,i){
            if(xis[i]>xis[j]+2*r || xis[i]<(xis[j]-2*r)) continue;
            double tempy=yis[j]+sqrt(4*r*r-pow(xis[i]-xis[j],2));
            if(ansy<tempy)ansy=tempy;
        }
        yis[i]=ansy;
    }
    rep(i,0,n) printf("%.10lf ", yis[i]);
    
}

int main(){
    // fast_cin;
	//clock_t clk;
	//clk = clock();
	//srand (time(NULL));
    int t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
    //clk = clock() - clk;	
	//cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}