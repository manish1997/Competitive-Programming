#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	int x=0;
	while(t--){
		x++;
		int n; cin >> n;
		long long till=0;
		long long answer=0;
		for(int i=0; i<n; i++){
			long long curr; cin >> curr;
			till+=curr;
			if(till<=0){
				answer+=abs(till);
				till=0;
			};
		};
		printf("Scenario #%d: %lld\n", x, answer+1);
		
	};
	return 0;
}
