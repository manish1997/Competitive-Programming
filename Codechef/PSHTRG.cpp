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
pair<int,int> SEG[4*MAX];

int n,q;
void update(int node, int start, int end, int idx, int val){
    if(start==end){
        SEG[node]={val,idx};
        return;
    }
    else{
        int mid=(start+end)>>1;
        if(idx<=mid) update(node*2, start, mid, idx, val);
        else update(2*node+1, mid+1, end, idx, val);
        if(SEG[2*node].f>=SEG[2*node+1].f) SEG[node]=SEG[2*node];
        else SEG[node]=SEG[2*node+1];
        return;
    }
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n>>q;
    rep(i,0,n){
        int x;cin>>x;
        update(1,0,n-1,i,x);
    }
    while(q--){
        int type;cin>>type;
        if(type==1){
            int idx,val;cin>>idx>>val;
            update(1,0,n-1,idx,val);
        }
        else{
            int l,r;
            cin>>l>>r;
            vector<pair<int,int> > toRestore;
            if(r-l+1<3){
                cout << 0 << endl;
                continue;
            }

            vector<int> top3;
            rep(i,0,3) {
                pair<int,int> curr=query(1,0,n-1,l,r);
                top3.pb(curr.f);
                update(1,0,n-1,curr.s,0);
                toRestore.pb(curr);
            }
            if(top3[0]+top3[1]>top3[2]){
                
            }
        }
    }

    
    
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