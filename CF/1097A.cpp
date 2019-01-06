#include <bits/stdc++.h>
using namespace std;
#define MAX 200005

void solve(){
	string s;
	cin>>s;
	char a=s[0];
	char b=s[1];
	for(int i=0; i<5; i++){
		string temp;
		cin>>temp;
		if(temp[0]==a || temp[1]==b){
			cout<<"YES\n";return;
		}
		
	}
	cout <<"NO";
	
	
	
	
}

int main() {
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}