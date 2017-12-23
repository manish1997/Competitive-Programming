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
// #define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
int n;
string arr[3005];
// string temp="abcdefghij";
int temparr[10];
int assign[10];
unordered_map<char,int> M;

vector<string> V[7];

bool comp(string a, string b){
    return (M[a[0]]>M[b[0]]);
}
void solve(){
    cin >> n;
    rep(i,0,n) {
        cin >> arr[i];
        V[arr[i].length()].pb(arr[i]);
        rep(j,0,arr[i].length()) M[arr[i][j]]++;
    }
    unordered_map<char, int> hash2;
    int first=1;
    bool f=false;
    int tr=0;
    repDown(i,6,1){
        if(V[i].size()==0) continue;
        sort(V[i].begin(), V[i].end(), comp);
        rep(j,0,V[i].size()){
            string curr=V[i][j];
            rep(k,0,curr.length())
            if(!f){
                hash2[curr[k]]=1;
                f=true;
            }
            else if(hash2.find(curr[k])==hash2.end()){
                hash2[curr[k]]=tr;
                tr++;
                if(tr==1) tr++;
            }
            
        }
    }
    ll temp=0;
    rep(i,0,n){
        rep(j,0,arr[i].length()){
            arr[i][j]='0'+hash2[arr[i][j]];
        }
        temp+=stol(arr[i]);
    }
    cout << temp << endl;   
}

int main(){
    fast_cin;
    clock_t clk;
    clk = clock();
    srand (time(NULL));
    int t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
    clk = clock() - clk;    
    cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}