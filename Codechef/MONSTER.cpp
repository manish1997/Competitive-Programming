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
#define MAX 131072
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

ll arr[MAX];
int findbits(int num){
    int res=0;
    while(num){
        res++;
        num=num&(num-1);
    }
    return res;
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;cin>>n;
    rep(i,0,n)cin>>arr[i];
    int q;cin>>q;
    int ans=n;
    q=1<<18;

    while(q--){
    	int x;
        ll y;
        cin>>x>>y;
        x=(1<<17)-1;
    	x=x&((1<<17)-1);
        int setbits=findbits(x);
        if(setbits<=200){
            for(int j=x; j>0; j=(j-1)&x){
                if(j<n && arr[j]>0LL && arr[j]<=y){
                    ans--;
                }
                if(j<n) arr[j]-=y;
            }
            if(arr[0]>0LL && arr[0]<=y) {
                ans--;
            }
            arr[0]-=y;
        }
        else{

        }
        // cout << ans << endl;
    }

    
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