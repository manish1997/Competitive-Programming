//tutorial: http://faculty.ycp.edu/~dbabcock/PastCourses/cs360/lectures/lecture23.html
int dp[MAX][MAX];
int W[MAX][MAX];
void floydWarshall(){
    int n=10; //nodes in graph
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j]=W[i][j];
            //base case without any intermediate vertex
        }
    }

    for(int k=1; k<=n; k++){
        //finding shortest path with k intermediate vertex
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                //ideally we should maintain 2 states with
                //k and k-1 intermediate vertexes
                //dp[2][i][j] but we don't need it because
                //dp[i][k]=i to k with k-1 intermediate vertex, also
                //dp[j][k]=j to k with k-1 intermediate vertex
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    //dp[i][j] equal shortest distance between i and j
}