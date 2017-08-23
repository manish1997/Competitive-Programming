#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;
#define ll long long
#define si(n) cin >> n
#define sll(n) cin >> n
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%i64d\n",n)
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
int main(){
	int t; si(t);
	while(t--){
		string s; cin >> s;
		int ans=0;
		int i=0;
		while(i<s.length() && s[i]=='U') i++;
		for(i; i<s.length();){
			if(s[i]=='D'){
				i++;
				continue;
			}
			ans++;
			while(i<s.length() && s[i]=='U') i++;
		}
		if(s[s.length()-1]=='D') ans++;

		int ans2=0;
		i=0;
		while(i<s.length() && s[i]=='D') i++;
		for(i; i<s.length();){
			if(s[i]=='U'){
				i++;
				continue;
			}
			ans2++;
			while(i<s.length() && s[i]=='D') i++;
		}
		if(s[s.length()-1]=='U') ans2++;
		pin(min(ans,ans2));
	}
	return 0;
}