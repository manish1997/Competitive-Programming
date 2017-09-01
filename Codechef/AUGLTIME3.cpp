#include <iostream>
using namespace std;
int R,C, N;
int arr[10][2];
int matrix[1000][1000];
int dp[1000][1000][512];
bool valid(int i, int j){
	return (i>=0 && i<R && j>=0 && j<C);
}
int row[4]={1,1,-1,-1};
int col[4]={1,-1,1,-1};
int helper(int x, int y, int curr){
	if(curr==((1<<N)-1)) return matrix[x][y];
	if(dp[x][y][curr]) return dp[x][y][curr];
	int answer=0,xx,yy,i,j,k;
	for(i=0; i<N; i++){
		k=1<<i;
		if(!(k&curr)){
			for(j=0; j<4; j++){
				xx=x+row[j]*arr[i][0];
				yy=y+col[j]*arr[i][1];
				if(valid(xx,yy)) answer=max(answer, helper(xx,yy, curr|(1<<i)));
			}
		}
	}
	dp[x][y][curr]=(answer+matrix[x][y]);
	return dp[x][y][curr];
}
int main(){
	int t,i,j,k,sx,sy,tempp; scanf("%d",&t);
	while(t--){
		scanf("%d%d%d", &R, &C, &N);
		scanf("%d%d", &sx, &sy);
		for(i=0; i<N; i++)
			scanf("%d", &arr[i][0]);
		for(i=0; i<N; i++)
			scanf("%d", &arr[i][1]);
		for(i=0; i<R; i++) for(j=0; j<C; j++) {
			scanf("%d", &matrix[i][j]);
		}
		tempp=1<<N;
		for(i=0; i<R; i++) for(j=0; j<C; j++) {
			for(k=0; k<tempp; k++) dp[i][j][k]=0;
		}
		printf("%d\n",helper(sx,sy,0));
	}
	return 0;
}