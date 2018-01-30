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
int n,m;
string dir;
char arr[55][55];
bool valid(pair<int,int> P){
    if(P.f<0 || P.s<0 || P.f>=n || P.s>=m) return false;
    if(arr[P.f][P.s]=='#') return false;
    return true;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin >> n >> m;
    pair<int,int> start,end;
    rep(i,0,n){
        rep(j,0,m){
            cin>>arr[i][j];
            if(arr[i][j]=='S') start={i,j};
            else if(arr[i][j]=='E') end={i,j};
        }
    }
    cin>>dir;
    string temp="lrdu";
    ll ans=0;

    while(true){
        // tr1(temp);
        map<int,char> M;
        rep(i,0,4) M[i]=temp[i];
        pair<int,int> tempstart=start;
        bool correct=false;
        rep(i,0,dir.length()){
            if(M[dir[i]-'0']=='l'){
                tempstart.s-=1;
            }
            if(M[dir[i]-'0']=='r'){
                tempstart.s+=1;
            }
            if(M[dir[i]-'0']=='d'){
                tempstart.f+=1;
            }
            if(M[dir[i]-'0']=='u'){
                tempstart.f-=1;
            }
            if(valid(tempstart)==false){
                break;
            }
            if(tempstart==end){
                correct=true;
                break;
            }
        }
        if(correct){
            ans++;
        }
        bool temp2=next_permutation(temp.begin(),temp.end());
        if(temp=="lrdu") break;
    }
    tr1(ans);
    
}

int main(){
    fast_cin;
	//clock_t clk;
	//clk = clock();
	//srand (time(NULL));
    int t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
    //clk = clock() - clk;	
	//cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}