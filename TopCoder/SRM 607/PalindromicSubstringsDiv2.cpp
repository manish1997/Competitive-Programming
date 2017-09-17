#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
using namespace std;

string S;
int helper(int i){
    int ans=1;
    int start=i-1;
    int end=i+1;
    while(start>=0 && end<S.length() && S[start]==S[end]){
        ans++;
        start--;
        end++;
    }
    return ans;
}
int helper(int i, int j){
    int ans=0;
    int start=i;
    int end=j;
    while(start>=0 && end<S.length() && S[start]==S[end]){
        ans++;
        start--;
        end++;
    }
    return ans;
}
int solve(){
    ll ans=0;
    rep(i,0,S.length()){
        ans+=helper(i);
        if(i!=S.length()-1) ans+=helper(i,i+1);
    }
    return ans;
}
class PalindromicSubstringsDiv2 {
    public:
    int count(vector<string> S1, vector<string> S2) {
        S="";
        rep(i,0,S1.size()) S+=S1[i];
        rep(i,0,S2.size()) S+=S2[i];

        return solve();
    }
};

// CUT badsaegin
ifstream data("PalindromicSubstringsDiv2.sample");

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

bool do_test(vector<string> S1, vector<string> S2, int __expected) {
    time_t startClock = clock();
    PalindromicSubstringsDiv2 *instance = new PalindromicSubstringsDiv2();
    int __result = instance->count(S1, S2);
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
        vector<string> S1;
        from_stream(S1);
        vector<string> S2;
        from_stream(S2);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(S1, S2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed qith : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1505654368;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time  sadad : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  asda: " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "PalindromicSubstringsDiv2 (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
