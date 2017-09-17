#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)

using namespace std;

class MagicalStringDiv1 {
    public:
    int getLongest(string S) {
        int start[50];
        int back[50];
        int temp=0;
        rep(i,0,S.length()){
            if(S[i]=='>') temp++;
            start[i]=temp;
        }
        temp=0;
        repDown(i,S.length()-1, 0){
            if(S[i]=='<') temp++;
            back[i]=temp;
        }
        int ans=INT_MAX;
        rep(i,0,S.length()){
            if(S[i]=='<'){
                if(i==0){
                    ans=min(ans,(int)S.length());
                    continue;
                }
                int s=start[i-1];
                int b=back[i];
                s=min(s,b);
                ans=min(ans,(int)S.length()-2*s);
            }
            else{
                if(i==S.length()-1){
                    ans=min(ans,(int)S.length());
                    continue;
                }
                int s=start[i];
                int b=back[i+1];
                s=min(s,b);
                ans=min(ans, (int)S.length()-2*s);
            }
        }

        return (S.length()-ans);
    }
};

// CUT badsaegin
ifstream data("MagicalStringDiv1.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(string S, int __expected) {
    time_t startClock = clock();
    MagicalStringDiv1 *instance = new MagicalStringDiv1();
    int __result = instance->getLongest(S);
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
        string S;
        from_stream(S);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(S, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed qith : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1505476815;
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
        cout << "MagicalStringDiv1 (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
