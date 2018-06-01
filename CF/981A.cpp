#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define mod 1000000007
#define MAX 105
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
 string s;
 bool check(int start, int end){
    while(start<=end) {
        if(s[start]!=s[end]) return true;
        start++;end--;
    }
    return false;
 }

void solve(){
    //solve the problem. You can and you will :) give your best shot..
   
    cin>>s;
    int ans=0;
    repDown(len,s.length(),1){
        int start=0;
        int end=start+len-1;
        while(end<s.length()){
            if(check(start,end)){
                ans=len;
                break;
            }
            start++;
            end++;
        }
        if(ans!=0) break;
    }
    cout << ans << endl;
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