#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;
vector<vector<int> > M(2005);
pair<int,int> person[1001];
pair<int,int> house[1001];
int arr[2005][2005];
int n,m; 
int from[2005];
bool visited[2005];
int find_aug_path(){
    queue<int> Q;
    Q.push(0);
    int sink=n+m+1;
    memset(from, -1, sizeof(from));
    memset(visited, false, sizeof(visited));
    visited[0]=true;
    bool whileBreak =false;
    while(!Q.empty() && !whileBreak){
        int cur=Q.front();
        Q.pop();
        for(int i=0; i<=(n+m+1); i++){
            int next=i;
            if(!visited[next] && arr[cur][next]>0){
                visited[next]=true;
                Q.push(next);
                from[next]=cur;
                if(next==sink) {
                    whileBreak=true;
                    break;
                }
                    
            }
            
        };
        
        
    };
   
    int prev;
    int curr=sink;
    int capacity=INT_MAX;
    while(true){
        prev=from[curr];
        if(prev==-1) break;
        capacity = min(capacity, arr[prev][curr]);
        curr=prev;
    };
    
    curr=sink;
    while(true){
        prev=from[curr];
        if(prev==-1) break;
        arr[prev][curr]-=capacity;
        arr[curr][prev]+=capacity;
        curr=prev;
    };
    return (capacity==INT_MAX)?0:capacity;
};


int maxFlow(){
    int result=0;
    while(true){
        int path= find_aug_path();
        if(path==0) break;
        result+=path;
    };
    return result;
};

int main() {
		scanf("%d%d",&n,&m);
	memset(arr, 0, sizeof(arr));
	for(int i=1; i<=n; i++){
		int ai,pi;
	    scanf("%d%d",&ai,&pi);
		person[i]={ai,pi};
	};
	for(int i=1; i<=m; i++){
		int ai,pi;
		scanf("%d%d",&ai,&pi);
		house[i]={ai,pi};
	};
	
	for(int i=1; i<=n; i++){
	    M[0].push_back(i);
	    arr[0][i]=1;
	    for(int j=1; j<=m; j++){
	        if(house[j].first>person[i].first && house[j].second<=person[i].second) {
	            M[i].push_back(j+n);
	            arr[i][j+n]=1;
	        };
	    };
	};
    for(int j=1; j<=m; j++){
        M[j+n].push_back(n+m+1);
        arr[j+n][n+m+1]=1;
    };
    
	
	
	printf("%d",maxFlow());
	
	
	return 0;
}
