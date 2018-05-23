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
#define MAX 100000
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll x1,x2,x3;
    cin>>x1>>x2>>x3;
    x1+=MAX;
    x2+=MAX;
    x3+=MAX;
    double chefd=x3-x1;
    double kefad=x2-x3;
    double v1,v2;
    cin>>v1>>v2;
    chefd=chefd/v1;
    kefad/=v2;
    if(chefd>kefad) cout<<"Kefa\n";
    else if(kefad>chefd) cout<<"Chef\n";
    else cout <<"Draw\n";
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