#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for(ll i=a;i<b;i++)
#define mod 1000000007
ll n,m;
 
vector<vector<ll> > mulMatrix(vector<vector<ll> > A, vector<vector<ll> > B){
    vector<vector<ll> > V(A.size(), vector<ll> (B[0].size(), 0));
    rep(j,0,A.size()){
        rep(i,0,B[0].size()){
            ll temp=0;
            rep(k,0,A[j].size()){
                temp=(temp+((A[j][k]*B[k][i])%mod))%mod;
            }
            V[j][i]=temp;
        }
    }
    return V;
}
 
vector<vector<ll> > expoMatrix(vector<vector<ll> > A, ll n){
    if(n==0){
        rep(i,0,A.size())rep(j,0,A[0].size())if(i==j)A[i][j]=1; else A[i][j]=0;
        return A;
    }
    vector<vector<ll> > temp=expoMatrix(A, n/2);
    temp=mulMatrix(temp, temp);
    if(n%2){
        temp=mulMatrix(temp, A);
    }
    return temp;
}
 
int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        if(n==1){
            cout << m << endl;
            return 0;
        }
        vector<vector<ll> > V1;
        V1.resize(m);
        rep(i,0,m) V1[i].resize(m,0);
        rep(i,0,m){
            if(i-2>=0){
                V1[i-2][i]=1;
            }
            V1[i][i]=1;
            if(i+2<m){
                V1[i+2][i]=1;
            }
        }
        vector<vector<ll> > V2;
        V2.resize(m);
        rep(i,0,m) V2[i].resize(m,0);
     
        rep(i,0,m){
            if(i-3>=0){
                V2[i-3][i]=1;
            }
            V2[i][i]=1;
            if(i+3<m){
                V2[i+3][i]=1;
            }
        }
        vector<vector<ll> > V3;
        V3.resize(m);
        rep(i,0,m) V3[i].resize(m,0);

        rep(i,0,m){
            if(i-1>=0){
                V3[i-1][i]=1;
            }
            V3[i][i]=1;
            if(i+1<m){
                V3[i+1][i]=1;
            }
        }
     
        vector<vector<ll> > V;
        V.resize(m);
        rep(i,0,m) V[i].resize(m,0);
        V=mulMatrix(V1,V2);
        V=mulMatrix(V,V3);
        if(n%3==1){
            V=expoMatrix(V,(n/3));
        }
        if(n%3==2) {
            V=expoMatrix(V,(n/3));
            V=mulMatrix(V,V1);
        }
        if(n%3==0){
            V=expoMatrix(V,(n/3)-1);
            V=mulMatrix(V,V1);
            V=mulMatrix(V,V2);
        }
        vector<vector<ll> > res(1, vector<ll> (m, 1));
        res=mulMatrix(res, V);
        ll tempp=0;
        rep(i,0,res[0].size()) tempp=(tempp+res[0][i])%mod;
        cout <<tempp<< endl;
    }
    return 0;
}