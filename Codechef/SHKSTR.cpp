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
#define MAX (1<<17)+5
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);

struct node{
    node* chars[256];
    int minn;
    int end;
    node(){
        rep(i,0,256) chars[i]=NULL;
        minn=1e9;
        end=false;
        end=minn;
    }

};
node* root;
void add(string s, int val){
    node* curr=root;
    rep(i,0,s.length()){
        if(curr->chars[s[i]]==NULL){
            curr->chars[s[i]]=new node();
        }
        curr=curr->chars[s[i]];
        curr->minn=min(curr->minn, val);
        if(i==s.length()-1) curr->end=min(curr->end,val);
    }
}
string ans(string s, int val){
    node* curr=root;
    string a="";
    rep(i,0,s.length()){
        if(curr->chars[s[i]] && curr->chars[s[i]]->minn<=val){
            a.pb(s[i]);
            curr=curr->chars[s[i]];
        }
        else{
            break;
        }
    }
    while(true){
        if(curr->end<=val) break;
        rep(j,0,256){
            if(curr->chars[j] && curr->chars[j]->minn<=val){
                a.pb((char)j);
                curr=curr->chars[j];
                break;
            }
        }
    }
    return a;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    int n;
    cin>>n;
    root= new node();
    rep(i,1,n+1){
        string s;cin>>s;
        add(s,i);
    }
    int q;cin>>q;
    while(q--){
        int r;string s;
        cin>>r>>s;
        cout<<ans(s,r)<<endl;
    }
    
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