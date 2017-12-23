#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <ctime>



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
#define P pair<ll,ll>
ll n,m,k;
pair<P,P> arr[100005];
ll SEG[2][100005];
ll possible[2][100005];

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin >> n >> m >> k;
    rep(i,0,m){
        cin >> arr[i].f.f >> arr[i].f.s >> arr[i].s.f>> arr[i].s.s;
    }
    rep(i,0,2){
        rep(j,0,100005){
            SEG[i][j]=1+1e6;
        }
    }
    ll a=n*(1+1e6), b=n*(1+1e6);

    sort(arr,arr+m);

    unordered_map<int,bool> M;
    rep(i,0,m){
        //i is added into the answer
        if(arr[i].s.f==0){
            //it is a flight that comes to city 0 from arr[i].f.f
            M[arr[i].f.s]; //this has to be true so because that man can come now
            if(SEG[0][arr[i].f.s]>arr[i].s.s){
                a-=SEG[0][arr[i].f.s];
                a+=arr[i].s.s;
                SEG[0][arr[i].f.s]=arr[i].s.s;
            }
        }
        if(M.size()==n) {
            possible[0][i]=a;
        }
    }
    M.clear();
    repDown(i,m-1,0){
        if(arr[i].f.s==0){
            M[arr[i].s.f];
            if(SEG[1][arr[i].s.f]>arr[i].s.s){
                b-=SEG[1][arr[i].s.f];
                b+=arr[i].s.s;
                SEG[1][arr[i].s.f]=arr[i].s.s;
            }
        }
        if(M.size()==n) {
            possible[1][i]=b;
        }
    }
    ll ans=-1;
    rep(i,0,m){
        if(possible[0][i]){
            int day=arr[i].f.f;
            day=day+k+1;
            //find first number having day>=day
            int start=i+1;
            int end=m-1;
            while(start<=end){
                int mid=(start+end)>>1;
                if(arr[mid].f.f>=day) end=mid-1;
                else start=mid+1;
            }
            if(start==m) continue;
            end+=1;
            if(possible[1][end]){
                if(ans==-1) ans=possible[0][i]+possible[1][end];
                else ans=min(ans,possible[0][i]+possible[1][end]);
            }
        }
    }
    tr1(ans);
}

int main(){
	fast_cin;
	clock_t clk;
	clk = clock();
	srand (time(NULL));
    int t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
    clk = clock() - clk;	
	// cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}