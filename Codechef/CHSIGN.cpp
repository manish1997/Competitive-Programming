//TODO
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
ll n,arr[MAX];
int cnt[MAX];
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n;
    mem(cnt,0);
    rep(i,0,n) cin>>arr[i];
    ll tillsum=0;
    tillsum=arr[0];
    priority_queue<pair<int,int > > PQ;
    rep(i,1,n){
    	PQ.push({min(arr[i],arr[i-1]), i});
    }

    while(!PQ.empty()){
    	pair<int,int> top=PQ.top();
    	PQ.pop();
    	int i=top.s;
    	if(cnt[i] || cnt[i-1] || arr[i]==arr[i-1]){
    		continue;
    	}
    	if(arr[i-1]>arr[i]) arr[i]*=-1LL;
    	else arr[i-1]*=-1LL;
    	cnt[i]=cnt[i-1]=1;
    }
    rep(i,0,n) cout << arr[i] << " ";
    cout << endl;



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