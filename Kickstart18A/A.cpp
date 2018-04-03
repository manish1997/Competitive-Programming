#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define mod 1000000007
#define MAX 1000005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
ll myfunc(string s){
	ll ans=0;
	rep(i,0,s.length()) ans=(ans*10+(s[i]-'0'));
	return ans;
}
ll ans(ll curr2, bool up){
	if(curr2==0) return 0;
	// tr2(curr2, up);
	string s=to_string(curr2);
	reverse(s.begin(), s.end());
	ll curr=s[s.length()-1]-'0';
	if(curr%2==0){
		s.pop_back();
		reverse(s.begin(), s.end());
		ll tem=myfunc(s);
		return curr*(pow(10LL,(ll)s.length()))+ans(tem, up);
	}
	if(up==false){
		s[s.length()-1]-=1;
		reverse(s.begin(), s.end());
		rep(i,1,s.length())s[i]='9';
		if(s[0]=='0') s=s.substr(1);
		return ans(myfunc(s), false);
	}
	else{
		if(curr!=9){
			s[s.length()-1]+=1;
			reverse(s.begin(), s.end());
			rep(i,1,s.length())s[i]='0';
			return (myfunc(s));
		}
		else{
			rep(i,0,s.length())s[i]='0';
			s.push_back('1');
			reverse(s.begin(), s.end());
			return (ans(myfunc(s), true));
		}
	}
}
ll tc=0;
double arr[20003];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
	double n;cin>>n;
	ll k;cin>>k;
	double maxx=0.0;
	unordered_map<double,double> M;

	double anss2=0;
	rep(i,0,n){
		cin>>arr[i];
		maxx=max(maxx, arr[i]);
		anss2+=arr[i];
		M[arr[i]]+=1.0;
	}
	cout<<"Case #"<<tc<<": ";
	if(k==0){
		printf("%.12lf\n", anss2/n);
		return;
	}
	double anss=0;
	double pp=M[maxx]/n;
	anss+=((anss2-M[maxx]*maxx)*((1.0-pp)*(1.0/n)));
	anss+=(pp*maxx);
	anss+=(1-pp)*pp*maxx;
	printf("%.12lf\n", anss);
}

int main(){
    // fast_cin;
    ll t=1; 
    cin >> t;

    while(t--){
    	tc++;
        solve();
    }
    return 0;
}