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
#define plln(n) printf("%i64d\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define S second
#define F first
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define newLine printf("\n")
int n;
int main(){
	int t; si(t);
	while(t--){
		si(n);
		if((n%2)==0){
			rep(i,1,n+1){
				if(i%2) pis(i+1);
				else pis(i-1);
			}
		}
		else{
			rep(i,1,n-2){
				if(i%2) pis(i+1);
				else pis(i-1);
			}
			pis(n-1);
			pis(n);
			pis(n-2);
		}
		newLine;
	}
	return 0;
}
