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
#define MAX 500005
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
int A[3][256];
void solve(){
    int n;cin>>n;
    int len;
    rep(i,0,3){
        string temp;cin>>temp;
        len=temp.length();
        rep(j,0,temp.length()) A[i][temp[j]-'A']++;
    }
    int beauty[3];
    mem(beauty,0);
    rep(i,0,3){
        rep(j,0,256) beauty[i]=max(beauty[i], A[i][j]);
        if(n!=1) beauty[i]=min(beauty[i]+n, len);
        else beauty[i]=beauty[i]==len?beauty[i]-1:beauty[i]+1;

    }
    if(beauty[0]>beauty[1] && beauty[0]>beauty[2]) cout << "Kuro\n";
    else if(beauty[1]>beauty[0] && beauty[1]>beauty[2]) cout << "Shiro\n";
    else if(beauty[2]>beauty[0] && beauty[2]>beauty[1])  cout << "Katie\n";
    else cout << "Draw" << endl;
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