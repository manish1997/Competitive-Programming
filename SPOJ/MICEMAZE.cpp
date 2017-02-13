#include <bits/stdc++.h>
using namespace std;
int N,E,T;
unordered_map<int, unordered_map<int,int> > M;
int dijkstra(int source, int destination){
	priority_queue<pair<int,int> > PQ;
	PQ.push({0,source});
	bool visited[N+1];
	memset(visited, false, sizeof(visited));
	long long dist[N+1];
	for(int i=0; i<=N; i++) dist[i]=INT_MAX;
	dist[source]=0;
	while(!PQ.empty()){
		int curr=PQ.top().second;
		PQ.pop();
		if(curr==destination) return dist[curr];
		if(visited[curr]) continue;
		visited[curr]=true;
		unordered_map<int,int> temp_map=M[curr];
		for(auto it=temp_map.begin(); it!=temp_map.end(); it++){
			if(dist[it->first]>(dist[curr]+it->second)){
				dist[it->first]=(dist[curr]+it->second);
				PQ.push({(-1)*dist[it->first], it->first});
			};
		};
	};
	return INT_MAX;
};
int main() {
	scanf("%d%d%d",&N,&E,&T);
	int r;
	scanf("%d",&r);
	while(r--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		M[a][b]=c;
	};
	int answer=0;
	for(int i=1; i<=N; i++){
		if(dijkstra(i,E)<=T) answer++;
	};
	printf("%d",answer);
	
	return 0;
}
