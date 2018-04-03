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
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
ll pre[MAX];
ll suff[MAX];
ll arr[MAX];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;cin>>n;rep(i,1,n+1)cin>>arr[i];
    arr[0]=arr[n+1]=0;
    pre[0]=pre[n+1]=0;
    suff[0]=suff[n+1]=0;
    rep(i,1,n+1) pre[i]=pre[i-1]+arr[i];
    repDown(i,n,1) suff[i]=suff[i+1]+arr[i];
    
    
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