//TODO, failed System test
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define mem(A,i) memset(A, i, sizeof(A))
using namespace std;
int parent[1100];
int weights[1100];
vector<int> adj[1100];
int dp[1100];
#define s second
#define f first
int recur(int node){
    if(dp[node]!=-1) return dp[node];

    if(adj[node].size()==0) return dp[node]=weights[node];
    // int ans=0;
    int curr=0;
    int maxx=0;

    vector<pair<int,int> > childsans;
    int maxx2=weights[node];
    
    for(int i=0; i<adj[node].size(); i++){
        childsans.push_back({recur(adj[node][i]),adj[node][i]});
        maxx2+=weights[adj[node][i]];
    }
    sort(childsans.begin(), childsans.end());
    for(int i=childsans.size()-1; i>=0; i--){
        maxx=max(maxx, childsans[i].f+curr);
        curr+=weights[childsans[i].s];
    }

    return dp[node]=max(maxx, maxx2);
}
class StonesOnATreeDiv2 {
    public:
    int minStones(vector<int> p, vector<int> w) {
        mem(dp,-1);
        rep(i,0,1100) adj[i].clear();
        rep(i,0,1100) weights[i]=0;
        rep(i,0,p.size()) adj[p[i]].push_back(i+1);

        rep(i,0,w.size()) weights[i]=w[i];
        // recur(3);
        // cerr << dp[5] << endl;
        return recur(0);
    }
};

// CUT badsaegin
ifstream data("StonesOnATreeDiv2.sample");

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

bool do_test(vector<int> p, vector<int> w, int __expected) {
    time_t startClock = clock();
    StonesOnATreeDiv2 *instance = new StonesOnATreeDiv2();
    int __result = instance->minStones(p, w);
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
        vector<int> p;
        from_stream(p);
        vector<int> w;
        from_stream(w);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(p, w, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed qith : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1519129249;
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
        cout << "StonesOnATreeDiv2 (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
