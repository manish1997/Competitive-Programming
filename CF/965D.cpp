#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define MAX 500005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
int A[MAX];
int reach[MAX];
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int w,l;
    cin>>w>>l;
    if(l==1){
        int ans=2e9;
        rep(i,0,w-1){
            int x;cin>>x;
            ans=min(x,ans);
        }
        cout<<ans<<endl;
        return;
    }
    rep(i,1,w){
        cin>>A[i];
        if(i<=l) reach[i]=A[i];
    }
    A[w]=2e9;
    ll ans=0;
    int ptr1=1;
    int ptr2=l+1;
    while(ptr2<=w){
            ptr1=max(ptr1, ptr2-l);
            if(reach[ptr1]+reach[ptr2]<=A[ptr2]){
                reach[ptr2]+=reach[ptr1];
                reach[ptr1]=0;
                ptr1++;
            }
            else{
                reach[ptr1]-=(A[ptr2]-reach[ptr2]);
                reach[ptr2]=A[ptr2];
                ptr2++;
            }
            if(ptr1==ptr2){
                ptr2++;
            }
    }
    cout<<reach[w] << endl;
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