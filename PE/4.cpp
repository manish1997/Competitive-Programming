#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool palindrome(string s){
	int st=0;
	int end=s.length()-1;
	while(st<=end) if(s[st++]!=s[end--]) return false;
	return true;
}
int main(){
	int ans=0;
	for(int i=999; i>=100; i--){
		for(int j=i; j>=100; j--){
			if((i*j)<ans) break;
			if(palindrome(to_string(i*j))) ans=i*j;
		}
	}
	cout << ans;
	return 0;
}