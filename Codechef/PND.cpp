#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s="";
		while(n){
			s.push_back((n%8)+'0');
			n=n/8;
		}
		int start=0;
		bool flag=true;
		int end=s.length()-1;
		while(start<=end){
			if(s[start]!=s[end]){
				flag=false;
				break;
			}
			start++;
			end--;
		}
		if(flag){
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}