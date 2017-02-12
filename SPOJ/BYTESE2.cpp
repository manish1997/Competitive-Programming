#include <bits/stdc++.h>
using namespace std;

struct node{
	bool start,end;
	int val;
};

node arr[205];

bool comp(node A, node B){
	if(A.val!=B.val) return (A.val<B.val);
	return A.start;
};

int main() {
	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		int maxi=0;
		for(int i=0; i<n; i++){
			int x,y; cin >> x >> y;
			arr[maxi].start=true;
			arr[maxi].end=false;
			arr[maxi].val=x;
			maxi++;
			arr[maxi].start=false;
			arr[maxi].end=true;
			arr[maxi].val=y;
			maxi++;
		};
		sort(arr,arr+maxi,comp);
		int answer=-1;
		int curr=0;
		for(int i=0; i<maxi; i++){
			if(arr[i].start) curr++;
			else if(arr[i].end) curr--;
			answer=max(answer,curr);
		};
		cout << answer << endl;
	};
	return 0;
};
