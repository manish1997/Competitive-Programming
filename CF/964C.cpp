#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000009
#define MAX 1000005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
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
    ll n,a,b,k;
    cin>>n>>a>>b>>k;
    ll ans=0;
    rep(i,0,k){
        char x;cin>>x;
        if(x=='+'){
            ans=(ans+((expo(a,n-i, mod)*expo(b,i, mod))%mod))%mod;
        }
        else{
            ans=(ans-((expo(a,n-i, mod)*expo(b,i, mod))%mod)+mod)%mod;
        }
    }

    n=(n+1)/k;
    n--;
    // cout<<n<<endl;
    if(n==0){
        cout << ans << endl;
        return;
    }
    //calculate (a^(-k)*b^(k))
    ll temp=expo(b,k,mod);

    ll temp2=(expo(a,mod-2,mod));

    temp2=expo(temp2,k,mod); //a^k

    temp=(temp*temp2)%mod;
    // cout<<temp<<endl;
    if(temp==1) {
        cout << (ans*(n+1LL))%mod << endl;
        return;
    }

    //Numerator
    temp2=expo(temp,n+1,mod);
    temp2-=1;
    if(temp2<0) temp2+=mod;
    //denominator
    ll alpha=(temp-1+mod)%mod;
    //final multiple
    temp2=(temp2*expo(alpha,mod-2,mod))%mod;
    //multiply
    ans=(ans*(temp2%mod))%mod;
    cout<<ans << endl;



}

int main(){
    fast_cin;
    int t=1; 
    // cin >> t;
    // cout << (((-1*1999)%mod)+mod)%mod << endl;

    // cout << ((-1+mod)*1999)%mod << endl;
    
    while(t--){
        solve();
    }
    return 0;
}