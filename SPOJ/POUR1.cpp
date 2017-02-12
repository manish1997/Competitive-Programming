#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>, bool>  dp;
int main() {
	// your code goes here
	int t; scanf("%d",&t);
	while(t--){
		dp.clear();
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		queue<pair<int,int> > Q;
		Q.push({a,0}); Q.push({0,b});
		int ans=1;
		queue<pair<int,int> > nextQ;
		dp[{0,0}]=true;
		bool answer=false;
		while(!Q.empty()){
			pair<int,int> temp= Q.front();
			Q.pop();
			
			if(temp.first==c || temp.second==c) {
				answer=true;
				break;
			};
			
			dp[{temp.first,temp.second}]=true;
			if(dp.find({0,temp.second})==dp.end()) nextQ.push({0,temp.second});
			if(dp.find({a,temp.second})==dp.end()) nextQ.push({a,temp.second});
			if(dp.find({temp.first,0})==dp.end()) nextQ.push({temp.first,0});
			if(dp.find({temp.first,b})==dp.end()) nextQ.push({temp.first,b});
			if(temp.first+temp.second>b){
				if(dp.find({temp.first-b+temp.second,b})==dp.end()) nextQ.push({temp.first-b+temp.second,b});
			}
			else{
				if(dp.find({0,temp.first+temp.second})==dp.end()) nextQ.push({0,temp.first+temp.second});
			};
			
			if(temp.first+temp.second>a){
				if(dp.find({a,temp.second-a+temp.first})==dp.end()) nextQ.push({a, temp.second-a+temp.first});
			}
			else{
				if(dp.find({temp.first+temp.second,0})==dp.end()) nextQ.push({temp.first+temp.second,0});
			};
			
			
			if(Q.empty() && ans++) {
				while(!nextQ.empty()) {
					Q.push(nextQ.front());
					nextQ.pop();
				};
			};
		};
		if(answer) printf("%d\n",ans);
		else printf("%d\n",-1);
		
	};
	return 0;
}
