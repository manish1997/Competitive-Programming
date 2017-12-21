#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define mod 1000000007
#define MAX 1000005
#define s second
#define f first
#define pb push_back

ll arr[MAX];
ll sums[MAX];
ll cnts[MAX];

int sz=1;

void solve(){
	ll n,k;
	cin >> n >> k;
	rep(i,0,n){
		ll x; cin >> x;
		arr[x]++;
	}

	ll ans=0;
	rep(i,1,1+1e6){
		if(arr[i]){
			ans=max(ans, arr[i]);
			cnts[sz]=arr[i];
			sums[sz]=i*arr[i];
			sz++;
		}
	}
	cnts[sz]=sums[sz]=0;
	sz--;
	repDown(i,sz,1){
		cnts[i]+=cnts[i+1];
		sums[i]+=sums[i+1];
	}
	repDown(i,sz,1){
		int start=1;
		int end=i-1;
		//how many can be added between start to end and 
		// their value sums[end]/cnts[end]
		ll val=(sums[i]-sums[i+1])/(cnts[i]-cnts[i+1]);
		
		if(start>end) continue;

		while(start<=end){
			int mid=(start+end)>>1;
			ll currsum=sums[mid]-sums[i];
			ll currcount=cnts[mid]-cnts[i];
			if((currcount*val)-currsum<=k) end=mid-1;
			else start=mid+1;
		}
		//end+1 is value till which we can surely get all values equal to val
		ll used=((cnts[end+1]-cnts[i])*val)-sums[end+1]+sums[i];
		used=k-used;
		ll tempans=cnts[end+1]-cnts[i+1];
		if(used>0 && end>0){
			ll chances=cnts[end]-cnts[end+1];
			ll valofone=(sums[end]-sums[end+1])/chances;
			valofone=val-valofone;
			int st=0;
			int en=chances;
			while(st<=en){
				int m=(st+en)>>1;
				if(m*valofone<=used) st=m+1;
				else en=m-1;
			}
			tempans+=(st-1);
		}
		ans=max(ans, tempans);

	}
	tr1(ans);
}

int main(){
	clock_t clk;
	clk = clock();
	srand (time(NULL));
    int t=1; 
    cin >> t;
    while(t--){
        solve();
    }
    clk = clock() - clk;	
	cout << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}