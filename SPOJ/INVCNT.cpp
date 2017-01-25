#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
#define REP(i, N) for(int i=1; i<=N; i++)
#define si(n) scanf("%d",&n)
#define pin(n) printf("%d\n",n)
#define pis(n) printf("%d",n)
#define plln(n) printf("%lld\n",n)
#define plls(n) printf("%lld",n)
typedef long long ll;
int n;
int arr[200001];
int temp[200001];
int original[200001];
long long BIT[10000001];
ll query(ll x){
	ll ans=0;
	while(x>0){
		ans+=BIT[x];
		x-=(x&-x);
	};
	return ans;
};
void update(ll x){
	while(x<=10000000){
		BIT[x]+=1;
		x+=(x&-x);
	};
};
int main()
{
    int t;
    cin >> t;
    while(t--){
    	si(n);
    	rep(i,n) {
    		si(arr[i]);
    	};
    	ll ans=0;
    	memset(BIT,0,sizeof(BIT));
    	for(int i=(n-1);i>=0; i--){
    		ans+=query(arr[i]);
    		update(arr[i]);
    	};
    	cout <<ans << endl;
    	
    };
    
    return 0;
}
