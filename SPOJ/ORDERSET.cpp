//#include<bits/stdc++.h>
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
#define si2(n1,n2) scanf("%d%d",&n1,&n2)
#define si3(n1,n2,n3) scanf("%d%d%d",&n,&n2,&n3)
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
struct node{
    int val;
    int r,l;
    node* right;
    node* left;
    node* par;
    node(int vall,int rr,int xx): val(vall), r(rr), l(xx), par(NULL),right(NULL), left(NULL){}
};
void reset(){
    //check if your logic is correct but still wrong answer

}

void ins(int a, node* root, node* parent){
    if(root==NULL || root.val==a) {
        if(!root) root=new node(a,0,0);
        return;
    }
    if(root.val>a) ins(a,root->left, root);
    else ins(a,root->right, root);

}
void solve(){
    reset();
    //solve the problem. You can and you will :) give your best shot..
    node* root=NULL;
    int q; si(q);
    while(q--){
        char ch; cin >> ch;
        int t; si(t);
        if(ch=='I') ins(t, NULL);
        else if(ch=='D') del(t);
        else if(ch=='K') kth(t);
        else coun(t);
    }
    
}

int main(){
    int t=1; si(t);
    while(t--){
        solve();
    }
    return 0;
}