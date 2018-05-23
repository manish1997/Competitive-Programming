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
#define MAX 100005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n,k;
    cin>>n>>k;
    if(n==1){
        cout << k << endl;
        return;
    }
    if(k==1){
        rep(i,0,n)cout << k << " ";
        cout << endl;
        return;
    }
    if(k==2){
        cout << 2 << " ";
        rep(i,0,n-1 )cout << 1 << " ";
        cout << endl;
        return;
    }
    if(k==3){
        if(n%2){
            cout << 3 << " ";
        }
        else{
            cout << 2 << " ";
        }
        rep(i,0,n-1) cout << 1 << " ";
        cout << endl;
        return;
    }
    int bit=0;
    rep(i,0,32) if((k>>i)&1LL) bit=i;
    cout << (1<<bit) << " ";
    if(n%2) cout << ((1<<bit)-2) << " ";
    else cout << ((1<<bit)-1) << " ";
    rep(i,0,n-2) cout << 1 << " "; 
    cout << endl;
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