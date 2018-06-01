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
#define MAX 200005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
int n,m;
// int SEG[62][4*MAX];
int BIT[MAX];
set<int> rems[62];


void update(int idx, int val){
  while(idx<=n){
    BIT[idx]+=val;
    idx+=(idx&-idx);
  }
}

int query(int idx){
  int ans=0;
  while(idx>0){
    ans+=BIT[idx];
    idx-=(idx&-idx);
  }
  return ans;
}

int gettrue(int idx){
  int start=1;
  int end=n;
  while(start<=end){
    int mid=(start+end)>>1;
    if(query(mid)>=idx) end=mid-1;
    else start=mid+1;
  }
  return start;
}
char tochar(int x){
  if(x<26) return 'A'+x;
  if(x<52) return 'a'+x-26;
  return '0'+x-52;
}
int toint(char x){
  if(x<='9') return x-'0'+52;
  if(x<='Z') return x-'A';
  return x-'a'+26;
}
void solve(){
  //solve the problem. You can and you will :) give your best shot..
  cin>>n>>m;
  string s;cin>>s;

  rep(i,1,s.length()+1){
    update(i,1);
    rems[toint(s[i-1])].insert(i);
  }
  while(m--){
    int l,r,X;
    char x;cin>>l>>r>>x;
    X=toint(x);
    l=gettrue(l);
    r=gettrue(r);
    auto it=rems[X].lower_bound(l);
    for(;it!=rems[X].end();){
      if((*it)<=r){
        update(*it,-1);
        it=rems[X].erase(it);
      }
      else
        break;
    }
  }
  string ans="";
  rep(i,1,n+1){
    if(query(i)-query(i-1)>=1){
      ans.pb(s[i-1]);
    }
  }
  cout<<ans << endl;
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