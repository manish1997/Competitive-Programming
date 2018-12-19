#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll unsigned long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define mod2 1000000033
#define MAX 1003
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
ll b1 = 29;
ll b2 = 31;

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    string s;
    cin>>s;
    string arr;
    cin>>arr;
    int k;cin>>k;
    set<pair<ll,ll>> M;

    rep(i,0,s.length()){
        ll currhash1=0, currhash2=0;
        ll currk=0;
        rep(j,i,s.length()){
            currhash1=(((currhash1*b1)%mod)+(s[j]-'a'+1))%mod;
            currhash2=(((currhash2*b2)%mod)+(s[j]-'a'+1))%mod;
            currk+=(arr[s[j]-'a']=='0');
            if(currk<=k && M.count({currhash1, currhash2})==0){
                M.insert({currhash1,currhash2});
            }
            if(currk>k){
                break;
            }
        }
    }
    cout << M.size() << endl;
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