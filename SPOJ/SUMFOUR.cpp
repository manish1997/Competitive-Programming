#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;
#define ll int
#define N 2505
int A[N],B[N],C[N],D[N];

int main() {
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
	
	unordered_map<ll,ll> M;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			M[C[i]+D[j]]++;
		};
	};
	
	long long answer=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(M.find(-A[i]-B[j])!=M.end()) answer+=(long long)M[-A[i]-B[j]];
		};
	};
	printf("%lld",answer);
	
	
	
	return 0;
}
