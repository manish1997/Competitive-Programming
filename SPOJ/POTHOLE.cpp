// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define si(n) scanf("%d",&n)
#define si2(n1,n2) scanf("%d%d",&n1,&n2)
#define si3(n1,n2,n3) scanf("%d%d%d",&n1,&n2,&n3)
#define sll(n) scanf("%lld",&n)
#define sll2(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll3(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
#define pin(n) printf("%d\n",n)
#define mem(A,i) memset(A, i, sizeof(A))
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define P pair<int,int>
#define PP pair<P,int>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define newLine printf("\n")
#define pb push_back
#define INF 1e7
#define sieveMax 10001 //maximum for which u need primality test

//Sieve Start
vector<int> Prime;
void sieve(){
    bool neverMakeThisName[sieveMax];
    mem(neverMakeThisName,false);
    neverMakeThisName[0]=neverMakeThisName[1]=true;
    for(int i=4; i<sieveMax; i+=2) neverMakeThisName[i]=true;

    for(int i=3; i<=sqrt(sieveMax); i+=2)
        if(neverMakeThisName[i]==false) {
            for(int j=i*i; j<sieveMax; j+=i) neverMakeThisName[j]=true;
        }

    rep(i,0,sieveMax) if(neverMakeThisName[i]==false) Prime.pb(i);
}
//Sieve End
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
int arr[205][205];
int n,m; 
int from[205];
bool visited[205];
int find_aug_path(){
    queue<int> Q;
    Q.push(1);
    int sink=n;
    memset(from, -1, sizeof(from));
    memset(visited, false, sizeof(visited));
    visited[1]=true;
    bool whileBreak =false;
    while(!Q.empty() && !whileBreak){
        int cur=Q.front();
        Q.pop();
        for(int i=1; i<=n; i++){
            int next=i;
            if(!visited[next] && arr[cur][next]>0){
                visited[next]=true;
                Q.push(next);
                from[next]=cur;
                if(next==sink) {
                    whileBreak=true;
                    break;
                }
            }
            
        }
    }
    if(from[sink]==-1) return 0;
    int prev;
    int curr=sink;
    int capacity=1;
    curr=sink;
    while(true){
        prev=from[curr];
        if(prev==-1) break;
        arr[prev][curr]-=1;
        arr[curr][prev]+=1;
        curr=prev;
    };
    return (capacity==INT_MAX)?0:capacity;
}


int maxFlow(){
    int result=0;
    while(true){
        int path=find_aug_path();
        if(path==0) break;
        result+=path;
    }
    return result;
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    si(n);
    mem(arr,0);
    int m,node;
    rep(i,1,n){
        si(m);
        rep(j,0,m){
            si(node);
            if(i==1) arr[i][node]=1;
            else if(node==n) arr[i][node]=1;
            else arr[i][node]=20000;
        }
    }
    pin(maxFlow());
}

int main(){
    int t=1; si(t);
    while(t--){
        solve();
    }
    return 0;
}