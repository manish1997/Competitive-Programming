//Couldn't solve for k=2 and k=3 in contest.
//solved till now for k=2, used this as reference https://discuss.codechef.com/questions/108250/sumcube-editorial/111119
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define s second
#define f first
#define mod 1000000007
#define MAX 100002
ll n,m,k;
vector<int> adj[100002];
ll power[MAX];
vector<int> Added;
ll ANS=0;
void getAns(){
  unordered_map<int,bool> M;
  ll ans=0;
  rep(i,0,Added.size()){
    rep(j,0,Added.size()){
      if(j==i) continue;
      if(find(adj[Added[i]].begin(),adj[Added[i]].end(),Added[j])!=adj[Added[i]].end()) ans++;
    }
  }
  ans/=2;
  ans%=mod;
  if(k==2) ans=(ans*ans)%mod;
  if(k==3) ans=(ans*((ans*ans)%mod))%mod;
  ANS=(ANS+ans)%mod;
}
void solve(int i){
  if(i==n){
    getAns();
    return;
  }
  solve(i+1);
  Added.push_back(i);
  solve(i+1);
  Added.pop_back();
  return;

}


ll add(ll &x, ll y){
  x=(x+y)%mod;
  while(x<0) x+=mod;
  return x;
}

int main() {
//  cout << 15*power(2,15)*225 << endl; //worst case in BRUTE FORCE
  int t; si(t);
  power[0]=1;
  rep(i,1,MAX) {

    power[i]=(power[i-1]*2)%mod;
  }
  while(t--){
    sll(n); sll(m);sll(k);
    ANS=0;
    rep(i,0,n+1) adj[i].clear();
    rep(i,0,m){
      int a,b;si(a);si(b);
      a--;b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    if(k==1){
      ANS=m;
      ANS=(ANS*power[n-2])%mod;
      cout << ANS << endl;
      continue;
    }

    // //BRUTE FORCE FOR n<=15
    if(n<=15){
      Added.clear();
      solve(0);
      cout << ANS <<endl;
      continue;
    }
    // //END BRUTE FORCE FOR n<=15

    if(k==2){
      ANS=m;
      ANS=(ANS*power[n-2])%mod;
      ll temp=0;
      if(n>=3){
        rep(i,0,n){
          add(temp,((ll)adj[i].size()*((ll)adj[i].size()-1))%mod);
        }
        temp=(temp*power[n-3])%mod;
        add(ANS,temp);
      }
      if(n>=4){
        temp=(m*m)%mod;
        add(temp,m);
        rep(i,0,n){
          add(temp, -1LL*((ll)adj[i].size()*(ll)adj[i].size()));
        }
        temp=(temp*power[n-4])%mod;
        add(ANS, temp);
      }
      plln(ANS);
      continue;
    }
    if(k==3){
      //wait
      cout << "TODO" << endl;
    }

  }
  return 0;
} 