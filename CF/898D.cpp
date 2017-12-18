// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
// #define pi 3.1415926535897
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
#define MAX 1000002
#define s second
#define f first
#define newLine printf("\n")
#define pb push_back
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


int SEG[4*MAX];
int lazy[4*MAX];

int n,m,k;
int arr[MAX];

void build(int node, int start, int end){
	if(start==end){
		if(arr[start]==1){
			SEG[node]=1;
		}
		return;
	}
	else{
		int  mid=(start+end)>>1;
		build(node<<1, start, mid);
		build(1+(node<<1),mid+1, end);
		SEG[node]=SEG[1+(node<<1)]+SEG[node<<1];
		return;
	}
}
void belazy(int node, int start, int end){
	if(lazy[node]){
		SEG[node]=0;
		if(start!=end){
			lazy[2*node]=1;
			lazy[2*node+1]=1;
		}
		lazy[node]=0;
		return;
	}
}
void update(int node, int start, int end, int l, int r){
	belazy(node, start, end);
	if(start>end || l>end || r<start) return;
	if(start>=l && end<=r){
		SEG[node]=0;
		if(start!=end){
			lazy[2*node]=1;
			lazy[2*node+1]=1;
		}
		return;
	}
	int mid=(start+end)>>1;
	if(l>mid) update(2*node+1, mid+1, end, l, r);
	else if(r<=mid) update(2*node, start, mid, l, r);
	else{
		update(2*node+1, mid+1, end, l, r);
		update(2*node, start, mid, l, r);
	}
	SEG[node]=SEG[1+(node<<1)]+SEG[node<<1];
	return;
}
int query(int node, int start, int end, int l, int r){
	belazy(node, start, end);
	if(start>end || l>end || r<start) return 0;
	if(start>=l && end<=r){
		return SEG[node];
	}
	int mid=(start+end)>>1;
	if(l>mid) return query(2*node+1, mid+1, end, l, r);
	else if(r<=mid) return  query(2*node, start, mid, l, r);
	else{
		return (query(2*node+1, mid+1, end, l, r)+query(2*node, start, mid, l, r));
	}
}

void solve(){
	cin >> n >> m >> k;
	rep(i,0,n){
		int x; cin >> x;
		arr[x]=1;
	}
	build(1,0,MAX-2);
	int ans=0;
	rep(i,1,MAX-m){
		int check=query(1,0,MAX-2, i, i+m-1);
		if(check<k) continue;
		check=check-k+1;
		ans+=check;
		int start=i;
		int end=i+m-1;
		while(start<=end){
			int mid=(start+end)>>1;
			int till=query(1,0,MAX-2, mid, i+m-1);
			if(till>=check) start=mid+1;
			else end=mid-1;
		}
		//start-1 has exact k values
		update(1,0,MAX-2, start-1,i+m-1);
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	//si(t);
	while(t--)solve();
    return 0;
}  