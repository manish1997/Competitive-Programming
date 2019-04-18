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
#define bit 62

//Modulus Expo
ll expo(ll x, ll n, ll m){
    if(n==0) return 1;
    ll temp=expo(x,n/2,m);
    temp = ((temp%m)*(temp%m))%m;
    if(n%2!=0) temp = ((temp%m)*(x%m))%m;
    return temp;
}
//end Modulus Expo

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll l,r;
    cin>>l>>r;
    ll minl,minr;
    ll evenl=0,oddl=0;
    ll mod2 = expo(2,mod-2,mod);

    rep(i,1,bit){
    	if(((1ll<<i)-1)>=l){
    		minl=i;
    		break;
    	}
    	if(i%2){
    		oddl+=(1ll<<(i-1));
    	}
    	else{
    		evenl+=(1ll<<(i-1));
    	}
    }
    rep(i,1,bit){
    	if(r<=((1ll<<i)-1)){
    		minr=i;
    		break;
    	}
    }

    if(minl==minr){
    	ll totalElement = (1ll<<(minl-1ll));
    	ll indexStart = (1ll<<minl)-totalElement;
    	ll indexEnd = (1ll<<minl)-1ll;
    	ll valueStart = (minl%2)?oddl*2ll+1ll:evenl*2ll+2;
    	ll valueEnd = (totalElement-1)*2ll + valueStart;

    	valueStart += (l-indexStart)*2ll;
    	ll terms = r-l+1;
    	ll sum = (2ll*valueStart)%mod;
    	sum = (sum+ ((((terms-1ll+mod)%mod)*2ll)%mod))%mod;
    	sum = (sum*(terms%mod))%mod;
    	sum=(sum*mod2)%mod;
    	cout << sum << endl;


    	return;
    }

    ll sum=0;

    for(ll i= minl; i<=minr; i++){
    	ll totalElement = (1ll<<(i-1ll));
    	ll indexStart = (1ll<<i)-totalElement;
    	ll indexEnd = (1ll<<i)-1ll;
    	ll valueStart = (i%2)?oddl*2ll+1:evenl*2ll+2;
    	ll valueEnd = (totalElement-1)*2ll + valueStart;


    	if(i==minl){
    		valueStart = valueStart + (l-indexStart)*2ll;
    		totalElement -= (l-indexStart);
    	}
    	else if (i==minr){
    		valueEnd = valueStart + (r-indexStart)*2ll;
    		totalElement = r-indexStart+1;
    	}
    	sum=(sum+(((((totalElement%mod)*(((valueStart%mod)+(valueEnd%mod))%mod))%mod)*mod2)%mod))%mod;


    	if(i%2){
    		oddl+=(1ll<<(i-1));
    	}
    	else{
    		evenl+=(1ll<<(i-1));
    	}

    }

    cout << sum << endl;



    
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