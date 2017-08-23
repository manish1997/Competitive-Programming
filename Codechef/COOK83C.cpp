#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
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

ll n,b;
int main(){
	
	int t; si(t);
	while(t--){
		sll(n); sll(b);
		vector<pair<int,int> > V;
		if(n==2 && b==0){
			printf("NO\n");
			continue;
		}
		else if(n==2){
			printf("YES\n");
			printf("1 2\n");
			continue;
		}
		if(!b){
			int x=2;
			while(V.size()!=(n-1)){
				V.push_back({1,x++});
			}
			printf("YES\n");
			rep(i,0,V.size()){
				cout << V[i].first << " " << V[i].second << endl;
			}
			continue;
		}
		
		for(int i=1; i<(2*b+1); i++){
			V.push_back({i,i+1});
		}
		//cout << "V.size " <<V.size() << endl;
		if(V.size()>(n/2)) {
			printf("NO\n");
			continue;
		}
		pair<int,int> last=V[V.size()-1];
		int x=last.second+1;
		while(V.size()!=(n-1)){
			V.push_back({1,x++});
		}
		printf("YES\n");
		rep(i,0,V.size()){
			cout << V[i].first << " " << V[i].second << endl;
		}
		// if((2*b-1)>(n/2)){
		// 	printf("NO\n");
		// 	continue;
		// }
	//	int rem=n-2*b;


		
	}
	return 0;
}