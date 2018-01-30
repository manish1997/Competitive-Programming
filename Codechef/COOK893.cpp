//TODO-Not correct
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

ll arr[MAX],n;

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n,d;
    cin >> n >> d;
    bool allneg=true;
    ll maxx=-1e9;

    rep(i,0,n){
        cin >> arr[i];
        if(arr[i]>0) allneg=false;
        maxx=max(maxx, arr[i]);
    }
    //if all elements are negative
    if(allneg){
        if(d>maxx){
            cout << -1 << endl;
            return;
        }
        cout << 1 << endl;
        return;
    }


    //all not negative
    if(d<=0){
        cout << 1 << endl;
        return;
    }


    ll tillhere=arr[0],maxsum=arr[0];
    rep(i,1,n){
        tillhere = max(arr[i], tillhere + arr[i]);
        maxsum = max(maxsum, tillhere);
    }
    if(maxsum<d){
        cout << -1 << endl;
        return;
    }

    ll start=0;
    ll end=0;
    ll sumupto=0;
    ll ans=1e6;
    while(end<n){
        if(sumupto+arr[end]<=0){
            start=end+1;
            sumupto=0;
        }
        else{
            sumupto+=arr[end];
            if(sumupto>=d){
                while(sumupto>=d){
                    ans=min(ans, end-start+1);
                    sumupto-=arr[start];
                    start++;
                }
            }
        }
        end++;
    }
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