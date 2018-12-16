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

vector<int> A;
vector<int> B;
int arr[MAX];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    A.clear();
    B.clear();
    int n;cin>>n;
    rep(i,0,n){
    	int x;cin>>x;
    	if(i%2) B.pb(x);
    	else A.pb(x);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int currA=0,currB=0;
    rep(i,0,n){
    	if(i%2){
    		arr[i]=B[currB++];
    	}
    	else{
    		arr[i]=A[currA++];
    	}
    }
    rep(i,0,n-1){
    	if(arr[i]>arr[i+1]) {
    		cout << i << endl;
    		return;
    	}
    }
    cout<<"OK"<<endl;
    return;
    
}
 
int main(){
    fast_cin;
    int t=1; 
    cin >> t;
    int t2=1;
    while(t--){
    	cout<<"Case #"<<t2<<": ";
	solve();
	t2++;
    }
    return 0;
}
