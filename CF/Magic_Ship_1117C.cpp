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
#define MAX 100005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

pair<ll,ll> arr[MAX];
ll n;
ll totalx,totaly;

bool possible(ll curr){
	ll temp = (curr-1)/n;
	ll windx = (arr[n-1].f)*temp;
	ll windy = (arr[n-1].s)*temp;


	temp = (curr-1)%n;
	windx+=arr[temp].f;
	windy+=arr[temp].s;

	windx=totalx-windx;
	windy=totaly-windy;

	windx=abs(windx);
	windy=abs(windy);

	if(windx>curr){
		return false;
	}

	curr-=windx;

	curr-=windy;

	return curr>=0;
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll x11,y11,x22,y22;
    cin>>x11>>y11>>x22>>y22;
    totalx = x22-x11;
    totaly = y22-y11;

    cin>>n;
    rep(i,0,n){
    	char x;cin>>x;
    	if(x=='U'){
    		arr[i].f=0;
    		arr[i].s=1;
    	}
    	else if(x=='D'){
    		arr[i].f=0;
    		arr[i].s=-1;
    	}
    	else if(x=='R'){
    		arr[i].f=1;
    		arr[i].s=0;
    	}
    	else{
    		arr[i].f=-1;
    		arr[i].s=0;
    	}
    	if(i!=0){
    		arr[i].f+=arr[i-1].f;
    		arr[i].s+=arr[i-1].s;
    	}
    }
    ll start = 1;
    ll end = 1e18;

    while(start<=end){
    	ll mid = (start+end)>>1LL;
    	if(possible(mid)){
    		end=mid-1;
    	}
    	else{
    		start=mid+1;
    	}
    }

    if(end==1e18){
    	cout << -1;
    }
    else{
    	cout << start;
    }


    
}

int main(){
    fast_cin;
    ll t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}