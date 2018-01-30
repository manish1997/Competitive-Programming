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

void solve(){
    ll n,m,r,k;
    double N,M,R,K;
    cin>>n>>m>>r>>k;
    if(n>m) swap(n,m);
    N=n;
    M=m;
    R=r;
    K=k;

    ll top=0;
    double ans=0;

    if((m+2-2*r)>=0){
        for(int i=r; k>0 &&i<=n-r+1; i++){

            ll fish=min(k,m+2-2*r);
            k-=fish;
            ans+=(((R*R)/((N-R+1)*(M-R+1)))*fish);
        }
    }
    tr1(ans);
    vector<pair<int,int> > Q;
    vector<pair<int,int> > TQ;
    
    for(int x=r-1; k>0&&x>=1; x--){
        for(int y=r-1; k>0&&y>=0; y--){
            if(k>0)TQ.pb({x,y});
            int tx=x,ty=y;
            while(k>0&&tx+ty!=(m+1)){
                k--;
                Q.pb({tx,ty});
                ty++;
            }
            if(k>0)TQ.pb({tx,ty});
            while(k>0 && tx+ty!=(n+m)){
                k--;
                Q.pb({tx,ty});
                tx++;
            }
            if(k>0)TQ.pb({tx,ty});
            while(k>0 && tx+ty!=(n+1)){
                k--;
                Q.pb({tx,ty});
                ty--;
            }
            if(k>0)TQ.pb({tx,ty});
            while(k>0 && tx!=x){
                k--;
                Q.pb({tx,ty});
                tx--;
            }
            while(k>0 && TQ.size()>0){
                Q.pb(TQ.back());
                TQ.pop_back();
                k--;
            }
        }
    }
    rep(i,0,Q.size()){
        ll tx=Q[i].f;
        ll ty=Q[i].s;
        tr2(tx, ty);
        double topp=max(0LL,n-r+1-(tx-r+1)+1);
        if(tx<=n-r+1) topp=r;
        else {
            topp=max(0LL,n-r+1-(tx-r+1)+1);
        }
        double leftt=max(0LL,m-r+1-(ty-r+1)+1);
        if(ty<=m-r+1) leftt=r;
        else leftt=max(0LL,m-r+1-(ty-r+1)+1);

        
        tr2(topp, leftt);
        ans+=(((topp)*leftt)/((N-R+1)*(M-R+1)));
    }
    cout << ans << endl;




}

int main(){
    // fast_cin;
    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}