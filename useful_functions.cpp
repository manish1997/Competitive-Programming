//GCD
ll gcd(ll a, ll b){
    if ( a==0 ) return b;
    return gcd ( b%a, a );
}
//end GCD

//nCr
ll nCr(ll n, ll r){
    ll ans=1;
    for(ll i=1; i<=r; i++){
        ans=(ans*(n-r+i));
        ans=(ans/i);
    }
    return ans;
}
//end nCr

//Modulus Expo
ll expo(ll x, ll n, ll m){
    if(n==0) return 1;
    ll temp=expo(x,n/2,m);
    temp = ((temp%m)*(temp%m))%m;
    if(n%2!=0) temp = ((temp%m)*(x%m))%m;
    return temp;
}
//end Modulus Expo

//Segmented Sieve
vector<int> Prime; //contains prime numbers uptop segMax
void segmentedSieve(){
    #define segMax 1000000 //till point you want to find Primes. Preferebly pow(10,x)
    #define rootSegMax 1000 //root of segMax
    bool prime[rootSegMax];
    memset(prime, true, sizeof(prime));
    for(int i = 2; i*i <= rootSegMax; i++){
        if(prime[i]) {
            for(int j = i*i; j < rootSegMax; j += i){
                prime[j] = false;
            }
        }
    }
    for(int i = 2; i < rootSegMax; i++){
        if(prime[i]) {
            Prime.push_back(i);
        }
    }
    int low = rootSegMax; 
    // ^^ lower end of current block we are finding primes for
    int high = 2*rootSegMax;
    // ^^ higher end of current block we are finding primes for
    int tempMax = Prime.size();
    // ^^All non prime numbers will be multiples of these numbers only
    while(low < segMax){
        memset(prime, true, sizeof(prime));
        for(int i = 0; i < tempMax; i++){
            int start = Prime[i]*ceil(1.0*low/Prime[i]);
            for(int j = start; j < high; j += Prime[i]){
                prime[j - low] = false;
            }
        }
        for(int i = 0; i < rootSegMax; i++){
            if(prime[i]){
                Prime.push_back( i+low );
            }
        }
        low += rootSegMax;
        high += rootSegMax;
    }
}
//end Segmented Sieve

//Sieve
#define sieveMax 10001 //maximum for which u need primality test
vector<int> Prime;
void sieve(){
    bool neverMakeThisName[sieveMax];
    mem(neverMakeThisName,false);
    neverMakeThisName[0]=neverMakeThisName[1]=true;
    for(int i=4; i<sieveMax; i+=2) neverMakeThisName[i]=true;

    for(int i=3; i<=sqrt(sieveMax); i+=2)
        if(neverMakeThisName[i]==false) {
            for(int j=i*i; j<sieveMax; j+=i) neverMakeThisName[j]=true;
        }

    rep(i,0,sieveMax) if(neverMakeThisName[i]==false) Prime.pb(i);
}
//end Sieve

//Ternary
int TS(int start, int end){
	int low=start-1;
	int high=end;
	double eps=0.0001;
	while((high-low)>eps){
	           int mid=(high+low)>>1;
	           if(f(mid)>f(mid+1)) high=mid;
	           else low=mid; //now f(mid+1)>=f(mid), so current maxima lies at low+1.
	}
	return f(low+1);
}
//end Ternary