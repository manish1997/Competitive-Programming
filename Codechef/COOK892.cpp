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

int arr[10],n;

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin >> n;
    ll sum=0;
    mem(arr,0);

    rep(i,0,n){
        ll x;
        cin >> x;
        sum+=x;
        if(x%4) {
            arr[x%4]++;
        }
    }
    if(sum%4){
        cout << -1 << endl;
        return;
    }

    ll ans=0;
    ans+=min(arr[1],arr[3]);
    int rem;
    if(arr[1]>=arr[3]){
        arr[1]-=arr[3];
        arr[3]=0;
        rem=arr[1];
    }
    else{
        arr[3]-=arr[1];
        arr[1]=0;
        rem=arr[3];
    }
    if(rem%2){
        cout << -1 <<endl;
        return;
    }
    ans+=(rem/2);
    rem/=2;
    arr[2]+=rem;
    if(arr[2]%2){
        cout << -1 << endl;
        return;
    }
    ans+=((arr[2]/2));
    cout << ans << endl;
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