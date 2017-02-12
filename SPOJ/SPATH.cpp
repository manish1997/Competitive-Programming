#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
using namespace std;

int n;
int dp[10001][10001];
vector<pair<int,int> > graph[10001];
void dijkstra(int source){
	
	
	long long minimum[n+1];	bool visited[n+1];
	for(int i=1; i<=n; i++) minimum[i]=INT_MAX-200020;
	memset(visited, false, sizeof(visited));
	minimum[source]=0;
	priority_queue<pair<int,int> > my_set;
	my_set.push({0,source});
	
	while(!my_set.empty()){
		int currnode=my_set.top().second;
		my_set.pop();
		
		if(visited[currnode]) continue;
		visited[currnode]=true;
		
		vector<pair<int,int> > TEMP=graph[currnode];
		
		for(int it=0; it<TEMP.size(); ++it){
			
			if(minimum[TEMP[it].first] > (minimum[currnode]+TEMP[it].second) ){
				minimum[TEMP[it].first]  = minimum[currnode]+TEMP[it].second;
				my_set.push({(-1)*minimum[TEMP[it].first], TEMP[it].first});
			};
			
		};
		
	};
	
	for(int i=1; i<=n; i++) {
		dp[source][i]=minimum[i];
		dp[i][source]=minimum[i];
	};
	
};

int tryit(int source, int destination){
	if(dp[source][destination]!=-1) return dp[source][destination];
	if(source==destination) return 0;
	dijkstra(source);
	return dp[source][destination];
};

int main() {
//	std::ios::sync_with_stdio(false);
	int t;
	si(t);
	while(t--){
		memset(dp, -1, sizeof(dp));
		si(n);
		unordered_map<string, int> cityName;
		for(int i=1; i<=n ;i++){
			graph[i].clear();
			string sname;
			cin >> sname;
			cityName[sname]=i;
			int neigh;
			si(neigh);
			while(neigh--){
				int x,y;
				si(x); si(y);
				graph[i].push_back({x,y});
			//	graph[x].push_back({i,y});
			};
		};
		
		int r; si(r);
		while(r--){
			string s1,s2; cin >> s1 >> s2;
			int first=cityName[s1], second=cityName[s2];
			printf("%d\n",tryit(first, second));
		};
		
	};
	return 0;
};
