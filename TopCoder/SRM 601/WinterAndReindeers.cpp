#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%dn",n)
#define plln(n) printf("%lldn",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define P pair<int,int>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 500005
#define s second
#define f first
#define newLine printf("n")
#define mem(A,i) memset(A, i, sizeof(A))
using namespace std;

int checkSubsequence(string A, int i, string B, int j){
        //BASE CASE
        if(i==A.length() && j<B.length()) return 0;
        if(j>=B.length()) return 1;
        if(A[i]==B[j]){
            return checkSubsequence(A,i+1,B,j+1);
        }
        return checkSubsequence(A,i+1,B,j);
}
int CA[2502];
int CB[2502];
string A,B,C;
void setCACB(){
    // cerr << A <<" " << B<<" " <<  C<<endl;
    for(int i=0; i<A.length(); i++){
        int j=i,k=0;
        while(k<C.length() && j<A.length()){
            if(A[j]==C[k]) k++;
            j++;
        }
        if(k==C.length()) CA[i]=j;
        // cerr << CA[i] <<endl;
    }
    for(int i=0; i<B.length(); i++){
        int j=i,k=0;
        while(k<C.length() && j<B.length()){
            if(B[j]==C[k]) k++;
            j++;
        }
        if(k==C.length()) CB[i]=j;
        // cerr << CB[i] <<endl;
    }

}
int dp[2502][2502][2];
int helper(int i, int j, int d){
    if(i>=A.length() || j>=B.length()){
        if(d) return INT_MIN;
        return 0;
    }
    if(dp[i][j][d]!=-1) return dp[i][j][d];
    if(d==0){
        if(A[i]==B[j]) return dp[i][j][d]=1+helper(i+1,j+1,d);
        return dp[i][j][d]=max(helper(i+1,j,d),helper(i,j+1,d));
    }
    int &ans=dp[i][j][d];
    ans=0;
    int a=CA[i];
    int b=CB[j];


    if(a!=-1 && b!=-1){
        ans=max(ans, (int)C.length()+helper(a,b,0));
    }
    else{
        return dp[i][j][d]=INT_MIN;
    }
    // cerr << A.substr(i) << " " << B.substr(j) <<" " << C << " " << k << endl;
    // cerr << ans << endl;
    if(A[i]==B[j]) ans=max(ans, 1+helper(i+1,j+1,d));
    ans=max(ans, helper(i,j+1,d));
    ans=max(ans, helper(i+1,j,d));
    return ans;
}

class WinterAndReindeers {
    public:
    
    int getNumber(vector<string> allA, vector<string> allB, vector<string> allC) {
        A="";B="";C="";
        mem(dp,-1);
        mem(CA,-1);
        mem(CB,-1);
        rep(i,0,allA.size()) A+=allA[i];
        rep(i,0,allB.size()) B+=allB[i];
        rep(i,0,allC.size()) C+=allC[i];
        setCACB();
        if(checkSubsequence(A,0,C,0)==0 || checkSubsequence(B,0,C,0)==0) return 0;
        return helper(0,0,1);
    }

};

// CUT badsaegin
ifstream data("WinterAndReindeers.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<string> allA, vector<string> allB, vector<string> allC, int __expected) {
    time_t startClock = clock();
    WinterAndReindeers *instance = new WinterAndReindeers();
    int __result = instance->getNumber(allA, allB, allC);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED bb!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED !" <<A << " " << B<< " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<string> allA;
        from_stream(allA);
        vector<string> allB;
        from_stream(allB);
        vector<string> allC;
        from_stream(allC);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(allA, allB, allC, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed qith : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1505224680;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time  sadad : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  asda: " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "WinterAndReindeers (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
