#include <bits/stdc++.h>
using namespace std;
bool palindrome(string s, int start, int end){
	if(start>=end) return true;
	while(start<=end){
		if(s[start]!=s[end]){
			return false;
		}
		start++; end--;
	}
	return true;
}
bool check(string s, int start, int end){
	if(start==end || (start+1==end)) return true;
	while(start<=end && s[start]==s[end]) {
		start++;
		end--;
	}
	if(start>end) return true;
	return (palindrome(s,start,end-1)||palindrome(s,start+1,end));
}
int main() {
	// your code goes here
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		if(check(s,0,s.length()-1)) printf("YES\n");
		else printf("NO\n");
		
	}
	return 0;
} 