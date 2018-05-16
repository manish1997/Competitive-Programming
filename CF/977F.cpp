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
#define MAX 200005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
int n, arr[MAX];
map<int,int> M;

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n;
    rep(i,0,n) cin>>arr[i];
    int ans=0;
    int start=0;
    repDown(i,n-1,0){
    	int curr=arr[i];
    	if(M.find(curr+1)==M.end()){
    		M[curr]=1;
    		if(M[curr]>ans){
	    		ans=1;
	    		start=curr;
	    	}
    		continue;
    	}
    	M[curr]=M[curr+1]+1;
    	int temp=M[curr];
    	if(temp>ans){
    		ans=temp;
    		start=curr;
    	}
    }
    cout << ans << endl;
    rep(i,0,n){
    	if(arr[i]==start){
    		cout << i+1 <<  " " ;
    		start++;
    	}
    }
    cout << endl;


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