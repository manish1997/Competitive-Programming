#include <bits/stdc++.h>
using namespace std;
#define y first
#define x second

bool comp(pair<int,int> A, pair<int,int> B){
	return A.x<B.x;
};

double distance(pair<int,int> A, pair<int,int> B){
	int a=B.x-A.x;
	a*=a;
	int b=B.y-A.y;
	b*=b;
	return sqrt(a+b);
};

int main() {
	int n;
	cin >> n;
	double h;
	pair<int,int> V[n];
	for(int i=0; i<n; i++)	cin >> V[i].x >> V[i].y;
	
	set<pair<int,int>> box;
	sort(V, V+n, comp);
	box.insert(V[0]);
	int left=0;
	
	for(int i=1; i<n; i++){
		
		if(i==1) h=distance(V[i],V[left]); // set h as current minimum distance which is distance between
		// first and second point
		
		// while we have points having lesser x than (V[i].x-V[left].x) remove them
		while(left<i && (V[i].x-V[left].x)>h) box.erase(V[left++]);
		
		// (it->y<=V[i].y+h) this assures that it never goes below range of current active set of points
		for(auto it=box.lower_bound(make_pair(V[i].y-h, INT_MIN)); it!=box.end() && it->y<=V[i].y+h; it++){
			h=min(h,distance(V[i],*it));
		};
		
		box.insert(V[i]);
	}; // end for
	
	cout << h << endl;
	return 0;
};
