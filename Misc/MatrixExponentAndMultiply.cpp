#define ll long long
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
 