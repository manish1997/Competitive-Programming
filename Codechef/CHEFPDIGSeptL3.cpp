#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
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
#define s second
#define f first
#define newLine printf("\n")
string s;
int arr[10];
int main(){
	int t; si(t);
	while(t--){
		cin >> s;
		memset(arr,0,sizeof(arr));
		rep(i,0,s.length()){
			arr[s[i]-'0']++;
		}
		string ans;
		rep(i,65,65+26){
			int f=i%10;
			int s=(i/10)%10;
			if(f==s){
				if(arr[f]>1){
					ans.push_back(i);
				}
			}
			else{
				if(arr[f] && arr[s]){
					ans.push_back(i);
				}
			}
		}
		cout << ans << endl;
		
	}
	return 0;
}
