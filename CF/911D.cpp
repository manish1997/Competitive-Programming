#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    double n,a,b,aPlates,bPlates,minB,minA;
    double ratio;
    cin>>n>>a>>b;
    ratio=n/(a+b);
    // cout<<ratio;
    aPlates=round(ratio*a);
    bPlates=round(ratio*b);
    if(aPlates==0||bPlates==0){
      if(aPlates==0)
      {
        aPlates=1;
        bPlates=n-1;
      }
      else if(bPlates==0){
        bPlates=1;
        aPlates=n-1;
      }
    }
    else{
    bPlates=round(ratio*b);
    aPlates=round(ratio*a);
    }
    minA=floor(a/aPlates);
    minB=floor(b/bPlates);
    // cout<<"Aplates="<<aPlates<<endl;
    // cout<<"bplates="<<bPlates<<endl;
    // cout<<"minA="<<minA<<endl;
    // cout<<"minB="<<minB<<endl;
    cout<<min(minA,minB);
  return 0;
}