#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll sum(ll x){
	ll ans=0;
	while(x){
		ans+=(x%10);
		x/=10;
	}
	return ans;
}
void change(ll &n){
	while(n>=10){
		n=sum(n);
	}
}
int main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
		ll n,a;
		cin>>a>>n;
		change(a);
		if(a==1)cout<<1<<endl;
		else if(a==2){
			n=(n-1)%6;
			if(n==0) cout<<2<<endl;
			else if(n==1) cout<<4<<endl;
			else if(n==2) cout<< 8 << endl;
			else if(n==3) cout << 7 << endl;
			else if(n==4) cout << 5 <<endl;
			else cout << 1 << endl;
		}
		else if(a==3){
			if(n==1) cout<<3<<endl;
			else cout<<9<<endl;
		}
		else if(a==4){
			n=(n-1)%3;
			if(n==0)cout<<4<<endl;
			else if(n==1) cout<<7<<endl;
			else cout<<1<<endl;
		}
		else if(a==5){
			n=(n-1)%6;
			if(n==0) cout<<5<<endl;
			else if(n==1) cout<<7<<endl;
			else if(n==2) cout<< 8 << endl;
			else if(n==3) cout << 4 << endl;
			else if(n==4) cout << 2 <<endl;
			else cout << 1 << endl;
		}
		else if(a==6){
			if(n==1)cout<<6<<endl;
			else cout<<9<<endl;
		}
		else if(a==7){
			n=(n-1)%3;
			if(n==0)cout<<7<<endl;
			else if(n==1) cout<<4<<endl;
			else cout<<1<<endl;
		}
		else if(a==8){
			n=(n-1)%2;
			if(n==0)cout<<8<<endl;
			else cout<<1<<endl;
		}
		else{
			cout<<9<<endl;
		}
	}
	return 0;
}