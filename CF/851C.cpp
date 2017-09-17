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
#define PI 3.14159265

int arr[5][1000];

int main(){
	int n; si(n);
	rep(i,0,n){
		si(arr[0][i]);
		si(arr[1][i]);
		si(arr[2][i]);
		si(arr[3][i]);
		si(arr[4][i]);
	}
	vector<int> V;
	if(n>11){
		printf("0\n");
		return 0;
	}
	rep(i,0,n){
		bool check=true;
		rep(j,0,n){
			
			if(j==i) continue;
			
			rep(k,0,n){
				if(k==j || k==i) continue;
				//i->j,, i->k
				// cout <<"i " << i << " j " << j << " k " << k << endl;
				int temp1[2][5];
				rep(ii,0,5){
					temp1[0][ii]=arr[ii][j]-arr[ii][i];
					temp1[1][ii]=arr[ii][k]-arr[ii][i];
					//pis(temp1[0][ii]); pin(temp1[1][ii]);
				}
				int ans=0;
				rep(m,0,5){
					ans+=temp1[0][m]*temp1[1][m];
				}
				// cout << "deg " << ans << endl;
				if(ans>0){
					check=false;
				}
				if(!check)break;

			}
			if(!check) break;
		}
		if(check){
			V.push_back(i+1);
		}
		
	}
	pin(V.size());
	rep(i,0,V.size()) pis(V[i]);

	return 0;
}