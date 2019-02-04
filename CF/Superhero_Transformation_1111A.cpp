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
bool vowel(char x){
	return (x=='a'||x=='e'||x=='i'||x=='o'||x=='u');
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    string a,b;
    cin>>a>>b;
    if(a.length()!=b.length()){
    	cout <<"No";
    	return;
    }
    for(int i=0;i<a.length();i++){
    	if(vowel(a[i])!=vowel(b[i])){
    		cout <<"No";
            return;
    	}
    }
    cout <<"Yes";
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