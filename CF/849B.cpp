#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
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
#define s second
#define f first
#define newLine printf("\n")
int n; pair<int,int> arr[1005];

int gcd ( int  a, int b )
{
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}
map<pair<int,int>, vector<int> > M;
pair<int,int> slo(int i, int j){
	int y=arr[i].second-arr[j].second;
	int x=arr[i].first-arr[j].first;
	if(y==0) return {0,1};
	bool neg=false;
	if((x<0 && y>0) || (x>0 && y<0)) neg=true;
	x=abs(x); y=abs(y);
	int temp=gcd(x,y);
	x/=temp;
	y/=temp;
	if(neg) y*=-1;
	return {y,x};
}
//bool visited[1001];
int main(){
	si(n);
	rep(i,1,n+1) {
		si(arr[i].second);
		arr[i].first=i;
	}
	int diff=0;
	// visited[1]=true;
	
	for(int i=2; i<=n; i++){

		pair<int,int> slope=slo(i,1);
		//cout << slope.f <<" " << slope.s << endl;
		if(M.find(slope)==M.end()){
			diff++;
		}
		M[slope].push_back(i);
	}
	if(diff==1){
		printf("No\n");
		return 0;
	}
	if(diff==(n-1)){
		for(int j=2; j<=n; j++){
			pair<int,int> slope=slo(1,j);
			int fix;
			if(j==2) fix=3;
			else fix=2;
			bool ans=true;
			for(int i=2; i<=n; i++){
				if(i==fix || i==j) continue;
				pair<int,int> xx=slo(fix,i);
				if(xx!=slope) {
					ans=false;
					break;
				}
			}
			if(ans==true){
				printf("Yes\n");
				return 0;
			}
		}
		//cout << "here";
		int fix=2;
		pair<int,int> slope=slo(fix,3);
		bool ans=true;
		for(int i=3; i<=n; i++){
			//if(i==fix || i==j) continue;
			pair<int,int> xx=slo(fix,i);
			if(xx!=slope) {
				ans=false;
				break;
			}
		}
		if(ans==true){
			printf("Yes\n");
			return 0;
		}
		printf("No\n");
		return 0;
	}
	bool one=false;
	vector<int> V;
	pair<int,int> temp;
	for(auto it=M.begin(); it!=M.end(); it++){
		if(it->second.size()>1 && one==false){
			//rep(j,0,it->second.size()) visited[it->second[j]]=true;
			temp=it->first;
			one=true;
		}
		else if(it->second.size()>1){
			printf("No\n");
			return 0;
		}
		else{
			V.push_back(it->second[0]);
		}
	}
	bool ans=true;
	for(int i=1; i<V.size(); i++){
		if(slo(V[i], V[0])!=temp){

		 ans=false;
		 break;
}

	}
	if(ans){
		printf("Yes\n");
	}
	else printf("No\n");

	return 0;
}