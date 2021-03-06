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
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
map<string,int> M;
bool pos[104];
string s[104];
bool comp(string a, string b){
	return (a.length()<b.length());
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
	int n;cin>>n;
	rep(i,0,n){
		cin>>s[i];
	}
	sort(s,s+n,comp);
	//s[0] will be smallest
	bool ans=true;
	rep(i,1,n){
		if(s[i].find(s[i-1])==std::string::npos){
			ans=false;
			break;
		}
	}
	if(!ans){
		cout<<"NO";
		return;
	}
	cout<<"YES\n";
	rep(i,0,n){
		cout<<s[i]<<endl;
	}
}

int main(){
    fast_cin;
    int t=1; 
    // cin >> t;
    // rep(i,0,100)cout<< rand()%100000000000000000+10000000000 <<endl;

    while(t--){
        solve();
    }
    return 0;
}