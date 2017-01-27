#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;
#define N 1000
char graph[N][N];
int R,C;
bool visited[N][N];
vector<pair<int,int>> V;
bool valid(int x, int y){
	if(x>=0 && y>=0 && x<R && y<C) return true;
	return false;
};
pair<int,int> next(int x, int y, int side){
	if(side==0) return make_pair(x-1, y);
	else if(side==1) return make_pair(x+1,y);
	else if(side==2) return make_pair(x,y+1);
	return make_pair(x,y-1);
};

int maxStored=-1;
pair<int,int> maxPair={-1,-1};

void BFS(int x, int y, int parent){
	queue<pair<int,int>> Q;
	for(int i=0; i<4; i++){
		pair<int,int> P=next(x,y,i);
		if(valid(P.first,P.second) && graph[P.first][P.second]!='#' && visited[P.first][P.second]==false) {
			if((parent+1)>maxStored){
				maxStored=parent+1;
				maxPair=P;
			};
			visited[P.first][P.second]=true;
			Q.push(make_pair(P.first,P.second));
		};
	};
	while(!Q.empty()){
		pair<int,int> P=Q.front();
		BFS(P.first,P.second,parent+1);
		Q.pop();
	};
};

int main() {
	int t;
	scanf("%d",&t);
	 while(t--){
	 	memset(visited,false,sizeof(visited));
	 	V.clear();
	 	maxStored=-1;
	 	maxPair={-1,-1};
	 	scanf("%d%d",&C,&R);
	 	for(int i=0; i<R; i++){
	 		char temp[C];
	 		scanf("%s",&temp);
	 		for(int j=0;j<C; j++) {
				graph[i][j]=temp[j];
	 			if(graph[i][j]=='.' && V.size()==0)	{
	 				V.push_back(make_pair(i,j));
	 			};
	 		};
	 	};
	 	int answer=0;
	 	if(V.size()!=0){
	 		visited[V[0].first][V[0].second]=true;
	 		BFS(V[0].first,V[0].second,0);
	 		pair<int,int> far=maxPair;
		 	maxPair=make_pair(-1,-1);
		 	maxStored=-1;
		 	memset(visited,false,sizeof(visited));
		 	BFS(far.first, far.second, 0);
		 	answer=max(maxStored,answer);
	 	};
	 	printf("Maximum rope length is %d.\n",answer);
	 };
	
	return 0;
}
