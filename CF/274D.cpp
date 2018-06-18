//https://codeforces.com/blog/entry/15296?#comment-203606
//offiline conncetivity of a graph
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
ll arr[MAX];
ll dp[MAX+1];

void solve(){
  //solve the problem. You can and you will :) give your best shot..
    int t,k;
    cin>>t>>k;
    arr[0]=1;
    rep(i,1,MAX){
        //on adding one length to the current eatery
        //we can either eat W
        //where we have to fix all past k-1 as W) and 
        //add arr[i-k] (valid solutions of length i-k)
        //or we can always eat R
        //where we only need to add all solution of (i-1)
        if(i>=k){
            arr[i]=(arr[i-1]+arr[i-k])%mod;
        }
        else{
            arr[i]=arr[i-1];
        }
    }

    rep(i,1,MAX){
        arr[i]=(arr[i-1]+arr[i])%mod;
    }
    while(t--){
        int a,b;cin>>a>>b;
        cout<<(arr[b]-arr[a-1]+mod)%mod<<endl;
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