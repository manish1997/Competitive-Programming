//TODO: not correct. have to do.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define si(n) cin >> n
#define sll(n) cin >> n
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define MAX 1000005
//ll arr
//const int logMax =log2(302)+1;
int n;
ll val[302];
vector<int> adj[302];
vector<int> primes;
int isPrime[MAX];
int cnt;
int len[301][301];
int powers[15][15][78500];
int s;

void dfs(int cur, int prev){
	//cout<<val[cur]<<endl;
    for(ll i=0; i<n; i++){
    	// if(i<10) cout << primes[i] <<endl;
        ll v = val[cur];
        ll j=primes[i];
        powers[s][cur][i] = powers[s][prev][i];
        while(v%j == 0){
            v/=j; powers[s][cur][i]++;
        }
        // if(j<15) cout<<j<<" "<<s<<" "<<cur<<" "<<powers[s][cur][j]<< " " << val[cur]<<endl;

    }
    len[s][cur] = len[s][prev]+1;
    for(int i=0; i<adj[cur].size(); i++){
        if(adj[cur][i]!=prev) dfs(adj[cur][i], cur);
    }

}  

void seive(){
	memset(isPrime,false,sizeof(isPrime));
	isPrime[0]=isPrime[1]=true;

    for(long long i=2; i<sqrt(MAX); i++){
        if(isPrime[i]==false){
            for(long long j=i*i; j<MAX; j+=i){
                isPrime[j]=true;
            }
        }
    }
    for(int i=2; i<MAX; i++){
        if(isPrime[i]==false){
            cnt++;
            // if(cnt%100==1) {
                primes.push_back(i);
            // }
        }
    }
}

int main(){
	std::ios::sync_with_stdio(false);
    seive();
    n=primes.size();
//cout << n <<endl;
	int t; si(t);
	while(t--){
		int N;
		si(N);
		rep(i,0,N){
			si(val[i+1]);
		}
		rep(i,0,MAX) adj[i].clear();
		//cout << n << endl;
		rep(i,1,N) {
			int x,y;
			si(x); si(y);
			 adj[x].push_back(y);
			 adj[y].push_back(x);
		}
		
		int ans = -1;
		cnt=0;



    for(int i=1; i<=N; i++){
    	s=i;
    	len[i][i]=0;
    	dfs(i, -1);
    }

    for(int i=1; i<=N; i++){
        for(int j=i; j<=N; j++){
            int flag=1;
            for(int k=0; k<n && flag; k++){
                if(powers[i][j][k]%3!=0) flag=0;
            }
            // cout<<i<<" "<<j<<" "<<len[i][j]<<endl; 
            if(flag) ans = max(ans, len[i][j]);
        }
    }

//    cout<<powers[7][10][]<<endl;

    // cout<<n<<end
    cout << (5LL*1000000LL*256LL*32LL) << endl;    cout << ans << endl;


	}
	return 0;
}
