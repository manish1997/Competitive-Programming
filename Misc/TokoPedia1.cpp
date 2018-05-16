#include <bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin>>t;
	while(t--){
		long long x;
		cin>>x;
		if((x%5 ==0) || (x%5==2)){
			cout << "Nakul" << endl;
		}
		else{
			cout << "RK" << endl;
		}
	}
	return 0;
}