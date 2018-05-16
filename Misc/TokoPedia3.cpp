#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll N,T,a,b;

//Modulus Expo
ll expo(ll x, ll n, ll m){
    if(n==0) return 1;
    ll temp=expo(x,n/2,m);
    temp = ((temp%m)*(temp%m))%m;
    if(n%2!=0) temp = ((temp%m)*(x%m))%m;
    return temp;
}
//end Modulus Expo

int main(){
	cin>>N>>T>>a>>b;
	if(N==2){
		if(T%2) cout<<0<<endl;
		else cout<<2<<endl;
		return 0;
	}
	if(T<=4){
		if(T==2){
			cout<<2<<endl;
			return 0;
		}
		if(T==3){
			cout << (2*(N-2)) << endl;
			return 0;
		}
		ll ans=0;
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				for(int k=1; k<=N; k++){
					for(int l=1; l<=N; l++){
						if((i==a && l==b) || (i==b && l==a)){
							if(j!=k && j!=i && k!=l) ans++;
						}
					}
				}
			}
		}
		cout << ans << endl;
		return 0;
	}
	ll first=expo(N-1, T-2, mod);
	ll r=((mod-1LL)*(expo(N-1,mod-2,mod)))%mod;
	if(r==1){
		cout << ((first*((T-1LL)%mod))%mod) << endl;
		return 0;
	}
	first=(first*((expo(r,T-1,mod)-1LL+mod)%mod))%mod;
	first=(first*(expo((r-1+mod)%mod, mod-2, mod)))%mod;
	cout<<(2LL*first)%mod<<endl;




	return 0;
}