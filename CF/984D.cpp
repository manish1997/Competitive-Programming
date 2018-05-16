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

//GCD
ll gcd(ll a, ll b){
    if ( a==0 ) return b;
    return gcd ( b%a, a );
}
//end GCD
int ans[5005][5005];
int n;
int arr[5005];
int maxx[5005][5005];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n;
    rep(i,0,n)cin>>arr[i];

    rep(i,0,n) ans[i][i]=arr[i];

    rep(len,1,n){
        int start=0;
        while(start+len<n){
            ans[start][start+len]=ans[start][start+len-1]^ans[start+1][start+len];
            start++;
        }
    }

    rep(i,0,n) maxx[i][i]=ans[i][i];

    rep(len,1,n){
        int start=0;
        while(start+len<n){
            maxx[start][start+len]=max(ans[start][start+len], 
                max(maxx[start][start+len-1], maxx[start+1][start+len]));
            start++;
        }
    }
    
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        l--;r--;
        cout << maxx[l][r] << endl;
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