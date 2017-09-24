#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define mod 1000000007
#define si(n) scanf("%d",&n)
#define si2(n1,n2) scanf("%d%d",&n1,&n2)
#define si3(n1,n2,n3) scanf("%d%d%d",&n1,&n2,&n3)
#define sll(n) scanf("%lld",&n)
#define sll2(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll3(n1,n2,n3) scanf("%lld%lld%lld",&n,&n2,&n3)
#define pin(n) printf("%d\n",n)
#define mem(A,i) memset(A, i, sizeof(A))
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define INF 1000008
#define maxn 105

ll gcd ( ll  a, ll b ){
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}
string inputString(){
    string i="";
    int temp=getchar();
    while(temp<'a'||temp>'z')
        temp=getchar();
    while(temp>='a'&&temp<='z')
    {
        i+=(char)temp;
        temp=getchar();
    }
    return i;
}

ll expo(ll x, ll n, ll m){
	if(n==0) return 1;
	ll temp=expo(x,n/2,m);
	temp = ((temp%m)*(temp%m))%m;
	if(n%2!=0) temp = ((temp%m)*(x%m))%m;
	return temp;
}

long long add(long long &x, long long y){
        x=x+y;
        x%=mod;
        if(x<0) x+=mod;
        return x;
}
void reset(){
    //check if your logic is correct but still wrong answer

}
int graph[maxn][maxn],n;
double dp[205][100];
void floydWarshall() {
for( int k = 1; k <= n; k++ )
for( int i = 1; i <= n; i++ )
for( int j = 1; j <= n; j++ )
graph[i][j] = min( graph[i][j], graph[i][k] + graph[k][j] );
}
int go(int x){
    int ans=0;
    rep(i,1,n+1) ans+=graph[x][i];
    return ans;
}
double sum1, sum2, N, P;
int p;
double go1(){
	double temp=(-1/(N-1.0));
    temp=pow(temp,p-1);
    double ans=0;
    ans=1-temp;
    ans=ans*(sum2*P);
    ans/=(N*(N-1));
    temp*=(-1.0/(N-1.0));
    temp=1-temp;
    temp*=sum1;
    temp/=N;
    ans+=temp;
    return ans;
}
double go2(){
	double ans=0.0;
    if(p%2) ans+=(sum2*((p/2)));
    else ans+=sum2*((p/2)-1)-sum2*(p-1);
    return ans;
}
double go3(){
	double ans=0.0;
    float num=1.0;
    double deno=(N-1)*(N-1);

    for(int i=2; i<=min(p,INF); i++){
        ans+=(pow(-1,i)*(num/deno));deno*=(N-1);num+=1.0;
    }
    ans*=-1*sum2;
    return ans;
}
void solve(){
	    //solve the problem. You can and you will :) give your best shot..

        int m;si3(n,m,p);  
        rep(i,0,maxn)
        	rep(j,0,maxn)
	            if(i==j) graph[i][j]=0;
	            else graph[i][j]=INF;

        rep(i,0,m){
            int x,y,z;
            si3(x,y,z);
            graph[x][y]=z;
            graph[y][x]=z;
        }
        floydWarshall();
        if(p<=200){
	        rep(i,1,1+p){
	            rep(j,1,1+n){
	                if(i==1){dp[i][j]=go(j)/(double)(n-1);}
	                else{
	                    dp[i][j]=0;
	                    rep(k,1,1+n){
	                        if(k==j)continue;
	                        dp[i][j]+=(dp[i-1][k]+graph[j][k]);
	                    }
	                    dp[i][j]=dp[i][j]/(double)(n-1);
	                }
	            }
	        }
	        printf("%.8f\n",dp[p][1]);
	        return;
    	}
    	sum1=go(1);
    	sum2=0.0;
    	rep(i,1,n+1) sum2+=go(i);
    	P=p;
    	N=n;
    	double ans=go1();
    	if(n==2) printf("%.8f\n",ans+go2());
    	else printf("%.8f\n",ans+go3());
        return;
}
int main(){
    int t;si(t);
    int x=1;
    while(t--){
        printf("Case #%d: ", x++);
        solve();
    }
    return 0;
}