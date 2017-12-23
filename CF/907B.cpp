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
    vector<string> V;
    rep(i,0,9){
        string s="";
        rep(j,0,3){
            string temp; cin >> temp;
            s+=temp;
        }
        V.pb(s);
    }
    int x,y;cin >> x >> y;
    x--;y--;
    int tx=x/3,ty=y/3;
    // tr2(tx,ty);
    int cnt=0;
    rep(i,tx*3,tx*3+3){
        bool flag=false;
        rep(j,ty*3, ty*3+3){
            cnt++;
            if(i==x && j==y){
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    // tr1(cnt);
    if(cnt<=3){
        ty=(cnt-1)%3;
        tx=0;
    }
    else if(cnt<=6){
        ty=(cnt-1)%3;
        tx=1;
    }
    else{
        ty=(cnt-1)%3;
        tx=2;
    }
    // tr2(tx,ty);
    bool alltrue=true;
    rep(i,tx*3,tx*3+3){
        rep(j,ty*3, ty*3+3){
            if(V[i][j]=='.') alltrue=false;
        }
    }
    if(!alltrue){
        rep(i,tx*3,tx*3+3){
            rep(j,ty*3, ty*3+3){
                if(V[i][j]=='.') V[i][j]='!';
            }
        }
    }
    else{
        rep(i,0,9){
            rep(j, 0, 9){
                if(V[i][j]=='.') V[i][j]='!';
            }
        }
    }
    rep(i,0,9){
        rep(j, 0, 9){
                if(j!=2 && j!=5)cout << (V[i][j]);
                else cout << (V[i][j]) << " ";
        }
        if(i==2 || i==5) cout <<endl<<endl;
        else cout << endl;
    }

    
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