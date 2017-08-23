#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define si(n) cin >> n
#define sll(n) cin >> n
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define S second
#define F first
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define newLine printf("\n")
void ans(ll n){
	if(n==0) return;
	if(n%2==0){
		plln(n);
		ll k=0;
		rep(i,0,n){
			plln(n);
			rep(j,0,n){
				if(j%2==0){
					plls(j+1);
					plls(((j+k)%n)+1);
					plln(((j+k+1)%n)+1);
				}
				else{
					plls(j+1);
					plls(((j-1+k)%n)+1);
					plln(((j+k)%n)+1);
				}
			}
			k++;
		}
	}
	else{
		 plln(n);
		 vector<pair<int,int>> Paa;
		rep(i,0,n){
			Paa.push_back(make_pair((i%n)+1, ((i+1)%n)+1));
		}
		ll k=0;
		rep(i,0,n){
			plln(n);
			int cnt=0;
			for(int j=k; cnt<n; j=(j+1)%n){
				pis(cnt+1);
				pis(Paa[j].first);
				pin(Paa[j].second);

				cnt++;
			}
			k++;
		}

	}
}
int main(){
	//vector<int> V;
	int t; si(t);
	while(t--){
		ll n;
		sll(n);
		if((n%2)==0){
			ans(n);
		}
		else{
			ans(n);
		}
		
	}
	return 0;
}