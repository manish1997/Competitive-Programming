//CAN FIND BFS FROM A SOURCE TO ALL NODES IN A DIRECTED GRAPH
// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define si(n) scanf("%d",&n)
#define si2(n1,n2) scanf("%d%d",&n1,&n2)
#define si3(n1,n2,n3) scanf("%d%d%d",&n1,&n2,&n3)
#define sll(n) scanf("%lld",&n)
#define sll2(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll3(n1,n2,n3) scanf("%lld%lld%lld",&n,&n2,&n3)
#define pin(n) printf("%d\n",n)
#define mem(A,i) memset(A, i, sizeof(A))
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define newLine printf("\n")
#define pb push_back

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
int f,source,u,destination,d;
bool visited[1000005];
void reset(){
    //check if your logic is correct but still wrong answer

}
void solve(){
    //reset();
    //solve the problem. You can and you will :) give your best shot..
    si3(f,source,destination);si2(u,d);
    if(source==destination){
        pin(0); return;
    }
    visited[source]=true;
    queue<pair<int,int> > Q;
    Q.push({0,source});
    while(!Q.empty()){
        int node=Q.front().s;
        int dist=Q.front().f;
        Q.pop();
        if(node==destination) {
            pin(dist);
            return;
        }
        int arr[2];
        arr[0]=(node-d>=1)?node-d:-1;
        arr[1]=(node+u<=f)?node+u:-1;
        for(int i=0; i<2; i++){
            if(arr[i]!=-1 && visited[arr[i]]==false){
                visited[arr[i]]=true;
                Q.push({dist+1,arr[i]});
            }
        }
    }
    printf("use the stairs\n");
}

int main(){
    int t=1; //si(t);
    while(t--){
        solve();
    }
    return 0;
}