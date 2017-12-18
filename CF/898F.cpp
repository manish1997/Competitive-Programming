#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
// #define pi 3.1415926535897
#define ll long long
#define si(n) scanf("%d",&n)
#define si2(n1,n2) scanf("%d%d",&n1,&n2)
#define si3(n1,n2,n3) scanf("%d%d%d",&n1,&n2,&n3)
#define sll(n) scanf("%lld",&n)
#define sll2(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll3(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
#define pin(n) printf("%d\n",n)
#define mem(A,i) memset(A, i, sizeof(A))
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define P pair<int,int>
#define PP pair<P,int>
#define mod1 1000000007
#define mod2 1000000009
#define MAX 100005
#define s second
#define f first
#define newLine printf("\n")
#define pb push_back
#define sieveMax 10001 //maximum for which u need primality test
 

 
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
    temp = (temp*temp)%m;
    if(n%2!=0) temp = (temp*x)%m;
    return temp;
}

string s;
int n;

ll hashtemp[5][1000002];
ll pre[5][1000002];
ll inv[5][1000002];
ll MOD[5];

ll getHash(int start, int end, int num){
	//inverse lena hai 10^start ke sath
	// cout << start << " st " << end << endl;
	if(start>end)return 0;
	// cout << hashtemp[8] << endl;
	ll temp=(hashtemp[num][start]-hashtemp[num][end+1])%MOD[num];
	if(temp<0) temp+=MOD[num];
	temp = (temp*inv[num][n-end+1])%MOD[num];
	return temp;
}

bool check(int start1, int end1, int start2, int end2){
	if(s[start1]=='0' && end1-start1+1>1) return false;
	if(s[start2]=='0' && end2-start2+1>1) return false;
	if(s[end2+1]=='0' && (s.length()-end2-1)>1) return false;


	bool ans=true;
	rep(f,0,5){
		ll hash1=getHash(start1+1, end1+1, f);
		ll hash2=getHash(start2+1, end2+1, f);
		ll hash3=getHash(end2+2, s.length(), f);
		if((hash1+hash2)%MOD[f]!=hash3) ans=false;
	}
	if(!ans) return false;
	rep(i,0,end1+1) printf("%c", s[i]);
	printf("+");
	rep(i,start2,end2+1) printf("%c", s[i]);
	printf("=");
	rep(i,end2+1, s.length()) printf("%c", s[i]);
	return true;
}

void solve(){
	cin >> s;
	n=s.length();
	rep(f,0,5){
		pre[f][0]=1;
		hashtemp[f][0]=0;
		inv[f][0]=1;
	}
	MOD[0]=1000002089;
	MOD[1]=1000002103;
	MOD[2]=1000002139;
	MOD[3]=1000002149;
	MOD[4]=1000002161;
	ll store[5];
	rep(f,0,5) store[f]=expo(10,MOD[f]-2,MOD[f]);
	// cout << store[1] << endl;


	rep(f,0,5){
		rep(i,1,s.length()+1){
			pre[f][i]=(pre[f][i-1]*10)%MOD[f];
			inv[f][i]=(inv[f][i-1]*store[f])%MOD[f];
		}
	}
	rep(f,0,5){
		hashtemp[f][s.length()+1]=0;
		repDown(i,s.length(),1){
			hashtemp[f][i]=((hashtemp[f][i+1])+(((s[i-1]-'0')*pre[f][n-i+1])%MOD[f]))%MOD[f];
		}
	}
	rep(len,1,n-1){
		//assumed length of solution is len
		if(check(0,len-1, len, n-len-1)) return;
		if(check(0,len-2, len-1, n-len-1)) return;
		if(check(0,n-2*len-1, n-2*len, n-len-1)) return;
		if(check(0,n-2*len, n-2*len+1, n-len-1)) return;
	}
	
}

int main(){
    int t=1; //si(t);
    while(t--){
        solve();
        // cout << getHash(6,9) << endl;
    }
    return 0;
}  