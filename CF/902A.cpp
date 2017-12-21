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
pair<int,int> arr[101];
int a[1000];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
	int n,m;
	cin >> n >> m;
	rep(i,0,n) {
		cin >> arr[i].f >> arr[i].s;
		if(i==0 && arr[i].f>0){
			printf("no\n");
			return;
		}
	}

	int currmax=0;
	int x=0;
	while(x<n){
		if(arr[currmax].s<arr[x].f){
			printf("no\n");
			return;
		}
		if(arr[x].s>arr[currmax].s) currmax=x;
		if(arr[currmax].s>=m) {
			printf("yes\n");
			return;
		}
		x++;
	}
	printf("no\n");
    
}

int main(){
    int t=1; 
    //si(t);
    while(t--){
        solve();
    }
    return 0;
}