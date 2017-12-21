//TODO
#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define si(n) scanf("%d",&n)
#define si2(n1,n2) scanf("%d%d",&n1,&n2)
#define sll(n) scanf("%lld",&n)
#define sll2(n1,n2) scanf("%lld%lld",&n1,&n2)
#define tr1(n) printf("%d\n",n)
#define tr2(n1,n2) printf("%d%d\n",n1,n2)
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define pb push_back

void solve(){
    //solve the problem. You can and you will :) give your best shot..
	int n; cin >> n;
	repDown(i,8,0){
		int maxx=5*pow(10,i);
		if(n>=maxx){
			cout << i << endl;
			int add=1;
			if(n>=pow(10,i+1)-1) add=0;
			cout <<(n-maxx+add)<<endl;
			return;
		}
	}
	cout<<((n*(n-1))/2);
    return;
}

int main(){
    int t=1; 
    //si(t);
    while(t--){
        solve();
    }
    return 0;
}