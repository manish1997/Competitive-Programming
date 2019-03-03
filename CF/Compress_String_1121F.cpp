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
string s;
ll n,a,b;

vector<int> generateFailureFunction(int idx){
	vector<int> ret;
	ret.pb(0);
	string temp = s.substr(idx);

	int start = 0;
	for(int i=1; i<temp.length();){
		if(temp[start]==temp[i]){
			start++;
			ret.pb(start);
			i++;
			continue;
		}
		if(start==0){
			ret.pb(0);
			i++;
		}
		else{
			start=ret[start-1];
		}
	}
	return ret;
}

int findLongest(int idx){
	if(idx==0){
		return 0;
	}
	//create failure function for 0-idx-1
	vector<int> failure = generateFailureFunction(idx);

	string next= s.substr(idx);

	int maxx = 0;
	int i=0;
	int j=0;
	while(j<idx){
		if(s[j]==next[i]){
			j++;
			i++;
			maxx=max(maxx, i);
			if(i==next.length()){
				return maxx;
			}
		}
		else{
			if(i==0){
				j++;
			}
			else{
				i = failure[i-1];
			}
		}
	}
	return maxx;
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n>>a>>b;
    cin>>s;

    int len[n];
    mem(len,0);
    repDown(i,n-1,0){
    	len[i]=findLongest(i);
    }
    pair<int,int> dp[n+1];
    dp[n]={0,0};
    repDown(i,n-1,0){
    	dp[i].f = a+min(dp[i+1].f, dp[i+1].s);
    	if(len[i]!=0) dp[i].s = b+min(dp[i+len[i]].f, dp[i+len[i]].s);
    	else{
    		dp[i].s=dp[i].f+b;
    	}
    }
    cout << min(dp[0].f, dp[0].s) << endl;
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