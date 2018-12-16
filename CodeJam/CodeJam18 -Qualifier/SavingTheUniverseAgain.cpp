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

ll V[35];
string s;
ll check(){
	ll ans=0;
	rep(i,0,s.length()) ans+=V[i];
	return ans;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll d;
    cin>>d;
    cin>>s;
    mem(V,0);
    ll curr=1LL;
    rep(i,0,s.length()){
    	if(s[i]=='C') curr*=2LL;
    	else V[i]=curr;
    }
    
    ll ans=0;
    while(true && check()>d){
    	bool swapped=false;
    	repDown(i,s.length()-2,0){
    		if(V[i]==0 && V[i+1]!=0){
    			swap(V[i],V[i+1]);
    			V[i]/=2;
    			swapped=true;
    			ans++;
    			break;
    		}
    	}
    	if(!swapped) break;
    	
    }
    if(check()<=d) cout<<ans<<endl;
    else cout <<"IMPOSSIBLE"<<endl;
    
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
