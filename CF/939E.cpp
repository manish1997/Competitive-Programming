#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define mod 1000000007
#define MAX 1000005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
int currlen=0;
bool same=true;
ll arr[600000];
ll pre[600000];

double f(ll maxx){
    return (arr[currlen-1]-(((double)pre[maxx]+(double)arr[currlen-1])/((double)maxx+2.0)));
}
double ansss=0;
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int q;cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            ll temp;
            cin>>temp;
            arr[currlen++]=temp;
            if(currlen>1) pre[currlen-1]=temp+pre[currlen-2];
            else pre[currlen-1]=arr[currlen-1];
            if(same && currlen>1 && arr[currlen-2]!=arr[currlen-1]) same=false;
            if(same){
                ansss=0;
                continue;
            }
            int start=0;
            int end=currlen-2;
            while(start<end){
                int mid=(start+end)>>1;
                if(f(mid)>f(mid+1)) end=mid;
                else start=mid+1;
            }
            ansss=f(end);
        }
        else{
            printf("%.10lf\n", ansss);
        }
    }
    
    
}

int main(){
    int t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}