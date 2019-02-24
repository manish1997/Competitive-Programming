#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define MAX 1000005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

ll fact[MAX];
ll powm[MAX];
ll pown[MAX];
ll revfact[MAX];



//Modulus Expo
ll expo(ll x, ll n, ll m){
	if(n==-1){
		return expo(x,m-2, m);
	}
    if(n==0) return 1;
    ll temp=expo(x,n/2,m);
    temp = ((temp%m)*(temp%m))%m;
    if(n%2!=0) temp = ((temp%m)*(x%m))%m;
    return temp;
}
//end Modulus Expo

ll nCr(ll n, ll r){
	ll ret = fact[n];
	ret = (ret * revfact[r])%mod;
	ret = (ret * revfact[n-r])%mod;
	return ret;
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n,m;
    cin>>n>>m;
    fact[0]=revfact[0]=1;
    pown[0]=powm[0]=1;

    rep(i,1,MAX){
    	powm[i]=(powm[i-1]*m)%mod;
    	pown[i]=(pown[i-1]*n)%mod;
    	fact[i]=(fact[i-1]*i)%mod;
    }
    revfact[MAX-1]=expo(fact[MAX-1], mod-2, mod)%mod;
    repDown(i,MAX-2,0){
    	revfact[i]=(revfact[i+1]*(i+1))%mod;
    }

    ll result = 0;

    rep(r,1,min(n-1,m)+1){
    	ll current = 1;
    	current = (current * nCr(m-1,r-1))%mod;
    	current = (current * nCr(n-2, r-1))%mod;
    	current = (current * fact[r-1])%mod;
    	current = (current * powm[n-1-r])%mod;
    	if((r+1)!=n){
	    	current = (current * pown[n-r-2])%mod;
	    	current = (current * (r+1))%mod;
	    }
    	result = (result + current)%mod;
    }
    cout << result << endl;

    
}

int main(){
    fast_cin;
    int t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}