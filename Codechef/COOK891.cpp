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
#define MAX 1000005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;cin >> n;
    if(n==0){
        cout <<"Draw" <<endl;
        return;
    }
    unordered_map<string,int> M;

    rep(i,0,n){
        string s; cin >> s;
        M[s]++;
    }
    if(M.size()==1){
        cout << M.begin()->first <<endl;
        return;
    }
    string a=M.begin()->first;
    int acnt=M.begin()->second;
    M.erase(M.begin());
    string b=M.begin()->first;
    int bcnt=M.begin()->s;
    if(acnt>bcnt){
        cout << a << endl;
    }
    else if(bcnt>acnt){
        cout << b << endl;
    }
    else {
        cout << "Draw" << endl;
    }
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