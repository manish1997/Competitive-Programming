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
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<vector<ll> > multiplyMatrix(vector<vector<ll> >& A, vector<vector<ll> >& B){
    vector<vector<ll> > V(A.size(),vector<ll>(A.size(),0));
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A.size(); j++){
            ll ans = 0;
            //ith row of A multiply by jth column of B
            for(int k=0; k<A.size(); k++){
                ans = (ans + ( ( A[i][k] * B[k][j] ) % mod ) )%mod;
            }
            V[i][j]=ans;
        }
    }
    return V;
}

vector<vector<ll> > matrixExpo(vector<vector<ll> >& V, ll n){
    if(n==1){
        return V;
    }
    vector<vector<ll> > temp = matrixExpo(V,n/2);
    temp=multiplyMatrix(temp,temp);
    if(n%2){
        temp=multiplyMatrix(temp,V);
    }
    return temp;
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n,m;
    cin>>n>>m;


    if(n==m){
        cout << "2";
        return;
    }
    if(n<m){
        cout << "1";
        return;
    }
    vector<vector<ll> > mat(m,vector<ll>(m,0));
    mat[0][0]=mat[0][m-1]=1;
    rep(i,0,m-1){
        mat[i+1][i]=1;
    }

    mat = matrixExpo(mat, n-m);

    ll ans = 0;
    ans+=mat[0][0];
    rep(i,0,m){
        ans=(ans+mat[0][i])%mod;
    }
    cout << ans << endl;


}

int main(){
    fast_cin;
    int t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}