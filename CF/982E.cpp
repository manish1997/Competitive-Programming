
#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define MAX 500005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n,m,x,y,vx,vy;
pair<int,int> arr[4];
ll xGCD(ll a,ll b,ll &x,ll &y){
	if(!b){
		x = 1,y = 0;
		return a;
	}
	ll t = xGCD(b,a%b,y,x);
	y-=a/b*x;
	return t;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
	cin>>n>>m>>x>>y>>vx>>vy;
	arr[0]={0,0};
	arr[1]={n,0};
	arr[2]={n,m};
	arr[3]={0,m};

	if(vx==0){
		if(x!=n && x!=0){
			cout << -1 << endl;
			return;
		}
		if(x==n){
			if(vy==1) cout << n << " " << m << endl;
			else cout << n <<" " << 0 << endl;
		}
		else{
			if(vy==1) cout << 0 << " " << m << endl;
			else cout << 0 <<" " << 0 << endl;	
		}
		return;
	}
	else if(vy==0){
		//if(y==m || y==0)
		if(y!=m && y!=0){
			cout << -1 << endl;
			return;
		}
		if(y==m){
			if(vx==1) cout << n << " " << m << endl;
			else cout << 0 <<" " << m << endl;
		}
		else{
			if(vx==1) cout << n << " " << 0 << endl;
			else cout << 0 <<" " << 0 << endl;	
		}
		return;
	}
	if(vx==-1){
		swap(arr[0], arr[1]);
		swap(arr[2], arr[3]);
		x=n-x;
	}
	if(vy==-1){
		swap(arr[0], arr[3]);
		swap(arr[1], arr[2]);
		y=m-y;
	}
	//Y=mX+c;
	//m==1;
	ll c=x-y;
	//Y-X-y+x=0;
	//X will be k1*n, Y will be k2*m
	//k1*n-k2*m=c //this is the equation we are solving for
	ll k1=0,k2=0;
	ll gc=xGCD(n,m,k1,k2);
	if(c%gc){
		cout << -1 << endl;
		return;
	}
	k1*=(c/gc);//this will help in making it (nx+my=c) equal to c irrespective of c's sign
	k2*=(c/gc);//this will help in making it (nx+my=c) equal to c irrespective of c's sign
	k2*=-1; // because gcdExtended solves (a*x+b*y=c), if b<0, we can say a*x-b*(-y)=c
	// therefore we have multiplies k2 (y) by -1. 
	// now general solution will be
	// kfirst= k1+(t*(-m)/gc)  => kfirst = k1 -t*m/gc
	// ksecond = k1 - t*(n/gc)
	// as we can see our line has slope 1, so both kfirst and ksecond
	// will either increase or decrease. t belongs to I
	while(k1<=0){
		k1+=(m/gc);
	}
	while(k1>(m/gc)) k1-=(m/gc);
	k2=(-c+k1*n)/m;
	//k2 will always be greater than zero in this case as
	// k1*n will always be >(x-y).. max*x-y=n
	// but n,0 is not possible as ball can't be on hole
	// so c<n, this can't be true always 
	// because k1*n may be less than c sometimes.. (but not always)
	// so in that case,, we can move from current k2 (slope is 1)
	// and find first positive k2 as k1 will always be positive for that
	while(k2<=0){
		k2+=(n/gc);
		k1+=(m/gc);
		//because m is negative. 
		//formula is. y=y0-t(a/gcd)
		// x=x0+t(b/gcd),  t belongs to I
		//so, y=y0-tn/gcd
		//x=x0-ym/gcd
	}
	//mirroring technique for question
	if((k1%2)==0){
		swap(arr[0], arr[1]);
		swap(arr[2], arr[3]);
	}
	if((k2%2)==0){
		swap(arr[0], arr[3]);
		swap(arr[1], arr[2]);
	}
	cout << arr[2].f <<" " << arr[2].s << endl;
}
int main(){
	fast_cin;
	solve();
	return 0;
}
