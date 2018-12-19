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
#define MAX 502
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

ll st_b[2],st_a[2];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    string s;
    cin>>s;
    ll odd=0;
    ll even=0;

    rep(i,0,s.length()){
        if(s[i]=='b'){
            st_b[i%2]+=1;
            odd+=(st_b[i%2]);
            even+=(st_b[1-(i%2)]);
        }
        else{
            st_a[i%2]+=1;
            odd+=(st_a[i%2]);
            even+=(st_a[1-(i%2)]);
        }
    }
    cout << even << " " << odd << endl;

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