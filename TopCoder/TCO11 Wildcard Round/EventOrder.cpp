#include <bits/stdc++.h>

using namespace std;

long long dp1[1001][3001];
long long dp2[1001][3001];

#define mod 1000000009;
class EventOrder {
    public:
    EventOrder(){
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));

    }
    long long add(long long &x, long long y){
        x=x+y;
        x%=mod;
        if(x<0) x+=mod;
        return x;
    }
    int getCount(int longEvents, int instantEvents) {
        int m=longEvents;
        dp1[0][0]=1;
        for(int i=0; i<m; i++){
            for(int j=0; j<2*m+1; j++){
                if(dp1[i][j]){
                    add(dp1[i+1][j],(dp1[i][j]*((j*(j-1))/2)));
                    add(dp1[i+1][j+1],(dp1[i][j]*(j*(j+1))));
                    add(dp1[i+1][j+2],(dp1[i][j]*(((j+1)*(j))/2)));
                    add(dp1[i+1][j+2],(dp1[i][j]*(((j+1)))));
                }
            }
        }
        int n=instantEvents;
        for(int i=0; i<2*m+n+1; i++){
            dp2[0][i]=dp1[m][i];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<2*m+n+1; j++){
                if(dp2[i][j]){
                    add(dp2[i+1][j],(dp2[i][j]*j));
                    add(dp2[i+1][j+1],(dp2[i][j]*(j+1)));
                }
            }
        }
        long long ans=0;
        for(int i=0; i<2*m+n+1; i++) add(ans,dp2[n][i]);
        return ans;
        
    }
};

// CUT begin
ifstream data("EventOrder.sample");

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

bool do_test(int longEvents, int instantEvents, int __expected) {
    time_t startClock = clock();
    EventOrder *instance = new EventOrder();
    int __result = instance->getCount(longEvents, instantEvents);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
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
        int longEvents;
        from_stream(longEvents);
        int instantEvents;
        from_stream(instantEvents);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(longEvents, instantEvents, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1504211276;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "EventOrder (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
