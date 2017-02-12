#include <iostream>
#include <stack>
using namespace std;
#define si(n) scanf("%d",&n)
int n;
string s;
struct node{
	int open;
	int close;
};

node SEG[4*30002];

node join (node A, node B){
	node toReturn;
	toReturn.open=B.open+(((A.open-B.close)>0)?(A.open-B.close):0);
	toReturn.close=A.close+ (((B.close-A.open)>0)?(B.close-A.open):0);
	return toReturn;
};

void build(int num, int left, int right){
	
	if(left==right){
		SEG[num].open=(s[left]=='(')?1:0;
		SEG[num].close=(s[left]==')')?1:0;
		return;
	};
	int mid=(left+right)/2;
	build(2*num, left, mid);
	build(2*num+1, mid+1, right);
	SEG[num]=join(SEG[2*num],SEG[2*num+1]);
//	cout << num << " " << SEG[num].open << " " << SEG[num].close << endl;
	return;
};

void update(int num, int left, int right, int idx){
	
	if(left>idx || right < idx) return;
	
	if(left==right){
		SEG[num].open=(s[left]=='(')?1:0;
		SEG[num].close=(s[left]==')')?1:0;
		return;
	};
	
	int mid=(left+right)/2;
	
	if(idx>mid) update(2*num+1, mid+1, right, idx);
	else update(2*num, left, mid, idx);
	
	SEG[num]=join(SEG[2*num],SEG[2*num+1]);
//	cout << num << " " << SEG[num].open << " " << SEG[num].close << endl;
};

int main() {
	
	for(int t=1; t<=10; t++){
		si(n);
		cin >> s;
		build(1, 0, n-1);
		int q;
		si(q);
		printf("Test %d:\n",t);
		while(q--){
			int x;
			si(x);
			if(x==0){
				node temp=SEG[1];
				if(temp.open==0 && temp.close==0) printf("YES\n");
				else printf("NO\n");
			}
			else{
				if(s[x-1]=='(') s[x-1]=')';
				else s[x-1]='(';
				update(1, 0, n-1, x-1);
			};
		};
		
		
	};
	return 0;
}
