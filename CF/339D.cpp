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
#define MAX (1<<17)+5
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

int SEG[4*MAX];
int power[MAX];
int n;
int arr[MAX];

void build(int node, int start, int end){
    if(start==end){
        SEG[node]=arr[start];
        return;
    }
    int mid=(start+end)>>1;
    build(node*2, start, mid);
    build((node*2)+1, mid+1, end);
    if(power[end-start+1]%2) SEG[node]=(SEG[2*node]|SEG[2*node+1]);
    else SEG[node]=(SEG[2*node]^SEG[2*node+1]);
}

void update(int node, int start, int end, int idx){
    if(start>idx || end<idx) return;
    if(start==end){
        SEG[node]=arr[start];
        return;
    }
    int mid=(start+end)>>1;
    if(idx<=mid){
        update(node*2, start, mid, idx);
    }
    else{
        update(2*node+1, mid+1, end, idx);
    }
    if(power[end-start+1]%2) SEG[node]=(SEG[2*node]|SEG[2*node+1]);
    else SEG[node]=(SEG[2*node]^SEG[2*node+1]);
}


void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int cnt=0;
    for(ll j=1; j<MAX; j*=2LL){
        power[j]=cnt++;
    }
    int m;
    cin>>n>>m;
    rep(i,0,1<<n) cin>>arr[i];
    build(1,0,(1<<n)-1);
    while(m--){
        int idx,val;cin>>idx>>val;
        arr[idx-1]=val;
        update(1,0,(1<<n)-1, idx-1);
        cout<<SEG[1]<<endl;
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