#include <iostream>
#include <climits>
using namespace std;
#define ll long long
#define si(n) cin >> n
#define sll(n) cin >> n
#define pin(n) cout << n << endl
#define plln(n) cout << n << endl
#define pis(n) cout << n << " "
#define plls(n) cout << n << " "
#define rep(i, start, end) for(ll i=start; i<end; i++)
 
ll R,C, N;
ll arr[10][2];
ll matrix[1000][1000];
ll dp[1000][1000][256];
bool valid(int i, int j){
	return (i>=0 && i<R && j>=0 && j<C);
}
int dx[2];
int dy[2];
 
ll helper2(int x, int y, int curr){
	ll &answer=dp[x][y][curr];
	if(answer!=-1) return answer;
	answer=0;
	rep(i,0,N){
		if(((1<<i)&curr)==0){
 
			rep(j,0,2){
				rep(k,0,2){
					int xx=x+dx[j]*arr[i][0];
					int yy=y+dy[k]*arr[i][1];
					if(valid(xx,yy)) answer=max(answer, helper2(xx,yy, curr+(1<<i)));
				}
 
			}
 
		}
	}
	answer=(answer+matrix[x][y]);
	return answer;
}
ll helper(int x, int y, int curr){
	ll &answer=dp[x][y][curr];
	if(answer!=-1) return answer;
	answer=0;
	rep(i,0,N){
		if(((1<<i)&curr)){
 
			rep(j,0,2){
				rep(k,0,2){
					int xx=x+dx[j]*arr[i][0];
					int yy=y+dy[k]*arr[i][1];
					if(valid(xx,yy)) {
					//	cout << x << " valid " << y << " " << curr << endl;
						answer=max(answer, helper(xx,yy, curr-(1<<i)));
					}
				}
 
			}
 
		}
	}
	answer=(answer+matrix[x][y]);
	return answer;
}
int main(){
	std::ios::sync_with_stdio(false);
	int t; si(t);
	dx[0]=1;
	dx[1]=-1;
	dy[0]=1;
	dy[1]=-1;
	while(t--){
		sll(R); sll(C); sll(N);
		int sx,sy;
		si(sx); si(sy);
		rep(i,0,N)
			sll(arr[i][0]);
		rep(i,0,N)
			sll(arr[i][1]);
		rep(i,0,R) rep(j,0,C) {
			sll(matrix[i][j]);
			rep(k,0,256) dp[i][j][k]=-1;
		}
		if(N>8){
			cout << 1 << endl;
			continue;
		}
		cout <<helper(sx,sy,(1<<N)-1) << endl;
	}
	return 0;
} 