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
    int n,k;
    cin>>n>>k;
    vector<int> tosort;
    vector<int> A(n);
    rep(i,0,n){
    	cin>>A[i];
    	int last=k+i+1;
    	int first=i-k-1;
    	if(last>=n && first<0) continue;
    	tosort.pb(A[i]);
    }
    sort(tosort.begin(), tosort.end());
    int curr=0;
    rep(i,0,n){
    	int last=k+i+1;
    	int first=i-k-1;
    	if(last>=n && first<0) continue;
    	A[i]=tosort[curr++];
    }
    rep(i,0,n) cout<<A[i] <<" ";
    
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