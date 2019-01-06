#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll unsigned long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define mod2 1000000033
#define MAX 1003
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
ll b1 = 29;
ll b2 = 31;
struct trie{
    trie* next[26];
    bool visited;
    trie(){
        visited=false;
        for(int i=0; i<26; i++){
            next[i]=NULL;
        }
    }
};
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    string s;
    cin>>s;
    string str;cin>>str;
    int maxx;cin>>maxx;
    trie* root = new trie();
    for(int i=0; i<s.length(); i++){
        trie* temp = root;
        for(int j=i; j<s.length(); j++){
            if(temp->next[s[j]-'a']==NULL){
                temp->next[s[j]-'a']=new trie();
            }
            temp=temp->next[s[j]-'a'];
        }
    }
    
    int ans=0;

    for(int i=0; i<s.length(); i++){
        trie* temp = root;
        int k=0;
        for(int j=i; j<s.length(); j++){
            k+=(str[s[j]-'a']=='0');
            temp=temp->next[s[j]-'a'];
            if(k<=maxx && temp->visited==false){
                ans++;
                temp->visited=true;
            }

        }
    }
    cout << ans << endl;
    

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