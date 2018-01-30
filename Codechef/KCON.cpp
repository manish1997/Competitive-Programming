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

vector<ll> V;
ll n,k;
ll maxsum(int start, int end){
    bool allneg=true;
    ll maxx=-1e7;
    rep(i,start,end+1){
        if(V[i]>0) {
            allneg=false;
        }
        maxx=max(maxx,V[i]);
    }
    if(allneg) return maxx;
    ll tillhere=V[start];
    maxx=V[start];
    rep(i,start+1,end+1){
        tillhere = max(V[i], tillhere + V[i]);
        maxx = max(maxx, tillhere);
    }
    return maxx;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n>>k;
    V.resize(n*2);
    ll sum=0;
    rep(i,0,n){
        cin>>V[i];
        sum+=V[i];
    }
    rep(i,n,2*n){
        V[i]=V[i-n];
    }
    if(k<=2){
        cout << maxsum(0,(n*k)-1) <<endl;
    }
    else{
        ll ans1=maxsum(0,(n*2)-1);
        if(ans1<=0) {
            cout << ans1 << endl;
            return;
        }
        ll ans2=(k-2)*sum;
        ll temp1=V[n-1];
        ll pre1=V[n-1];
        repDown(i,n-2,0){
            pre1+=V[i];
            temp1=max(temp1,pre1);
        }
        ll temp2=V[0];
        ll suff1=V[0];
        rep(i,1,n){
            suff1+=V[i];
            temp2=max(temp2, suff1);
        }
        if(temp2>0) ans2+=temp2;
        if(temp1>0) ans2+=temp1;
        cout << max(ans1, ans2) << endl;

    }
    
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