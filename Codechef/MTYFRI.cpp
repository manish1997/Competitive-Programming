
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

int x;

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n,k;cin>>n>>k;

    ll total=0;
    ll tomu=0;
    vector<int> T;
    vector<int> M;
    rep(i,0,n){
        cin>>x;
        total+=x;
        if(i%2){
            tomu+=x;
            T.pb(x);
        }
        else M.pb(x);
    }

    sort(M.begin(), M.end());
    sort(T.begin(), T.end());
    int end=M.size()-1;
    for(int i=0; i<T.size(); i++){
        if(i>=k || end<0 || T[i]>=M[end]) break;
        tomu-=T[i];
        tomu+=M[end];
        end--;
        if(tomu>total-tomu){
            cout<<"YES\n";
            return;
        }
    }
    if(tomu>total-tomu){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";



    
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