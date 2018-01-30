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
bool val(string &s, int i){
    if(i<0 || i>=s.length()) return false;
    return true;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    string s;
    cin >> s;
    int ans=0;
    while(true){
        bool br=true;
        string temp="";
        if(s.length()>=2){
            if(s[0]!=s[1]){
                br=false;
            }
            else{
                temp.pb(s[0]);
            }
            if(s[s.length()-1]!=s[s.length()-2]){
                br=false;
            }
            else{
                temp.pb(s[s.length()-1]);
            }
        }
        rep(i,1,s.length()-1){
            if(i>=s.length()-1) break;
            if((s[i-1]!=s[i]) || (s[i+1]!=s[i])){
                br=false;
            }
            else{
                temp.pb(s[i]);
            }
        }
        if(br) break;
        ans++;
        s=temp;
        if(s.length()==0) break;
    }
    tr1(ans);
}

int main(){
    fast_cin;
	//clock_t clk;
	//clk = clock();
	//srand (time(NULL));
    int t=1; 
    // rep(i,0,1e6/4){
    //     cout <<"aaab";
    // }
    // cin >> t;
    while(t--){
        solve();
    }
    //clk = clock() - clk;	
	//cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}