//TODO
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define mem(A,i) memset(A, i, sizeof(A))
using namespace std;
ll gcd ( ll  a, ll b ){
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}
bool LCMeasy(vector<int> S, int x){
    vector<ll> V;
    rep(i,0,S.size()) if(x%S[i]==0) V.push_back((ll)S[i]);
    if(V.size()==0) return false;
    ll ans=V[0];
    rep(i,1,V.size()) ans=abs(ans*V[i])/gcd(ans,V[i]);
    if(ans==x) return true;
    return false;
}
class LCMSet {
    public:
    string equal(vector<int> A, vector<int> B) {
        rep(i,0,A.size()) if(LCMeasy(B,A[i])==false) return "Not equal";
        rep(i,0,B.size()) if(LCMeasy(A,B[i])==false) return "Not equal";
        return "Equal";
    }
};

// CUT badsaegin
ifstream data("LCMSet.sample");

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

bool do_test(vector<int> A, vector<int> B, string __expected) {
    time_t startClock = clock();
    LCMSet *instance = new LCMSet();
    string __result = instance->equal(A, B);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED !" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED !" << " (" << elapsed << " seconds)" << endl;
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
        vector<int> A;
        from_stream(A);
        vector<int> B;
        from_stream(B);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(A, B, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed qith : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1505479327;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time  sadad : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  asda: " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "LCMSet (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
