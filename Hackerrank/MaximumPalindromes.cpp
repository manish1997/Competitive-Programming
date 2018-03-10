#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define mod 1000000007
#define ll long long
string s;
int n;
int FR[100005][26];
ll pre[100005];
ll xpre[100005];

//Modulus Expo
ll expo(ll x, ll n, ll m){
    if(n==0) return 1;
    ll temp=expo(x,n/2,m);
    temp = ((temp%m)*(temp%m))%m;
    if(n%2!=0) temp = ((temp%m)*(x%m))%m;
    return temp;
}
//end Modulus Expo

int main() {
    pre[0]=1;
    for(long long i=1; i<=100000; i++){
        pre[i]=(pre[i-1]*i)%mod;
    }
    xpre[0]=1;
    for(long long i=1; i<=100000; i++){
        xpre[i]=expo(pre[i], mod-2, mod);
    }
    
    cin>>s;
    for(int i=0; i<s.length(); i++){
        if(i==0) FR[i][s[i]-'a']++;
        else{
            for(int j=0; j<26; j++) FR[i][j]=FR[i-1][j];
            FR[i][s[i]-'a']++;
        }
    }
    n=s.length();
    int q; cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        vector<int> V(26);
        for(int i=0; i<26; i++) V[i]=FR[r][i]-(l==0?0:FR[l-1][i]);
        int len=0;
        int odd=0;
        for(int i=0; i<26; i++){
            if(V[i]%2) odd++;
            len+=(V[i]/2);
        }
        ll ans=pre[len];
        for(int i=0; i<26; i++){
            ans=(ans*xpre[V[i]/2])%mod;
            
        }
        if(odd==0) odd=1;
        cout << (ans*odd)%mod << endl;
    }
    return 0;
}
