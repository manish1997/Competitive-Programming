#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define S second
#define F first
#define P pair<int,int>
#define PP pair<P,int>
#define mod 1000000007
#define MAX 100005
#define newLine printf("\n");
int n,m;
int ans[MAX];
int last[MAX];
bool done[MAX];
int distinct[MAX];
vector<int> adj[MAX];
int main() {
	int t; si(t);
	while(t--){
		memset(ans,0,sizeof(ans));
		memset(last,-1, sizeof(last));
		rep(i,0,MAX){
			adj[i].clear();
		}
		si(n);
		si(m);
		bool flag=true;
		rep(i,0,m){
			int a,b;
			si(a); si(b);
			if(a>=b) flag=false;
			adj[a].push_back(b);
		}
		if(!flag){
			pin(-1);
			continue;
		}
		rep(i,0,n) sort(adj[i].begin(), adj[i].end());
		int maxx=0;
		rep(i,0,adj[0].size()){
			if(ans[adj[0][i]]==0) {
				ans[adj[0][i]]=++maxx;
				last[maxx]=adj[0][i];
			}
			else flag=false;
		}
		if(!flag){
			pin(-1);
			continue;
		}

		rep(qq, 1, n){
			if(adj[qq].size()==0){
				flag=false;
				break;
			}
			vector<int> curr=adj[qq];
			rep(i,0,curr.size()){
				if(i!=0 && curr[i-1]==curr[i]){
					flag=false;
					break;
				}
				if(ans[curr[i]]==0){
					rep(j,1,maxx+1){
						if(last[j]==qq){
							ans[curr[i]]=j;
							last[j]=curr[i];
							break;
						}
						if(j==maxx){
							flag=false;
						}
					}
				}
				if(!flag) break;
			}
			if(!flag) break;
		}

		if(!flag){
			pin(-1);
			continue;
		}
		//ans[5]=2;
		// rep(i,1,n+1){
		// 	pis(ans[i]);
		// }
		// printf("\n");
		memset(done, false, sizeof(done));
		memset(distinct,0,sizeof(distinct));
		int cnt=0;
		distinct[n+1]=0;
		for(int i=n; i>=0; i--){
			if(done[ans[i]]==false){
				done[ans[i]]=true;
				cnt++;
			}
			distinct[i]=cnt;
		}
		rep(i,0,n+1){
			if(adj[i].size()!=distinct[i+1]){
				flag=false;
				break;
			}
		}

		
		if(!flag){
			pin(-1);
			continue;
		}
		rep(i,1,n+1){
			pis(ans[i]);
		}
		printf("\n");
	}
	return 0;
} 
