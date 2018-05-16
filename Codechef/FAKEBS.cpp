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
int A[MAX],arr[MAX];
int n,q;
map<int,int> M;
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n>>q;
    M.clear();
    rep(i,1,n+1){
    	cin>>arr[i];
    	M[arr[i]]=i;
    	A[i]=arr[i];
    }
    sort(A+1, A+1+n);
    while(q--){
    	int x;cin>>x;
    	int i=M[x];
    	int start=1;
    	int end=n;
    	int small=0,large=0,sm=0,lg=0;
    	while(start<=end){
    		int mid=(start+end)>>1;
    		if(arr[mid]==x) break;
    		else if(mid<i){
     			if(arr[mid]>arr[i]) small++;
     			sm++;
    			start=mid+1;
    		}
    		else{
    			if(arr[mid]<arr[i]) large++;
    			lg++;
    			end=mid-1;
    		}
    	}
    	start=1;
    	end=n;
    	while(start<=end){
    		int mid=(start+end)>>1;
    		if(A[mid]>=arr[i]) end=mid-1;
    		else start=mid+1;
    	}
    	int lesser=start-1;
    	int larger=n-lesser-1;
    	int ans=max(small,large);
    	if(sm>lesser || lg>larger) cout << -1 << endl;
    	else tr1(ans);
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