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
#define P pair<int,int>
#define PP pair<P,int>
#define mod 1000000007
#define MAX 100005
#define block 100
#define newLine printf("\n")

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll n; sll(n);
    ll odd=0;
    ll even=0;
    rep(i,0,n) {
    	ll x; sll(x);
    	if(x%2==0){
    		even++;
    	}
    	else{
    		odd++;
    	}
    }
    if(odd==0){
    	printf("Second\n");
    }
    else{
    	printf("First\n");
    }


    return 0;
}