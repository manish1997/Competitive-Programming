#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
	//solve manually for large numbers
	long long k; k=100;
	cout << ((k*(k+1))/2)*((k*(k+1))/2)-((k*(k+1)*(2*k+1))/6);
	return 0;
}