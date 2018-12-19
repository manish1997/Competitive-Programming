#include <bits/stdc++.h>
using namespace std;
#define MAX 105
int n,m;
#define ll long long
ll dp[MAX][MAX];
ll arr[MAX][MAX];

bool valid(int i, int j){
    // cout << i << " " << j <<" " << n << " " << m << " " << (i>=0 && i<n && j>=0 && j<m)<< endl;
    return (i>=0 && j>=0 && i<n && j<m);
}
ll helper(int x, int y){
    if(valid(x,y)==false) return INT_MIN;
    // cout << x << " " << y <<endl;
    if(dp[x][y]!=-1) return dp[x][y];
    ll ans=0;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0 && j==0) continue;
            int nx=x+i;
            int ny=y+j;
            if(valid(nx,ny)==false || arr[nx][ny]<=arr[x][y]) continue;
            ans=max(ans, helper(nx,ny));
        }
    }
    return dp[x][y]=(ans+1);
}
int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    ll ans=0;
    memset(dp,-1,sizeof(dp));
    cout << helper(0,0) << endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         // cout << helper(i,j) << endl;
    //         ans=max(ans, helper(i,j));
    //     }
    // }
    cout << ans << endl;


    return 0;
}