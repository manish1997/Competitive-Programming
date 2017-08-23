// Simple application of Minimum Spanning Trees.
// For MST tutorial go through >
// https://github.com/manish1997/Adv-Data-Structures/blob/master/Spanning%20Tree%20using%20Kruskal%E2%80%99s%20Algorithm
include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int Parent[1002];
int Crank[1002];
#define P pair<int,int>
#define PP pair<ll,P>
#define S second
#define F first
PP arr[300002];
void initializer(){
	for(int i=0; i<=1001; i++){
		Crank[i]=0;
		Parent[i]=i;
	};
};
int root(int x){
	if(Parent[x]!=x) Parent[x]=root(Parent[x]);
	return Parent[x];
};
void union1(int x, int y){
	int PX=root(x);
	int PY=root(y);
	if(Crank[PX]>Crank[PY]) Parent[PY]=PX;
	else Parent[PX]=PY;
	if(Crank[PX]==Crank[PY]) Crank[PY]+=1;
};

int n,m;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		initializer();
		ll price;
		scanf("%lld",&price);
		scanf("%lld%lld",&n,&m);
		for(int i=0; i<m; i++) scanf("%d%d%lld", &arr[i].S.F, &arr[i].S.S, &arr[i].F);
		sort(arr, arr+m);
		ll answer=0;
		for(int i=0; i<m; i++){
			int x=arr[i].S.F;
			int y=arr[i].S.S;
			if(root(x)!=root(y)){
				answer+=arr[i].F;
				union1(x,y);
			};
		};
		answer*=price;
		printf("%lld\n",answer);
	};
	return 0;
}
