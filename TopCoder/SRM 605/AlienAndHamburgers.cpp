#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, start, end) for(ll i=start; i<end; i++)
using namespace std;

bool comp(int a, int b){
    return a>b;
}
class AlienAndHamburgers {
    public:
    int getNumber(vector<int> type, vector<int> taste) {
        vector<int> V[101];
        rep(i,0,type.size()) {
            V[type[i]].push_back(taste[i]);
        }
        int t=0;
        int ans=0;
        rep(i,0,101){
            if(V[i].size()==0) continue;
            sort(V[i].begin(),V[i].end(), comp);
            if(V[i][0]<0) continue;
            t++;
            rep(j,0,V[i].size()){
                if(V[i][j]<0) break;
                ans+=V[i][j];
            }
        }
        vector<int> temp;
        rep(i,0,101){
            if(V[i].size()==0 || V[i][0]>=0) continue;
            temp.push_back(V[i][0]);
        }
        sort(temp.begin(), temp.end(),comp);
        rep(i,0,temp.size()){
            if(((t+1)*(ans+temp[i]))>=(t*(ans))){
                t++;
                ans+=temp[i];
            }
        }
        return t*ans;
    }
};

// CUT badsaegin
ifstream data("AlienAndHamburgers.sample");

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

bool do_test(vector<int> type, vector<int> taste, int __expected) {
    time_t startClock = clock();
    AlienAndHamburgers *instance = new AlienAndHamburgers();
    int __result = instance->getNumber(type, taste);
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
        vector<int> type;
        from_stream(type);
        vector<int> taste;
        from_stream(taste);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(type, taste, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed qith : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1505339129;
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
        cout << "AlienAndHamburgers (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
