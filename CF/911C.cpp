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

void solve(int a,int b,int c){
    //solve the problem. You can and you will :) give your best shot..
    // rep(k1,1,10)rep(k22,1,10)rep(k3,1,10){

        int k2[3];
        k2[0]=a;
        k2[1]=b;
        k2[2]=c;
    bool gr=false;
    rep(i,0,3) {
        // cin >> k2[i];
        if(k2[i]==1) {
            cout << "YES"<<endl;
            return;
        }
        if(k2[i]>50) gr=true;
    }
    sort(k2,k2+3);
    if(k2[0]==k2[1] && k2[1]==2){
        cout << "YES"<<endl;
        return;
    }
    // cout << "NO";
    if(gr){
        cout <<"NO"<<endl;
        return;
    }
    bool temp[1000];
    for(int x1=1;x1<=50; x1++){
        for(int x2=1; x2<=50; x2++){
            for(int x3=1; x3<=50; x3++){
                mem(temp,false);
                for(int k=x1; k<=500; k+=k2[0]) temp[k]=true;
                for(int k=x2; k<=500; k+=k2[1]) temp[k]=true;
                for(int k=x3; k<=500; k+=k2[2]) temp[k]=true;
                bool ans=true;
                for(int k=max(x1,max(x2,x3)); k<=500; k++){
                    if(temp[k]==false) ans=false;
                }
                if(ans) {
                    cout <<"YES" <<endl;
                    // cout << k2[0] <<" " << k2[1] << " " << k2[2] << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" <<endl;

// }
    
}

int main(){
    fast_cin;
	//clock_t clk;
	//clk = clock();
	//srand (time(NULL));
    int t=1; 
    // cin >> t;
    // while(t--){
    //     solve();
    // }
    rep(k1,1,7)rep(k2,1,7)rep(k3,1,7){solve(k1,k2,k3);};
    //clk = clock() - clk;	
	//cerr << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}