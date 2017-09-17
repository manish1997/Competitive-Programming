#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define mem(A,i) memset(A, i, sizeof(A))
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define S second
#define F first
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define newLine printf("\n")
 
ll gcd ( ll  a, ll b ){
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}
string inputString(){
    string i="";
    int temp=getchar();
    while(temp<'a'||temp>'z')
        temp=getchar();
    while(temp>='a'&&temp<='z')
    {
        i+=(char)temp;
        temp=getchar();
    }
    return i;
}
 
ll expo(ll x, ll n, ll m){
    if(n==0) return 1;
    ll temp=expo(x,n/2,m);
    temp = ((temp%m)*(temp%m))%m;
    if(n%2!=0) temp = ((temp%m)*(x%m))%m;
    return temp;
}
 
long long add(long long &x, long long y){
        x=x+y;
        x%=mod;
        if(x<0) x+=mod;
        return x;
}
 
 
int main(){
    int t=1;
    si(t);
    while(t--){
        int n; si(n);
        rep(i,1,n+1) cout << 2*i << " ";
        newLine;
        // int cnt=0;
        // ll median=0;
        // for(int i=1; i<=n; i++){
        //     for(int j=i; j<=n; j++){
        //         int temp=(arr[((i+j)/2)]);
        //         if(((j-i+1)%2)==0){
        //             temp+=(arr[((i+j)/2)+1]);
        //             temp/=2;
        //         }
        //         median+=temp;
        //         cnt++;
        //     }
        // }
        // // << (median/(double)cnt) << endl;
        // if((median/(double)cnt)<=(n+1) && (median/(double)cnt)>=(n-1)) cout << "true" << endl;
        // else cout << "false" <<endl;
        
    }
    return 0;
} 