#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;
#define ll long long
#define si(n) cin >> n
#define sll(n) cin >> n
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%i64d\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define S second
#define F first
#define P pair<ll,ll>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 100005
#define newLine printf("\n")

int main(){
	ll t; si(t);
	while(t--){
		ll n; sll(n);
		ll x1,y1,y2,x2;
		sll(x1); sll(y1); sll(x2); sll(y2);
		if(y1==y2){
			printf("Draw\n");
			continue;
		}
		if(y1<=((n+1)/2)&& y2<=((n+1)/2)){
			//if(Miron is near midway he will surely win)
			//else if he can't block up/down of slewa in
			//first turn he will lose
			ll miron=((n+1)/2)-y1;
			ll slewa=((n+1)/2)-y2;
			if(miron<=slewa){
				printf("Miron\n");
			}
			else{
				if(abs(y1-y2)==1 && x1!=x2){
					printf("Draw\n");
				}
				else printf("Slava\n");
			}

		}
		else if(y1>=((n+2)/2)&& y2>=((n+2)/2)){
			ll miron=y1-((n+2)/2);
			ll slewa=y2-((n+2)/2);
			if(miron<=slewa){
				printf("Miron\n");
			}
			else{
				if(abs(y1-y2)==1 && x1!=x2){
					printf("Draw\n");
				}
				else printf("Slava\n");
			}
		}
		else if(n%2!=0){
			//left will try to go to (n+2)/2
			//right will try to come to (n+2)/2
			//whoever reaches first wins
			//miron's distance, slewa's distance 
			ll miron=abs(y1-((n+2)/2));
			ll slewa=abs(y2-((n+2)/2));
			if(x1==x2){
				if(miron<=slewa){
					printf("Miron\n");
				}
				else{
					printf("Slava\n");
				}
			}
			else {
				if(miron<slewa){
					printf("Miron\n");
				}
				else if(miron==slewa || (miron==slewa+1)){
					printf("Draw\n");
				}
				else{
					printf("Slava\n");
				}
			}
		}
		else {
			ll miron;
			ll slewa;
			if(y1<=((n+1)/2)){
				miron=abs(y1-((n+2)/2));
			}
			else{
				miron=abs(y1-((n+1)/2));
			}
			if(y2<=((n+1)/2)){
				slewa=abs(y2-((n+2)/2));
			}
			else{
				slewa=abs(y2-((n+1)/2));
			}
			if(x1==x2){
				if(miron<slewa){
					printf("Miron\n");
				}
				else if(miron==slewa || (miron==(slewa+1))){
					printf("Draw\n");
				}
				else{
					printf("Slava\n");
				}
			}
			else {
				if(miron==slewa || (miron==(slewa-1)) 
					|| (miron==(slewa+1)) || (miron==(slewa+2))){
					printf("Draw\n");
				}
				else if(miron<=(slewa-2)){
					printf("Miron\n");
				}
				else{
					printf("Slava\n");
				}
			}
		}
	}
}