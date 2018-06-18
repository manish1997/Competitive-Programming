#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll unsigned long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define MAX 200005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n,k;
ll arr[MAX];
ll nextnone[MAX];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n>>k;
    rep(i,0,n) cin>>arr[i];
    ll curr=n;
    bool allone=true;
    repDown(i,n-1,0){
        if(arr[i]!=1){
            allone=false;
            curr=i;
        }
        nextnone[i]=curr;
    }
    if(allone){
        if(k==1){
            cout<<n<<endl;
        }
        else{
            cout<<0<<endl;
        }
        return;
    }
    ll ans=0;
    for(int i=0; i<n; i++){
        ll product=arr[i];
        ll sum=arr[i];
        if(product/sum==k){
            ans++;
        }

        for(ll j=i+1; j<n;){
            if(arr[j]==1){
                ll tempj=nextnone[j];
                ll initialsum=sum;
                ll currentsum=sum+tempj-j;
                if(product%k!=0){
                    sum=currentsum;
                    j=tempj;
                    continue;
                }
                if((product/k)<=currentsum && (product/k)>initialsum){
                    ans++;
                }
                j=tempj;
                sum=currentsum;
                continue;
            }
            ll temp=product*arr[j];
            if((temp/arr[j])!=product){
                break;
            }
            product*=arr[j];
            sum+=arr[j];
            if(product==sum*k){
                ans++;
            }
            j++;
        }
    }
    cout<<ans<<endl;






}

int main(){
    fast_cin;
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}