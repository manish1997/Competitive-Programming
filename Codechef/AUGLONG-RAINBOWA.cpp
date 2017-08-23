#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%lld\n\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define S second
#define F first
#define P pair<int,int>
#define PP pair<P,int>
using namespace std;
ll n,d;
ll arr[101];
int main(){
	int t; si(t);
	while(t--){
		sll(n); //sll(d);
		int ans=true;
		rep(i,1,n+1){
			sll(arr[i]);
			if(arr[i]>7 || arr[i]<1) ans=false;
		}
		if(ans==false){
			cout << "no" << endl;
			continue;
		}
		int start=1;
		int end=n;
		int curr=1;
		arr[end+1]=1;//rr[end];
		arr[0]=1;//arr[1];
		//cout << "or" << endl;
		while(start<=end){
		//	cout << start << " " << end << " " << curr << " " << arr[start] <<" " << arr[end]<< endl;
			if(arr[start]==arr[end] && arr[start]==curr){
				start++;
				end--;
			}
			else if(arr[start]==arr[end] && arr[start]!=curr){
				if(arr[start]==curr+1){
					curr++;
				}
				else{
					ans=false;
					break;
				}
				start++;
				end--;
			}
			else if(arr[start]!=arr[end]){
				ans=false;
				break;
			}
		}
		if(curr!=7) ans=false;
		if(ans==false){
			cout << "no" << endl;
		}
		else{
			cout << "yes" << endl;
		}


	}


	return 0;
}