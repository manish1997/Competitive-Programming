#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX (1<<17)
#define size 1<<20
#define f first
#define s second

ll health[size];
pair<ll,ll> Q[size];
ll dp[(1<<18)+5];
ll SUB[size];

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>health[i];
    }
    ll q;
    cin>>q;
    for(int i=0; i<q; i++){
        cin>>Q[i].f>> Q[i].s;
        Q[i].f&=(MAX-1);
    }
    ll block=1000;
    ll num=((q-1)/block);

    for(int b_num=0; b_num<=num; b_num++){
        int low=b_num*block;
        int high=min(low+block-1, q-1);
        memset(dp, 0, sizeof(dp));
        for(int i=low; i<=high; i++){
            dp[Q[i].f]+=Q[i].s;
        }
        for(int i=0; i<=16; i++){
            for(int mask=MAX-1; mask>=0; mask--){
                if(((mask>>i)&1)==0){
                    dp[mask]+=dp[mask^(1<<i)];
                }
            }
        }
        for(int i=0; i<n; i++){
            if(health[i]<=0) continue;
            if(health[i]-dp[i]>0){
                health[i]-=dp[i];
                continue;
            }
            for(int j=low; j<=high; j++){
                if((Q[j].f&i)==i){
                    health[i]-=Q[j].s;
                    if(health[i]<=0){
                        SUB[j]-=1;
                        break;
                    }
                }
            }
        }
    }
    int ans=n;
    for(int i=0; i<q; i++){
        ans+=SUB[i];
        cout << ans << endl;
    }
    return 0;
}