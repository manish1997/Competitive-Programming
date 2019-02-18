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
struct envelope
{
	ll wi;
	ll di;
	ll si;
	ll ti;
	envelope(ll a, ll b, ll c, ll d):si(a), ti(b), di(c), wi(d){};
	bool operator<(envelope x) const{
		if(this->wi!=x.wi) return this->wi<x.wi;
		if(this->di!=x.di) return this->di<x.di;
		return this->si<x.si;
	}
};
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n,m,k;
    cin>>n>>m>>k;
    vector<int> ins[n+2];
    vector<int> outs[n+2];
    vector<envelope> V;


    rep(i,0,k){
    	ll si,ti,di,wi;
    	cin>>si>>ti>>di>>wi;
    	envelope temp(si,ti,di,wi);
    	V.push_back(temp);
    	ins[si].push_back(i);
    	outs[ti+1].push_back(i);
    }

    multiset<envelope> S;

    ll arr[n+2][2];



    rep(i,1,n+2){
    	for(auto it:outs[i]){
    		auto itr = S.find(V[it]);
    		if(itr!=S.end()){
    			S.erase(itr);
    		}
    	}
    	for(auto it: ins[i]){
    		S.insert(V[it]);
    	}
    	if(!S.empty()){
    		arr[i][0]=(S.rbegin())->wi;
    		arr[i][1]=(S.rbegin())->di+1;
    	}
    	else{
    		arr[i][0]=0;
    		arr[i][1]=i+1;
    	}
    }

    ll dp[n+2][m+1];
    rep(i,0,n+2)rep(j,0,m+1)dp[i][j]=1e17;
    ll ans = 1e17;
    for(int i=0; i<=m; i++) dp[n+1][i]=0;

    for(int i=n; i>=1; i--){
    	for(int j=0; j<=m; j++){
			dp[i][j]=min(dp[i][j], arr[i][0]+dp[arr[i][1]][j]);
    		if(j!=0){
				dp[i][j]=min(dp[i][j], dp[i+1][j-1]);
			}
			
			if(i==1) ans=min(ans, dp[i][j]);
    	
    	}
    }

    cout << ans << endl;
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