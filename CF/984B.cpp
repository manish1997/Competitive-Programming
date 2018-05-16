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
int n,m;
bool valid(int x, int y){
    return (x>=0 && y>=0 && x<n && y<m);
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n>>m;
    char arr[n][m];
    rep(i,0,n) rep(j,0,m) cin>>arr[i][j];
    
    rep(i,0,n){
        rep(j,0,m){
            if(arr[i][j]=='*') continue;
            int limit=0;
            if(arr[i][j]!='.') limit=arr[i][j]-'0';
            int cnt=0;
            for(int x=-1; x<=1; x++){
                for(int y=-1; y<=1; y++){
                   if(x==0 && y==0) continue;
                   if(valid(i+x, j+y)){
                    if(arr[i+x][j+y]=='*') cnt++;
                   }
                }
            }
            if(cnt!=limit){
                cout <<"NO\n";
                return;
            }
        }
    }
    cout <<"YES\n";
    return;

}
int main(){
    // fast_cin;
    int t=1; 
    while(t--){
        solve();
    }
    return 0;
}