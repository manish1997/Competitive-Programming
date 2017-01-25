#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define slli(n) scanf("%lld",&n)
#define P pair<int,int>
#define S second
#define F first
long long k,n;
long long arr[100002];
int main(){
	slli(n); slli(k);
  // unordered_map will help in checking element presence in O(1) time.
	unordered_map<long long,bool> M;
	for(int i=0; i<n; i++){
		slli(arr[i]);
		M[arr[i]]=true;
	};
	long long answer=0;
	
	for(int i=0; i<n; i++){
    // two numbers to find
		long long r=arr[i]+k;
		long long l=arr[i]-k;
		if(M.find(r)!=M.end()) answer++;
		if(M.find(l)!=M.end()) answer++;
    // delete arr[i] to avoid duplication of pairs as when arr[i]+k comes at current position
    // then it will check for (arr[i]+k)-k and it will add (arr[i], arr[i]+k) again in answer
		M.erase(arr[i]); 
	};
	printf("%lld",answer);
	return 0;
};
