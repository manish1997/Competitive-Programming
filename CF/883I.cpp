#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define si(n) scanf("%d",&n)
#define si2(n1,n2) scanf("%d%d",&n1,&n2)
#define sll(n) scanf("%lld",&n)
#define sll2(n1,n2) scanf("%lld%lld",&n1,&n2)
#define tr1(n) printf("%d\n",n)
#define tr2(n1,n2) printf("%d%d\n",n1,n2)
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define MAX 300005
#define s second
#define f first
#define pb push_back
int n,k;
int arr[MAX];
bool dp[MAX];
int check[MAX];

bool f(int ans){
    rep(i,1,n+1) {
        dp[i]=false;
        check[i]=0;
    }
    int minn=1;
    int curr=0;
    rep(i,k,n+1){
        //maxx is maximum index which can be there for ith element
        int maxx=(i-k+1);
        while(arr[i]-arr[minn]>ans) minn++;
        //minn is first element that can be taken into account
        if(minn<=maxx) {
            if(minn==1||check[maxx-1]-check[minn-2]>0){
                dp[i]=true;
                curr++;
            }
        }
        check[i]=curr;
    }
    return (dp[n]==true);
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    si2(n,k);
    rep(i,1,n+1) si(arr[i]);
    sort(arr+1, arr+1+n);
    int low=0;
    int high=arr[n]-arr[1]+1;
    while(low<=high){
        int mid=(low+high)>>1;
        if(f(mid)) high=mid-1;
        else low=mid+1;
    }
    tr1(high+1);
}

int main(){
    int t=1; 
    //(t);
    while(t--){
        solve();
    }
    return 0;
}