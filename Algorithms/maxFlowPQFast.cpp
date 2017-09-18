#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;
vector<vector<int> > M(2005);
pair<int,int> person[1001];
pair<int,int> house[1001];
#define P pair<int,int>
#define PP pair<int,P>
int arr[2005][2005];
int n,m; 
int from[2005];
bool visited[2005];
#define s second
#define f first
int find_aug_path(){
    priority_queue<PP> Q;
    Q.push(make_pair(INT_MAX, make_pair(0,-1)));
    int sink=n+m+1;
    memset(from, -1, sizeof(from));
    memset(visited, false, sizeof(visited));
    
    int capacity=INT_MAX;
    
    while(!Q.empty()){
        PP cur=Q.top();
        Q.pop();
        
        if(visited[cur.s.f]) continue;
        from[cur.s.f]=cur.s.s;
        if(cur.s.f==sink){
            capacity=cur.f;
            break;
        };
        visited[cur.s.f]=true;
        for(int i=0; i<=(n+m+1); i++){
            int next=i;
            if(arr[cur.s.f][next]>0){
                int new_cost=min(arr[cur.s.f][next],cur.f);
                Q.push(make_pair(new_cost, make_pair(next,cur.s.f)));
            };
            
        };
        
        
    };
   
    int prev;
    int curr=sink;
    if(capacity==INT_MAX) return 0;
    while(true){
        prev=from[curr];
        if(prev==-1) break;
        arr[prev][curr]-=capacity;
        arr[curr][prev]+=capacity;
        curr=prev;
    };
    return capacity;
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
	}
	for(int i=1; i<=m; i++){
		int ai,pi;
		scanf("%d%d",&ai,&pi);
		house[i]={ai,pi};
	}

	for(int i=1; i<=n; i++){
	    M[0].push_back(i);
	    arr[0][i]=1;
	    for(int j=1; j<=m; j++){
	        if(house[j].first>person[i].first && house[j].second<=person[i].second) {
	            M[i].push_back(j+n);
	            arr[i][j+n]=1;
	        }
	    }
	}
    for(int j=1; j<=m; j++){
        M[j+n].push_back(n+m+1);
        arr[j+n][n+m+1]=1;
    }
	
	
	cout << maxFlow();
	
	
	return 0;
}
