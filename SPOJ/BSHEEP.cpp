#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sll(n) scanf("%lld", &n)
#define P pair<ll,ll>
#define F first
#define S second
ll t,n;
bool check[20002][20002];
bool used[100001];
P XY[100001];

ll crossProduct(int p, int i, int curr){
	ll x1,y1,x2,y2;
	x1=XY[i].F-XY[p].F;
	x2=XY[curr].F-XY[p].F;
	y1=XY[i].S-XY[p].S;
	y2=XY[curr].S-XY[p].S;
	return (x1*y2-x2*y1);
};

ll distance(int i, int p){
	ll f=XY[p].F-XY[i].F;
	ll s=XY[p].S-XY[i].S;
	f=f*f; s=s*s;
	return (f+s);
};

double distanceDouble(int i, int p){
	return sqrt(double(distance(i,p)));
};

int main() {
	sll(t);
	while(t--){
		memset(used, false, sizeof(used));
		memset(check, false, sizeof(check));
		sll(n);
		ll p=-1;
		ll diffCount=0;
		for(int i=0; i<n; i++){
			ll x,y;
			sll(x); sll(y);
			x+=10000;
			y+=10000;
			if(check[x][y]) {
				XY[i].F=-1;
				continue;
			};
			diffCount++;
			check[x][y]=true;
			XY[i].F=x; XY[i].S=y;
			if(p==-1 || XY[i].S < XY[p].S || (XY[i].S==XY[p].S && XY[i].F<XY[p].F)) p=i;
		};
		if(diffCount==1){
			printf("%s\n%d\n\n","0.00",1);
			continue;
		};
		ll maxAns=0;
		int ansIndexes[100002];
		ll start=p;
		do{
			ll curr=-1;
			ll d=0;
			for(int i=0; i<n; i++){
				
				// if already used or we started from this point only or not valid
				if(used[i] || i==p || XY[i].F==-1) continue;
				
				if(curr==-1) curr=i;
				
				ll cross=crossProduct(p,i,curr);
				
				ll dist=distance(p,i);
				
				if(cross>0){
					d=dist;
					curr=i;
				}
				else if(cross==0 && d<dist ){
						d=dist;
						curr=i;
				};
				
			};
			p=curr;
			used[curr]=true;
			ansIndexes[maxAns++]=curr;
		}
		while(start!=p);
		// while ends
		
		p=ansIndexes[maxAns-1];
		double answerPeri=0;
		for(int i=0; i<maxAns; i++){
			answerPeri+=distanceDouble(ansIndexes[i],p);
			p=ansIndexes[i];
		};
		printf("%.2lf\n",answerPeri);
		printf("%d ",ansIndexes[maxAns-1]+1);
		for(int i=0; i+1<maxAns; i++){
			printf("%d ",ansIndexes[i]+1);
		};
		printf("\n\n");
	};
	return 0;
}
