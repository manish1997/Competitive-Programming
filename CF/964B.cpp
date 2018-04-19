#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define MAX 1000005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll A,B,C,T;
    ll n;cin>>n;
    cin>>A>>B>>C>>T;
    // int arr[T];
    // mem(arr,0);
    ll ans=0;

    rep(i,0,n){
    	ll ti;cin>>ti;
    	//received at ti;
    	ll temp=0;
    	rep(j,ti,T+1){
    		//if he receieves it at t=j, what will he get
    		ll curr=(j-ti)*C;
    		//already received
    		curr+=(A-B*(j-ti));
    		temp=max(temp, curr);
    	}
    	ans+=temp;
    }
    cout<<ans<<endl;
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