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
#define MAX 100005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
//GCD
ll gcd(ll a, ll b){
    if ( a==0 ) return b;
    return gcd ( b%a, a );
}
//end GCD
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll a;cin>>a;
    a++;
    if(a&(a-1)){
    	a--;
    	ll temp = (pow(2ll,(int)log2(a))-(a-pow(2ll,(int)log2(a))+1));
    	cout << gcd(a^temp, a&temp)  << endl;
    	return;
    }
    a--;

    ll ans=0;
    for(ll i=1; i*i<=a; i++){
    	if(a%i) continue;
    	ans=max(ans, i);
    	if((a/i)!=a){
    		ans=max(ans,a/i);
    	}
    }
    cout << gcd(ans^a, ans&a) << endl;

}

int main(){
    fast_cin;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}