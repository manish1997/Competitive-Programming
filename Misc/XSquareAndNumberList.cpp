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
#define MAX 500005
#define INF (1<<30)-1
#define BIT 29
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

ll pre[MAX+5], suff[MAX+5];
ll pow2[MAX+5];
ll arr[MAX+5];
ll cnt[MAX+5];
ll ans[MAX+5];

map<ll,ll> M;

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    ll n,q;
    scanf("%lld%lld", &n, &q);
    pow2[0]=1LL;
    rep(i,1,MAX+5) pow2[i]=(pow2[i-1]*2LL)%mod;
    rep(i,0,n){
        scanf("%lld", &arr[i]);
    }
    sort(arr,arr+n);
    ll curr=1;
    rep(i,0,n){
    	if(M.find(arr[i])!=M.end()){
    		cnt[M[arr[i]]]++;
    	}
    	else{
    		M[arr[i]]=curr++;
    		cnt[curr-1]=1;
    	}
    }
    ll till=0;
    rep(i,1,curr){
    	pre[i]=suff[i]=((pow2[cnt[i]]-1)*pow2[till])%mod;
    	ans[i]=pre[i];
    	till+=cnt[i];
    }
    pre[0]=1;suff[curr]=0;
    rep(i,1,curr){
    	pre[i]=(pre[i-1]+pre[i])%mod;
    }
    suff[0]=1;
    repDown(i,curr-1,0){
    	suff[i]=(suff[i+1]+suff[i])%mod;
    }
    while(q--){
    	char type; ll x;
    	getchar();
    	scanf("%c%lld", &type, &x);
    	if(type=='<'){
			if(x>arr[n-1]){
				printf("%lld\n", pre[curr-1]);
				continue;
			}
			x=M.lower_bound(x)->second;
			printf("%lld\n", pre[x-1]);
    	}
    	else if(type=='>'){
    		if(x>=arr[n-1]){
    			printf("0\n");
    			continue;
    		}
    		if(M.find(x)!=M.end()) x=M[x];
    		else{
    			x=M.lower_bound(x)->second;
    			x--;
    		}
    		printf("%lld\n", suff[x+1]);
    	}
    	else{
    		if(M.find(x)==M.end()){
    			printf("0\n");
    			continue;
    		}
    		printf("%lld\n", ans[M[x]]);
    	}
    }





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