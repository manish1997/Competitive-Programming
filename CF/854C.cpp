#include <bits/stdc++.h>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) prllf("%d\n",n)
#define plln(n) prllf("%i64d\n",n)
#define pis(n) prllf("%d ",n)
#define plls(n) prllf("%lld ",n)
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define S second
#define F first
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define s second
#define f first
#define newLine prllf("\n")
ll n,k;
ll BIT1[1000005], BIT2[6000010];
pair<ll,ll> arr[300005];

 
void update2(ll index, ll Delta){
 
 for(;index<=(k+n);index+=index&-index){
  	BIT2[index]+=Delta;
 };
 
 
}
 
ll query2(ll x){
 ll answer=0;
 for(;x>0;x-=x&-x){
  answer+=BIT2[x];
 };
 return answer;
}


ll BS(ll index, ll start, ll end){
    //ll start=1,end=n;
   // cout << index << " " << start << " " << end << " ";
    while(start<=end){
       ll mid=start+((end-start)/2);
       ll temp=query2(mid);
       //if(start==5) cout << mid << endl;
       if(temp>=index) end=mid-1;
       else start=mid+1;
    };
   // cout << end+1 << endl;
     return (end+1);
}

bool comp(pair<ll,ll> A, pair<ll,ll> B){
	if(A.f>B.f) return true;
	return false;
}

int main(){
	sll(n); sll(k);
	//cout << n+1 << endl;
	for(int i=1; i<=n; i++){
		sll(arr[i].f);
		arr[i].s=i;
		//cout << arr[i].f << " " << arr[i].s << endl;
		//cout << i << endl;
	}
	for(int i=k+1; i<k+n+1; i++) {
		// cout << i << endl;
		update2(i,1);
		// cout << query2(i) << endl;
	}
	sort(arr+1, arr+n+1, comp);

	ll total=0;
	rep(i,1,n+1){
		//cout << arr[i].f << " " << arr[i].s << endl;
 		int left=max(arr[i].s, k+1);
		int ind=BS(1, left, k+n);
		//cout << ind << endl;

		if(ind==k+n+1){
			continue;
		}
		update2(ind,-1);
		total+=(ind-arr[i].s)*arr[i].f;
		arr[i].f=ind;
	}
	cout << total << endl;
	ll ans[300005];
	rep(i, 1, n+1) ans[arr[i].s]=arr[i].f;
	rep(i,1,n+1) cout << ans[i] << " ";
	return 0;
}