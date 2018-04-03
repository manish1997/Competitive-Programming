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
    int n;
    cin>>n;
    //first sec
    if(n>=6){
    	tr2(1,2);
    	tr2(1,3);
    	tr2(1,4);
    	rep(i,0,n-4) cout << 2 << " " << i+5 << endl;
    }
    else{
    	cout<<-1<<endl;
    }

    //second sec

    rep(i,0,n-1){
    	cout << 1 << " " << i+2 << endl;
    }
    

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
