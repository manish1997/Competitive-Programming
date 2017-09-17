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
#define plln(n) printf("%lld\n",n)
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
//int n;
ll dist(ll x1, ll y1, ll x2, ll y2){
	ll temp= (x1-x2)*(x1-x2);
	temp += ((y1-y2)*(y1-y2));
	//cout << temp << endl;
	return temp;
}
bool collinear(ll ax, ll ay, ll bx, ll by, ll cx, ll cy){
	ll t=ax*(by-cy)+bx*(cy-ay)+cx*(ay-by);
	return (t!=0);
}
int main(){
	ll ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	if(collinear(ax,ay,bx,by,cx,cy) && dist(ax,ay,bx,by)==dist(cx,cy,bx,by)) printf("Yes\n");
	else printf("No\n");
	return 0;
}