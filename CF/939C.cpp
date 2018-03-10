#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define mod 1000000007
#define MAX 1000005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
ll arr[210004];
ll n;
ll s,f;
ll pre[210005];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n;
    rep(i,1,n+1) cin>>arr[i];
    rep(i,n+1,2*n+1) arr[i]=arr[i-n]; //put n more days to see circularly
    
    pre[0]=0;
    rep(i,1,2*n+1) {
        pre[i]=arr[i]+pre[i-1]; // prefix sum upto all
    }
    cin>>s>>f;
    ll maxx=f-s; //max continous hours we can have contest
    ll start; 
    ll curr=0, anss=n+1;
    rep(i,1,n+1){
        // fix i as first planet having start of contest as s hour, all next maxx-1 planets
        //will also have contest. check what max players we can have for competition
        if(curr<(pre[i+maxx-1]-pre[i-1])){
            curr=pre[i+maxx-1]-pre[i-1];
            start=i;
        }
    }
    rep(i,1,n+1){
        if(curr==(pre[i+maxx-1]-pre[i-1])){
            if(s-i+1<=0){
                anss=min(anss, s-i+1+n);
            }
            else anss=min(anss, s-i+1);
        }
    }
    cout << anss << endl;
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