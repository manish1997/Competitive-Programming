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
int arr[1004];
int n;
int find(int value){
	int ans=0;
	for(int i=0; i<n; i++){
		ans+=(min(abs(value-arr[i]), min(abs(value-(arr[i]-1)), abs(value-(arr[i]+1)))));
	}
	return ans;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n;
    for(int i=0; i<n; i++){
    	cin>>arr[i];
    }
    int ans=1e9;
    int ind=0;

    for(int i=1; i<=100; i++){
    	if(ans>find(i)){
    		ans=find(i);
    		ind=i;
    	}
    }
    cout << ind << " " << ans << endl;
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