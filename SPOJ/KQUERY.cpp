//#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <queue>
#include <algorithm>
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
int n;
int ans[200002];
int BIT[30005];
pair<int,int> arr[30001];

void update(int idx){
    while(idx<=n){
        BIT[idx]+=1;
        idx+=(idx&-idx);
    }
}
int query2(int idx){
    int answer=0;
    while(idx>0){
        answer+=BIT[idx];
        idx-=(idx&-idx);
    }
    return answer;
}


struct query{
    int l,r,k,ind;
} Q[200002];

bool comp(query A, query B){
    return A.k>B.k;
}


void solve(){
    //solve the problem. You can and you will :) give your best shot
    si(n);
    rep(i,1,n+1){
        si(arr[i].f);
        arr[i].s=i;
    }
    sort(arr+1, arr+1+n);
    int q; si(q);
    rep(i,0,q){
        si3(Q[i].l, Q[i].r, Q[i].k);
        Q[i].ind=i;
    }
    sort(Q,Q+q,comp);
    int endptr=n;
    rep(i,0,q){
        while(endptr>0 && arr[endptr].f>Q[i].k){
            update(arr[endptr].s);
            endptr--;
        }
        ans[Q[i].ind]=query2(Q[i].r)-query2(Q[i].l-1);
    }
    rep(i,0,q) pin(ans[i]);
}

int main(){
    int t=1; // si(t);
    while(t--){
        solve();
    }
    return 0;
}