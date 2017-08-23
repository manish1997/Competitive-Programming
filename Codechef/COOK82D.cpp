//TODO: SQRT Decomposition will give TLE, couldn't get hashing approach
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
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
#define newLine printf("\n")
#define BLOCK 1000
#define MAX 1000050
#define MAXN 100005
pair<ll,ll> arr[MAX];
ll n,m;
struct node {
	int L, R, i;
}q[MAX];
unordered_map<int,bool> M;
ll cnt[MAXN];
bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		return x.L/BLOCK < y.L/BLOCK;
	}
	return x.R < y.R;
}
bool ans;
bool answer[MAX];

int main() {
	sll(n); sll(m);
	for(int i=1; i<=m; i++){
		ll x,y; sll(x); sll(y);
		
		cnt[x]++;
		if(cnt[x]%2){
			M[x]=true;
			ans=false;
		}
		else{
			M.erase(M.find(x));
			if(M.size()==0) ans=true;
		}
		cnt[y]++;
		if(cnt[y]%2){
			M[y]=true;
			ans=false;
		}
		else{
			M.erase(M.find(y));
			if(M.size()==0) ans=true;
		}
		if(ans) answer[i]=1;
		else answer[i]=0;
		//cout << x << " " << cnt[x] << " " << y << " " << cnt[y]<< endl;
		cout << answer[i] << " ";
	}
	answer[0]=0;
	cout << endl;
	int qq;
	si(qq);
	for(int i=1; i<=qq; i++){
		si(q[i].L); si(q[i].R);
		if(answer[q[i].L-1]==answer[q[i].R]) printf("Yes\n");
		else printf("No\n");
	}
}