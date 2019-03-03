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
// int arr[MAX];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n,k;
    cin>>n>>k;
    int arr[n];
    rep(i,0,n){
    	cin>>arr[i];
    }
    pair<int,int> process[k];
    int currentFree = k;
    rep(i,0,k){
    	process[i]={i,1};
    }
    int currMoment = 1;
    int completed = 0;
    int q=0;
    unordered_map<int,bool> M;


    while(true){
    	int cnt=0;
    	rep(i,0,k){
    		if(process[i].f>=n){
    			cnt++;
    			continue;
    		}
    		if(process[i].s==q){
    			M[process[i].f];
    		}
    	}
    	if(cnt==k){
    		break;
    	}
    	rep(i,0,k){
    		if(process[i].f>=n){
    			continue;
    		}
    		if(process[i].s==arr[process[i].f]){
    			completed++;
    			process[i]={currentFree,1};
    			currentFree++;
    			continue;
    		}
    		process[i].s++;
    	}
    	currMoment++;
    	double tem = (100.0*completed)/(n*1.0);
    	q=int(tem+0.5);
    }
    cout << M.size() << endl;

    
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