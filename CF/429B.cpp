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
#define MAX 1003
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

int n,m;
ll first[MAX][MAX][4];
ll second[MAX][MAX][4];
ll arr[MAX][MAX];
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n>>m;
    rep(i,1,n+1){
        rep(j,1,m+1){
            cin>>arr[i][j];
        }
    }
    rep(i,1,n+1){
        rep(j,1,m+1){
            first[i][j][0]=arr[i][j]+max(first[i-1][j][0],first[i-1][j][1]);
            first[i][j][1]=arr[i][j]+max(first[i][j-1][0],first[i][j-1][1]);
        }
    }
    repDown(i,n,1){
        repDown(j,m,1){
            first[i][j][2]=arr[i][j]+max(first[i+1][j][2],first[i+1][j][3]);
            first[i][j][3]=arr[i][j]+max(first[i][j+1][2],first[i][j+1][3]);
        }
    }

    repDown(i,n,1){
        rep(j,1,m+1){
            second[i][j][0]=arr[i][j]+max(second[i][j-1][0],second[i][j-1][1]);
            second[i][j][1]=arr[i][j]+max(second[i+1][j][0],second[i+1][j][1]);
        }
    }
    rep(i,1,n+1){
        repDown(j,m,1){
            second[i][j][2]=arr[i][j]+max(second[i-1][j][2],second[i-1][j][3]);
            second[i][j][3]=arr[i][j]+max(second[i][j+1][2],second[i][j+1][3]);
        }
    }
    ll ans=0;
    rep(i,2,n){
        rep(j,2,m){
            //assuming they meets at i,j

            ll temp=first[i][j][0]+second[i][j][0];
            ll temp2=first[i][j][2]+second[i][j][3];
            ans=max(ans,temp+temp2-4*arr[i][j]);
            temp=second[i][j][1]+first[i][j][1];
            temp2=first[i][j][3]+second[i][j][2];
            ans=max(ans,temp+temp2-4*arr[i][j]);
        }
    }
    cout << ans << endl;

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