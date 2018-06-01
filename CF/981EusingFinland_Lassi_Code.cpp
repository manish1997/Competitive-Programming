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
#define MAX 10005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int>  SEG[4*MAX];
bitset<MAX> ans;
int n,q;
void insert(int node, int start, int end, int l, int r, int val){
  if(start>end || l>end || r<start) return;
  if(start>=l && end<=r){
    SEG[node].pb(val);
    return;
  }
  int mid=(start+end)>>1;
  insert(2*node, start, mid, l, r, val);
  insert(2*node+1, mid+1, end, l, r, val);
}
void dfs(int node, int start, int end, bitset<MAX> temp){
  if(SEG[node].size()){
    rep(i,0,SEG[node].size()){
      temp|=(temp<<SEG[node][i]);
    }
  }
  if(start==end){
    ans|=temp;
    return;
  }
  int mid=(start+end)>>1;
  dfs(node*2, start, mid, temp);
  dfs(node*2+1, mid+1, end, temp);
}
void solve(){
  //solve the problem. You can and you will :) give your best shot..
  
  cin>>n>>q;
  rep(i,0,q){
    int li,ri,xi;cin>>li>>ri>>xi;
    insert(1,1,n,li,ri,xi);
  }
  bitset<MAX> temp;
  rep(i,0,MAX){
    temp[i]=ans[i]=0;
  }
  temp[0]=1;
  dfs(1,1,n,temp);
  vector<int> x;
  rep(i,1,n+1) if(ans[i]==1) x.pb(i);
  tr1(x.size());
  rep(i,0,x.size()) cout <<x[i] <<" ";
  cout<<endl;
  
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