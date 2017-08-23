#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define MAX 100005
#define S second
#define F first
#define P pair<int,int>
#define PP pair<P,int>
int AA[26];
int BB[26];
int main() {
	int t; cin >> t;
	while(t--){
		string a,b;
		cin >> a >> b;
		if(a.length()==1){
			cout << "B" << endl;
			continue;
		}
		memset(AA,0,sizeof(AA));
		memset(BB,0,sizeof(BB));
		for(int i=0; i<a.length(); i++){
			AA[a[i]-'a']++;
			BB[b[i]-'a']++;
		}
		int i;
		int j=-1;
		for(i=0; i<26; i++){
			if(AA[i]>0 && BB[i]==0){
				if(j==-1) j=i;
				else{
					if(AA[i]>AA[j]){
						j=i;
					}
				}
			}
		}
		if(j==-1){
			cout << "B" << endl;
			continue;
		}
		if(AA[j]>1){
			cout << "A" << endl;
			continue;
		}
		j=-1;
		for(i=0; i<26; i++){
			if(BB[i]>0 && AA[i]==0){
				j=i;
				break;
			}
		}
		if(j==-1){
			cout << "A" << endl;
			continue;
		}
		cout << "B" << endl;
	}
	return 0;
} 