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
char arr[5300][5300];
int sumzero[5300][5300];

int n;

string convert(int i){
	string ans="";
	while(i){
		ans.pb((i%2)+'0');
		i/=2;
	}
	while(ans.size()<4) ans.pb('0');
	reverse(ans.begin(), ans.end());
	return ans;
}
bool solve(int x){
	// bool possible = true;
	for(int i=0; i<n; i+=x){
		for(int j=0; j<n; j+=x){

			char curr = arr[i][j];

			int endx=i+x-1;
			int endy=j+x-1;
			if(arr[endx][endy]!=curr){
				return false;
			}
			int total = sumzero[endx][endy];
			int top = (endx-x)>=0?sumzero[endx-x][endy]:0;
			int left= (endy-x)>=0?sumzero[endx][endy-x]:0;
			int twotime = (i-1>=0 && j-1>=0)?sumzero[i-1][j-1]:0;
			total-=(top+left-twotime);

			if(curr=='1'){
				if(total) return false;
			}
			else{
				if(total!=(x*x)) return false;
			}

		}
	}
	return true;

}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n;
    string pre[16];
    rep(i,0,16){
    	pre[i]=convert(i);
    }
    rep(i,0,n){
    	string s;
    	cin>>s;
    	for(int j=0; j<s.length(); j++){
    		string curr = pre[(s[j]<='9')?(s[j]-'0'):(s[j]-'A'+10)];
    		for(int k=4*j; k<4*(j+1); k++){
    			arr[i][k]=curr[k%4];
    			sumzero[i][k]=arr[i][k]=='0';
    			if(k!=0) sumzero[i][k]+=sumzero[i][k-1];
    		}
    	}
    	for(int j=0; j<n; j++){
    		if(i==0) continue;
    		sumzero[i][j]+=sumzero[i-1][j];
    	}
    }
    // rep(i,0,n){
    // 	rep(j,0,n) cout<<sumzero[i][j] <<" ";
    // 	cout << endl;
    // }
    vector<int> divs;
    for(int i=1; i*i<=n; i++){
    	if(n%i) continue;
    	divs.pb(i);
    	if(i*i!=n) divs.pb(n/i);
    }
    
    sort(divs.begin(), divs.end());
    for(int i=divs.size()-1; i>=0; i--){
    	if(i==0){
    		cout << 1;
    		return;
    	}
	    if(solve(divs[i])){
	    	cout << divs[i];
	    	return;
	    }
	}
    
}

int main(){
	// const clock_t begin_time = clock();
    fast_cin;
    int t=1;

    while(t--){
        solve();
    }
    // cout << endl;
    // cout << float( clock () - begin_time )/CLOCKS_PER_SEC;
    return 0;
};