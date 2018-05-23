//Kruskal start
int parent[MAX];
int root(int u){
	if(u!=parent[u]) parent[u]=root(parent[u]);
	return parent[u];
}
void join(int u, int v){
	u=root(u);v=root(v);
	if(u==v) return;
	parent[u]=v;
}
//Kruskal End