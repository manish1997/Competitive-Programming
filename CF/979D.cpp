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
#define MAX 100005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
bool check[MAX];
struct trie{
    trie* setbit[2];
    int minimum;
    trie(){
        minimum=1e6;
        setbit[0]=setbit[1]=NULL;
    }
}* tree[100005];


void add(int idx, int temp){
    trie* curr=tree[idx];
    curr->minimum=min(curr->minimum, temp);
    repDown(i,16,0){
        int c=(temp>>i)&1;
        if(curr->setbit[c]==NULL) curr->setbit[c]=new trie();
        curr=curr->setbit[c];
        curr->minimum=min(curr->minimum, temp);
    }
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    rep(i,0,MAX){
        tree[i]=new trie();
    }
    int q;cin>>q;
    while(q--){
        int type;cin>>type;
        if(type==1){
            int a;cin>>a;
            if(check[a]) continue;
            check[a]=true;
            for(int i=1; i*i<=a; i++){
                if(a%i) continue;
                add(i, a);
                if((i*i!=a)) add(a/i, a);
            }
        }
        else{
            int xi,ki,si;
            cin>>xi>>ki>>si;
            if(xi%ki){
                cout << -1 << endl;
                continue;
            }
            trie* curr=tree[ki];
            int maxx=si-xi;
            if(curr->minimum>maxx){
                cout << -1 << endl;
                continue;
            }
            ll ans=0;
            repDown(i,16,0){
                int c=(xi>>i)&1;
                if(curr->setbit[c^1] && curr->setbit[c^1]->minimum<=maxx){
                    curr=curr->setbit[c^1];
                    ans+=((c^1)<<(i));
                }
                else{
                    curr=curr->setbit[c];
                    ans+=(c<<i);
                }
            }
            cout << ans << endl;
        }
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