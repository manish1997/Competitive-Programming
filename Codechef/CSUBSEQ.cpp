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
#define MAX 1000005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
string w,s;
int counts[26];
ll p2[20002];
ll tempcounts[26];
bool same(){
    rep(i,0,26) if(counts[i]!=tempcounts[i]) return false;
    return true;
}
int W;
ll hashes[200005];
unordered_map<ll,int> M;
unordered_map<ll,int> M2;
map<int,ll> M3;

void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>w>>s;
    
priority_queue<pair<int,ll> > PQ;
    M.clear();
    M3.clear();
    M2.clear();
    
    W=w.length();
    mem(counts,0);
    mem(tempcounts,0);
    
    rep(i,0,W) counts[w[i]-'a']++;
    
    ll currhash=0;
    rep(i,0,W-1){
        currhash=(((currhash*2)%mod)+(s[i]-'a'+1))%mod;
        tempcounts[s[i]-'a']++;
    }
    
    rep(i,W-1, s.length()){
        if(i-W>=0){
            currhash=(((currhash-(((s[i-W]-'a'+1)*p2[W-1])%mod))%mod)+mod)%mod;
            tempcounts[s[i-W]-'a']--;
        }
        currhash=(((currhash*2)%mod)+(s[i]-'a'+1))%mod;
        tempcounts[s[i]-'a']++;
        if(same()){
            M2[currhash]++;
            M[currhash]=i-W+1;
        }
    }
    for(auto it:M2){
        PQ.push(it);
    }
    
    ll ans=-1;
    string temp="";
    
    while(!PQ.empty()){
        pair<int,ll> currpa=PQ.top();
        PQ.pop();
        if(currpa.f>ans){
            ans=currpa.f;
            temp=s.substr(currpa.s,W);
        }
        else if(currpa.f==ans){
            if(s.substr(currpa.s,W)<temp){
                temp=s.substr(currpa.s,W);
            }
        }
        else{
            break;
        }
    }
    if(ans==-1) cout << -1 << endl;
    else cout << temp << endl;
    
}

int main(){
    fast_cin;
    int t=1; 
    cin >> t;
    p2[0]=1;
    rep(i,1,20002) p2[i]=(p2[i-1]*2LL)%mod;
    
    while(t--){
        solve();
    }
    return 0;
}