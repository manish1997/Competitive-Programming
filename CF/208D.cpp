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
#define MAX 55
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
ll n;
vector<ll> V(5);
ll arr[MAX];
vector<ll> ans(5,0);

void solve(){
  //solve the problem. You can and you will :) give your best shot..
    cin>>n;
    rep(i,0,n){
        cin>>arr[i];
    }
    rep(i,0,5){
        cin>>V[i];
    }
    ll curr=0;
    rep(i,0,n){
        curr+=arr[i];
        if(curr>=V[0]){
            repDown(j,4,0){
                if(curr>=V[j]){
                    ans[j]+=curr/V[j];
                    curr%=V[j];
                }
            }
        }
    }
    rep(i,0,5) cout<<ans[i]<<" ";
    cout<<endl;
    cout<<curr;

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