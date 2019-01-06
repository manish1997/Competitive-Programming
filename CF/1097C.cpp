#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define ll long long
string arr[MAX];
int n;

int helper(string str, bool rev){
	stack<char> S;
	
	if(rev){
		for(int i=str.length()-1; i>=0; i--){
			if(str[i]=='('){
				if(S.empty()){
					return -1;
				}
				S.pop();
			}
			else{
				S.push(str[i]);
			}
		}
	}
	else{
		for(int i=0; i<str.length(); i++){
			if(str[i]==')'){
				if(S.empty()){
					return -1;
				}
				S.pop();
			}
			else{
				S.push(str[i]);
			}
		}
	}
	return S.size();
}

void solve(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	pair<int,int> pre[n];
	ll ans=0;
	vector<int> first;
	map<int,int> second;
	for(int i=0; i<n; i++){
		pre[i].first=helper(arr[i], true);
		pre[i].second=helper(arr[i],false);
		if(pre[i].first==0 && pre[i].second==0){
			ans++;
		}
		else if(pre[i].first==-1){
			first.push_back(pre[i].second);
		}
		else{
			second[pre[i].first]++;
		}
	}
	
	
	ans/=2LL;
	
	for(int i=0; i<first.size(); i++){
		if(second.find(first[i])!=second.end()){
			ans++;
			second[first[i]]--;
			if(second[first[i]]==0){
				second.erase(first[i]);
			}
		}
	}
	cout << ans << endl;
	
	
	
	
	
	
	
}

int main() {
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}