#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;
#define ll long long
#define si(n) cin >> n
#define sll(n) cin >> n
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%i64d\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define S second
#define F first
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define newLine printf("\n")
int B,R,M,E;
void inp(){
	string s;
	cin >> s;
	if(s[0]=='B') cin >> B;
	else if(s[0]=='R') cin >> R;
	else if(s[0]=='M') cin >> M;
	else cin >> E;
}
int main(){
	cout << sqrt(1000050) << endl; 
	int t; si(t);
	while(t--){
		rep(i,0,4){
			inp();
		}
		if(B>E && R<M){
			printf("Barcelona\n");
		}
		else printf("RealMadrid\n");
	}
	return 0;
}