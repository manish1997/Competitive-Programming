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
bool sign(int a){
	return a<0;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;
    cin>>n;
    int a[n],b[n];
    rep(i,0,n) cin>>a[i];
    rep(i,0,n) cin>>b[i];
    int ans = 0;
    rep(i,0,n){
    	if(a[i]==b[i] && b[i]==0){
    		ans++;
    	}

    	if(a[i]==0 || b[i]==0) continue;

    	while(true){
    		int temp = __gcd(abs(a[i]), abs(b[i]));
    		if(temp==1){
    			break;
    		}
    		a[i]/=temp;
    		b[i]/=temp;
    	}
    }
    map<pair<int,pair<int,int> >,int> M;
    rep(i,0,n){
    	if(a[i]==0 && b[i]==0){
    		continue;
    	}
    	if(a[i]==0){
    		continue;
    	}
    	if(b[i]==0){
    		M[{0,{0,0}}]++;
    		continue;
    	}

    	if(sign(a[i])!=sign(b[i])){
    		M[{0,{abs(a[i]), abs(b[i])}}]++;
    	}
    	else{
    		M[{1,{abs(a[i]), abs(b[i])}}]++;
    	}
    }

    int tmax =0;
    for(auto it:M){
    	tmax=max(tmax, it.s);
    }
    cout << (ans+tmax) << endl;


    
    
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