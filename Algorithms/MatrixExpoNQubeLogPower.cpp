#define mod 1000000007
#define ll long long

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

vector<vector<ll> > matrixExpo(vector<vector<ll> >& V, int n){
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

int main(){
	vector<vector<ll> > V = {{1,0,1},{1,0,0},{0,1,0}};
	V = matrixExpo(V, n-2);
	return 0;
}