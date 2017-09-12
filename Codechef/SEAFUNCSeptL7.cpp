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
string str[100];
int done;
int total;
int extra;
void solve(string s, vector<vector<int> > &V, int j){
  s.push_back('0');
  int start=0;
  rep(i,0,s.length()){
    if(s[i]=='1') {
      done++;
      continue;
    }
    if(s[i]=='0' && i==start) {
      start=i+1;
      continue;
    }
    V.push_back({0,1,0,1,0,1,j+1,start+1, i});
    start=i+1;
    if(total-done<=extra) break;
  }
  
  
}
int calculate(string s){
  int ans=0;
  rep(i,0,s.length()) if(s[i]=='1') ans++;
  return ans;
}
int changes(string s){
  s.push_back('0');
  s="0"+s;
  int start=0;
  int ans=0;
  rep(i,0,s.length()){
    if(s[i]=='1') {
      continue;
    }
    if(s[i]=='0' && i==start) {
      start=i+1;
      continue;
    }
    ans++;
    start=i+1;
  }
  return ans;
}
int main() {
  cout << pow(2,15) <<endl;
  int t; si(t);
  while(t--){
    vector<vector<int> > V;
    int n; si(n);
    total=0;
    rep(i,0,n) {
      cin >> str[i];
      total+=calculate(str[i]);
    }
    if(total<=100){
      pin(0);
      continue;
    }
    done=0;
    priority_queue<pair<int,pair<int,int> > > PQ;
    rep(j,0,n){
      string temp="";
      //if((total-done)>100){
        rep(i,0,n){
          temp.push_back(str[i][j]);
        }
        int t2=changes(temp);
        PQ.push({t2,{j,n-calculate(temp)}});
       // solve(temp,V,j);
      //}
    }
    extra=0;
    bool visited[n];
    memset(visited,false,sizeof(visited));
    while(!PQ.empty()){
      if(PQ.top().f!=0 && extra+PQ.top().s.s<=100){
        extra+=PQ.top().s.s;
        visited[PQ.top().s.f]=true;
        V.push_back({0,1,0,1,0,1,1+PQ.top().s.f,1,n});
      }
      PQ.pop();
    }
    //cout << total << endl;
    extra=100-extra;
    rep(j,0,n){
      if(visited[j]==true)continue;
      string temp="";
      if((total-done)>extra){
        rep(i,0,n){
          temp.push_back(str[i][j]);
        }
        solve(temp,V,j);
      }
    }




    cout << (V.size()) << endl;
    rep(i,0,V.size()){
      rep(j,0,V[i].size()) pis(V[i][j]);
      cout << endl;
    } 
  }
  return 0;
} 