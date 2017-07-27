//Blog to learn: https://blog.anudeep2011.com/heavy-light-decomposition/
//Topcoder Link for LCA: https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/ 
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
#define MAX 10005

const int logMax =log2(10005)+1;
int SEG[6*MAX];
int subsize[MAX];
pair<pair<int,int> , int> costs[MAX];
vector<int> indexx[MAX];
int n,ptr;
int L[MAX];
vector<pair<int,int> > adj[MAX];
int pa[logMax][MAX], baseArray[MAX], posInBase[MAX], otherEnd[MAX];

void dfs(int node, int parent, int level){
	pa[0][node]=parent;
	L[node]=level;
	subsize[node]=1;
	for(int i=0; i<adj[node].size(); i++){
		if(adj[node][i].first!=parent){
			otherEnd[indexx[node][i]]=adj[node][i].first;
			dfs(adj[node][i].first, node, level+1);
			subsize[node]+=subsize[adj[node][i].first];
		}
	}
	return;
}
void LCAPre(){
	for(int i=1; i<=logMax; i++){
		for(int j=1; j<=n; j++)	if(pa[i-1][j]!=-1) pa[i][j]=pa[i-1][pa[i-1][j]];
	}
}

int LCA(int u, int v){
	if(L[u]>L[v]) swap(u,v);
	int log=log2(L[v])+1;
	for(int i=log; i>=0; i--){
		if(pa[i][v]!=-1 && L[pa[i][v]]>=L[u]) v=pa[i][v];
	}
	//need to see proof why they come at same level
	if(v==u) return v;
	for(int i=log; i>=0; i--){
		if(pa[i][u]!=-1 && pa[i][u]!=pa[i][v]){
			u=pa[i][u];
			v=pa[i][v];
		}
	}
	return pa[0][v];
}
//HLD
int chainHead[MAX];
int chainNo; 
int chainNumber[MAX];
int chainPos[MAX];
int chainSize[MAX];
void HLD(int node, int parent, int cost){
	if(chainHead[chainNo]==-1) {
		chainHead[chainNo]=node;
	}
	chainNumber[node]=chainNo;
	chainPos[node]=chainSize[chainNo];
	chainSize[chainNo]++;
	
	//for base array. we need cost of edge with parent and position in base array
	baseArray[ptr++]=cost;
	posInBase[node]=ptr-1;

	int ind=-1; int largest=-1;
	for(int i=0; i<adj[node].size(); i++){
		if(adj[node][i].first!=parent && subsize[adj[node][i].first]>largest){
			largest=subsize[adj[node][i].first];
			ind=i;
		}
	}

	if(ind!=-1){
		HLD(adj[node][ind].first, node, adj[node][ind].second);
	}
	for(int i=0; i<adj[node].size(); i++){
		if(adj[node][i].first!=parent && ind!=i){
			chainNo++;
			HLD(adj[node][i].first, node, adj[node][i].second);
		}
	}

}
//END HLD

//after baseArray is done, segment array creation
void make_tree(int node, int start, int end){
	if(start>end) return;
	if(start==end){
		SEG[node]=baseArray[start];
		return;
	}
	int mid=(start+end)>>1;
	make_tree(2*node, start, mid);
	make_tree(2*node+1, mid+1, end);
	SEG[node]=max(SEG[2*node], SEG[2*node+1]);
	return;
}
//end segment tree creation
int queryAns(int node, int start, int end, int l, int r){
	if(start>end || l>end || r<start) return INT_MIN;
	if(l<=start && r>=end){
		return SEG[node];
	}
	int mid=(start+end)>>1;
	int left=queryAns(2*node, start, mid, l, r);
	int right=queryAns(2*node+1, mid+1, end, l, r);
	return max(left, right);
}
int query_up(int u, int lca){
	if(u==lca) return 0;
	int uChain=chainNumber[u];
	int lcaChain=chainNumber[lca];
	if(uChain==lcaChain){
		return queryAns(1, 0, ptr-1, posInBase[lca]+1, posInBase[u]);
	}
	int ans=queryAns(1,0,ptr-1, posInBase[chainHead[uChain]], posInBase[u]);
	u=pa[0][chainHead[uChain]];
	return max(ans, query_up(u,lca));
}

void query(int u, int v){
	int lca=LCA(u,v);
	int ans=query_up(u, lca);
	int temp=query_up(v,lca);
	pin(max(ans, temp));
	return;
}

void update_tree(int node, int start, int end, int index, int value){
	if(start>end || index<start || index>end) return;
	if(start==end){
		SEG[node]=value;
		return;
	}
	int mid=(start+end)>>1;
	update_tree(2*node+1, mid+1, end, index, value);
	update_tree(2*node, start, mid, index, value);
	SEG[node]=max(SEG[2*node], SEG[2*node+1]);
	return;
}

void change(int j, int cost){
	int u=otherEnd[j];
	int x=posInBase[u];
	update_tree(1,0,ptr-1,x, cost);
	return;
}
int main(){
	int t; si(t);
	while(t--){

		si(n);
		int i;
		ptr=0;
		ptr=0;
		chainNo=0;
		memset(pa,-1,sizeof(pa));
		rep(i,0,MAX) {
			adj[i].clear();
			chainHead[i]=-1;
			chainSize[i]=0;
			indexx[i].clear();
		}
		rep(i,1,n){
			int a,b,c;
			si(a);si(b);si(c);
			adj[a].push_back({b,c});
			adj[b].push_back({a,c});
			indexx[a].push_back(i);
			indexx[b].push_back(i);
		}
		dfs(1, -1, 0);
		LCAPre();
		//calcualte parents at 2^i level. 
		//pa[i][j]=2^i(th) parent of jth node

		//HLD
		HLD(1,0,0);
		//end HLD
		make_tree(1,0,ptr-1);
		while(1){
			char s[100];
			scanf("%s",s);
			if(s[0]=='D') break;
			int a,b; si(a); si(b);
			if(s[0]=='Q'){
				query(a,b);
			}
			else{
				change(a,b);
			}
		}
	}
	return 0;
}
