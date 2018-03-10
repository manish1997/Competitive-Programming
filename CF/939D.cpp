#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define mod 1000000007
#define MAX 1000005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
ll visited[26];
ll mat[26][26];
int n;
bool bfs(int node, int baap, int parent){
    if(node==baap) return true;
    visited[node]=1;
    for(int i=0; i<26; i++) if(mat[node][i]==1 && i!=parent && visited[i]==0 && bfs(i,baap, node)) return true;
    return false;
    
}
bool check(int a, int b){
    mem(visited,0);
    return bfs(a,b,-1);
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    mem(mat,0);
    cin>>n;
    string a,b;
    cin>>a;
    cin>>b;
    vector<pair<char,char> > ANS;
    
    rep(i,0,n){
        if(a[i]==b[i]) continue;
        
        if(check(a[i]-'a', b[i]-'a')){
            continue;
        }
        ANS.push_back({a[i], b[i]});
        mat[a[i]-'a'][b[i]-'a']=1;
        mat[b[i]-'a'][a[i]-'a']=1;
    }
    cout << ANS.size()<<endl;
    rep(i,0,ANS.size()) cout << ANS[i].f << " " << ANS[i].s << endl;
    
    
}

int main(){
    fast_cin;
    int t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}