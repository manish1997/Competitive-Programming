#include <bits/stdc++.h>
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
#define P pair<int,int>
#define PP pair<P,int>
using namespace std;
ll n,D;
ll arr[100005];

int main(){
	int t; si(t);
	while(t--){
		sll(n); sll(D);
		rep(i,1,n+1){
			sll(arr[i]);
		}
		ll curr=-1;
		bool ans=true;
		ll finalAnswer=0;
		for(ll i=1; i<=D; i++){
			ll num=0;
			ll tempCurr=0;
			for(ll j=i; j<=n; j+=D){
				num++;
				tempCurr+=arr[j];
			}
			//cout << tempCurr << endl;

			//cout << num << endl;
			if(tempCurr%num!=0){
				ans=false;
				break;
			}
			if(curr==-1) curr=tempCurr/num;
			if((tempCurr/num)!=curr){
				ans=false;
				break;
			}
			tempCurr=tempCurr/num;
			//cout << tempCurr << endl;
			for(ll j=i; j<=n; j+=D){
				if(j+D>n) continue;
				if(arr[j]<tempCurr){
					arr[j+D]-=(tempCurr-arr[j]);
					finalAnswer+=(tempCurr-arr[j]);
				}
				else if(arr[j]>tempCurr){
					arr[j+D]+=(arr[j]-tempCurr);
					finalAnswer+=(arr[j]-tempCurr);
				}
			}
		}
		if(ans==false){
			plln(-1LL);
			continue;
		}
		plln(finalAnswer);




	}


	return 0;
}