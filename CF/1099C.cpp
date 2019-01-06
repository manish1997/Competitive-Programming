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

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    string s;cin>>s;
    int k;cin>>k;
    int snow=0,candy=0;
    rep(i,0,s.length()){
        if(s[i]=='*') snow++; 
        else if(s[i]=='?') candy++;
    }
    int total=snow+candy;
    int original=s.length()-total;
    
    // cout << k << " " << total << " " << original<< endl;
    if(total==0){
        if(s.length()!=k){
            cout <<"Impossible";
            return;
        }
        cout << s << endl;
        return;
    }
    if(k>original){
        if(snow==0){
            cout <<"Impossible";
            return;
        }
        int rem=k-original;
        string ans="";
        for(int i=0; i<s.length(); i++){
            if(s[i]=='?'){
                continue;
            }
            if(s[i]=='*'){
                while(rem){
                    ans.push_back(ans.back());
                    rem--;
                }
                continue;
            }
            ans.push_back(s[i]);
        }
        cout << ans << endl;
        return;
    }
    if(k==original){
        string ans="";
        for(int i=0; i<s.length(); i++){
            if(s[i]!='*' && s[i]!='?'){
                ans.push_back(s[i]);
            }
        }
        cout << ans << endl;
        return;
    }
    //k<original
    int rem=original-k;
    if(total<rem){
        cout <<"Impossible";
        return;
    }
    string ans="";
    for(int i=0; i<s.length(); i++){
        if(s[i]=='*' || s[i]=='?'){
            if(rem){
                ans.pop_back();
                rem--;
            }
            continue;
        }
        ans.push_back(s[i]);
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