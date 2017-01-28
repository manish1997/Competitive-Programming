#include <iostream>
#include <climits>
using namespace std;
#define N 100002
#define S second
#define F first

pair<int,int> SEG[4*N];
int arr[N];

pair<int,int> union1(pair<int,int> A, pair<int,int> B){
	pair<int,int> P;
	P.F=max(A.F,B.F);
	if(A.F<=B.S) P.S=B.S;
	else if(A.S>=B.F) P.S=A.S;
	else P.S=min(A.F,B.F);
	return P;
};

void build(int node, int start, int end){
	if(start==end){
		SEG[node].F=arr[start];
		SEG[node].S=INT_MIN;
		return;
	};
	int mid=start+((end-start)/2);
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);
	SEG[node]=union1(SEG[2*node], SEG[2*node+1]);
	return;
};

void update(int node, int start, int end, int idx){
	if(start>idx || end<idx) return;
	if(start==end){
		SEG[node].F=arr[idx];
		SEG[node].S=INT_MIN;
		return;
	};
	int mid=start+((end-start)/2);
	update(2*node, start, mid, idx);
	update(2*node+1, mid+1, end, idx);
	SEG[node]=union1(SEG[2*node], SEG[2*node+1]);
	return;
};

pair<int,int> query(int node, int start, int end, int l, int r){
	if(l>end || r<start || start>end) return make_pair(INT_MIN, INT_MIN);
	if(l<=start && r>=end){
		return SEG[node];
	};
	int mid=start+((end-start)/2);
	return union1(query(2*node, start, mid, l, r), query(2*node+1, mid+1, end, l,r));
};



int main() {
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&arr[i]);
	build(1, 0, n-1);
	int Q;
	scanf("%d",&Q);
	while(Q--){
		char A;
		int x,y;
		scanf(" %c%d%d", &A, &x, &y);
		if(A=='U'){
			x--;
			arr[x]=y;
			update(1,0,n-1, x);
		}
		else{
			x--;
			y--;
			pair<int,int> temp=query(1,0,n-1,x,y);
			printf("%d\n", temp.F+temp.S);
		};
	};
	return 0;
}
