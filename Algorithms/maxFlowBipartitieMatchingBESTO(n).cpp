#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%lld\n\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define MAX 100005
#define S second
#define F first
#define P pair<int,int>
#define PP pair<P,int>
using namespace std;
vector<vector<int> > M(50002);
int n,m,p;
bool visited[50002];
int A[50002];
int B[50002];

bool find_path(int x){
    for(auto i:M[x]){
        if(!visited[i])
            {
            visited[i]=true;
            if(B[i]==-1 || find_path(B[i]))
                {
                B[i] = x;
                A[x] = i;
                return true;
            }
        }
    }
    return false;
};


int main() {
    cin >> n >> m >> p;
	while(p--){
        int x,y;
        cin >> x >> y;
        M[x].push_back(y);
    };
	int result=0;
    memset(A,-1,sizeof(A));
    memset(B,-1,sizeof(B));
    for(int i=1; i<=n; i++){
        if(A[i]!=-1) continue;
        memset(visited, false, sizeof(visited));
        if(find_path(i)) result+=1;
    };
	//rep(i,0,(log2(5000)*5e7));
    cout << result;
	return 0;
}
