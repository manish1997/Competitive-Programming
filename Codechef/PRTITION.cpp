#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define MAX 1000005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
ll n,k;
char ans[1000006];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>k>>n;
    ll sum=(n*(n+1))/2;
    sum-=k;
    if(sum%2){
        tr1("impossible");
        return;
    }
    sum/=2;
    rep(i,0,n+2) ans[i]='0';
    ll curr=0LL;
    bool flag=false;
    rep(i,1,n+1){
        if(i==k){
            ans[i]='2';
            continue;
        }
        curr+=i;
        if(curr<sum){
            ans[i]='1';
            continue;
        }
        if(curr==sum){
            ans[i]='1';
            flag=true;
            break;
        }
        ll req=curr-sum;
        if(ans[req]=='1'){
            ans[i]='1';
            ans[req]='0';
            flag=true;
            break;
        }
        else{
            if(i+1<=n && ans[req+1]=='1'){
                ans[i+1]='1';
                ans[req+1]='0';
                flag=true;
            }
            else if(req!=2){
                ans[i]='1';
                ans[req-1]='0';
                ans[1]='0';
                flag=true;
            }
            break;
        }
    }

    if(!flag || n==2) {
        tr1("impossible");
        return;
    }
    rep(i,1,n+1) if(i==k) cout<<"2"; else cout<<ans[i];
    cout<<"\n";
}

int main(){
    fast_cin;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}