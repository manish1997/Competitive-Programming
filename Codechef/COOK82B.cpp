#include <iostream>
#include <cmath>
#include <climits>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
#define ll long long
#define si(n) cin >> n
#define sll(n) cin >> n
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define S second
#define F first
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define newLine printf("\n")
ll n; 

ll expo(ll x, ll n, ll m){
	if(n==0) return 1;
	ll temp=expo(x,n/2,m);
	temp = (temp*temp)%m;
	if(n%2!=0) temp = (temp*x)%m;
	return temp;
}
bool prime[40000];
vector<int> Prime;
void sieve(){
	//memset(prime, false, sizeof(prime));
	prime[0]=prime[1]=true;
	for(ll i=2; i<=sqrt(40000); i++){
		if(prime[i]==false){
			for(ll j=i*i; j<40000; j+=i){
				prime[j]=true;
			}
		}
	}
	for(ll i=2; i<40000; i++) if(prime[i]==false) Prime.push_back(i);


}

int main(){
	map<ll,ll> pow;
	sll(n);
	sieve();
	cout << Prime.size() << endl;
	rep(i,0,n){
		ll temp;
		sll(temp);
		for(int j=0; j<Prime.size(); j++){

			int cnt=0;
			while(temp%Prime[j]==0){
				temp=temp/Prime[j];
				cnt++;
			}
			if(cnt){
				pow[Prime[j]]+=cnt;
			}
		}
		if(temp>1){
			pow[temp]+=1;
		}
	}
	bool flag=0;
	for(auto it=pow.begin(); it!=pow.end(); it++){
		if(it->second%n) flag=1;
	}
	if(!flag){
		printf("justdoit\n");
		return 0;
	}
	ll ans=1;
	for(auto it=pow.begin(); it!=pow.end(); it++){
		if(((it->second)%(n+1))==0) continue;
		it->second=(n+1)-(it->second%(n+1));
		ans= (ans * (expo(it->first, it->second, mod)))%mod;;
	}
	plln(ans);
	return 0;
}