#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
#define ll long long
void solve(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<(1<<n); i++){
		ll ans=0;
		for(int j=0; j<n; j++){
			if(i&(1<<j)){
				ans+=a[j];
				ans=(ans+360)%360;
			}
			else{
				ans-=a[j];
				ans=(ans+360)%360;
			}
		}
		ans=(ans+360)%360;
		if(ans==0){
			cout<<"YES";
			return;
		}
		
	}
	cout<<"NO";
	return;
	
	
	
	
}

int main() {
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}