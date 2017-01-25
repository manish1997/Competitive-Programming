#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <climits>
#define ll long long
using namespace std;
int H,W; 

vector<pair<int,int>> V; // to store all the position corresponding to 'A'

int dp[52][52][28]; // to store values at indexes already visited

int grid[52][52]; // input grid

// helper function having position.x, position.y and corresponding required value at the point as inputs

int helper(int x, int y, int valueNeeded){

  // if value is not what we want or the index is out of bound(i.e. grid[i][j]=-1), it can't be the next step so terminate
  
  if(grid[x][y]==-1 || grid[x][y]!=valueNeeded) return INT_MIN;
	
  // if already visited then return the stored answer
  if(dp[x][y][valueNeeded]!=-1) return dp[x][y][valueNeeded];
	
  // path is atleast of 1 length
  int answer=1;
  
	// we can simply recurr on rest possible positions where we can go now i.e. check in all 8 directions
  // also we need (c+1) value at next step then only it's continuous i.e. for A we need B, for B we need C etc.
	int c=grid[x][y];
  
  // adding maximum of all the answers and 0 (in case no next step is feasible)
	answer+=max(max(helper(x-1,y-1,c+1), max(helper(x-1,y+1,c+1), 
						max(helper(x+1,y-1,c+1), helper(x+1,y+1,c+1))))
						,
						max(helper(x+1,y,c+1), max(helper(x-1,y,c+1), 
						max(helper(x,y-1,c+1), max(helper(x,y+1,c+1), 0)))));
	
  // store the value and return it
	return dp[x][y][valueNeeded]=answer;

};

int main() {
	int k=0;
	while(true){
		k++;
    scanf("%d%d",&H,&W);
		if(H==0 && W==0) break;
		
    // reseting all arrays
    memset(dp, -1, sizeof(dp));
		memset(grid, -1, sizeof(grid));
		V.clear();
    
		for(int i=1; i<=H; i++){
			string temp;
			cin >> temp;
			for(int j=1; j<=W; j++){
				grid[i][j]=temp[j-1]-'A';
				if(grid[i][j]==0) V.push_back(make_pair(i,j));
			//	cout << grid[i][j] << " ";
			};
			// cout << endl;
		};
    
    //minimum answer will be zero in case when no 'A' is there in the grid
		int tempAns=0;
		
    // running helper function on every possible candidate i.e. every 'A'
		for(int i=0; i<V.size(); i++) tempAns=max(tempAns, helper(V[i].first,V[i].second,0));
		
		printf("Case %d: %d\n",k,tempAns);
	};
	return 0;
};
