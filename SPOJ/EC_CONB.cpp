#include <bits/stdc++.h>
using namespace std;
int N;

int findLastBit(int curr){
	while(curr^(curr&-curr)){
		curr=curr^(curr&-curr);
	};
	for(int i=0; i<32; i++){
		if(1<<i & curr) return (i);
	};
	return 0;
};

int change(int curr){
	int x=findLastBit(curr);
	int newNum=0;
	for(int i=0; i<=x; i++){
		if((1<<i)&curr) newNum+= pow(2,x-i);
	};
	return newNum;
};
int main() {
	scanf("%d",&N);
	while(N--){
	
		int curr; cin >> curr;
		
		if(curr&1) 
			cout << curr << endl;
		else
			cout << change(curr) << endl;
	
	};
	return 0;
}
