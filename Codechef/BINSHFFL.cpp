

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
#define MAX (1<<17)+5
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

ll countbit(ll a){
    ll res=0;
    while(a){
        if(a%2LL) res++;
        a/=2LL;
    }
    return res;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0<<endl;
        return;
    }
    if(b==0){
        cout<<-1<<endl;
        return;
    }
    if(b==1){
        if(a==0) cout<<1<<endl;
        else cout<<-1<<endl;
        return;
    }

    ll A=countbit(a);
    ll X=countbit(b-1LL);
    if(A>X) cout<<2<<endl;
    else cout<<(X-A+1)<<endl;
}

int main(){
    fast_cin;
    int t=1; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}