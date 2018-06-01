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

void solve(){
  //solve the problem. You can and you will :) give your best shot..
  int x,y;
  cin>>x>>y;
  //x^y < y^x
  //ylogx < xlogy
  //logx/x < logy/y
  //f(x)=logx/x
  //f(2)=log2/2
  //f(3)=log3/3
  ///f(4)=f(2)
  //f(5)...........decreasing

  if(x==y){
    //case when 2 are equal or 2,4  4,2
    cout <<"=";
  }
  else if(x==1){
    cout<<"<";
  }
  else if(y==1){
    cout<<">";
  }
  else if((x+y)==6){
    //2,4 only pair of remamining i/ps to have sum as 6
    cout<<"=";
  }
  else if(x==3){
    cout<<">";
  }
  else if(y==3){
    cout<<"<";
  }
  else if(x<y){
    cout<<">";
  }
  else{
    cout<<"<";
  }
  return;
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