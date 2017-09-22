#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
#define pi 3.1415926535897
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
void reset(){
    //check if your logic is correct but still wrong answer

}
int n;
pair<int,int> findM(vector<int> V){
    int maxx=-1;
    int ind=-1;
    rep(i,0,V.size()) if(maxx<=V[i]){
        ind=i;
        maxx=V[i];
    }
    return {maxx,ind};
}
int solve(vector<int> V, int m){
    int toF=V[m];
    pair<int,int> temp=findM(V);
    if(temp.f==toF){
        int ans=0;
        rep(i,0,temp.s+1){
            if(V[i]==temp.f) ans++;
            if(i==m) return ans;
        }

    }
    else{
        int ind=-1;
        vector<int> VV;
        rep(i,temp.s+1,V.size()){
            // if(i>temp.s){
                VV.push_back(V[i]);
                if(i==m){
                    ind=VV.size()-1;
                }
            // }
        }
        int ans=0;
        rep(i,0,temp.s){
            if(V[i]!=temp.f){
                VV.pb(V[i]);
            }
            else ans++;
            if(i==m){
                    ind=VV.size()-1;
            }
        }
        return (ans+1+solve(VV,ind));
    }
}
void solve(){
    reset();
    //solve the problem. You can and you will :) give your best shot..
    int m;
    vector<int> V;
    si(n);
    si(m);
    priority_queue<int> PQ;
    queue<pair<int,int> > Q;
    int x;
    rep(i,0,n) {
        si(x);
        V.pb(x);
        PQ.push(V[i]);
        Q.push({V[i],i});
    }

    //method 1... without queue and priority queue
    //pin(solve(V,m));

    //method 2...
    int ans=0;
    pair<int,int> t;
    int temp;
    while(true){
        temp=PQ.top();
        PQ.pop();

        while(Q.front().f!=temp){
            pair<int,int> t=Q.front();
            Q.pop();
            Q.push(t);
        }
        t=Q.front();
        Q.pop();
        if(m==t.s){
            break;
        }
        ans++;
    }
    pin(ans+1);

    
}

int main(){
    int t; si(t);
    while(t--){
        solve();
    }
    return 0;
}