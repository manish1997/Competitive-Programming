#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)

using namespace std;

class TaroFriends {
    public:
    int getNumber(vector<int> V, int K) {
        // Theta(2*(n^2)*(n-1)).. need to read up editorial for better approach.. 
        // this do gets AC
        //O(n^2) is achiveable by.. RRRRRRL, RRRRRRLL, RRRRRLLL.........LLLLLLL
        int arr[2];
        arr[0]=1;
        arr[1]=-1;
        int n=V.size();
        int ans=INT_MAX;
        sort(V.begin(),V.end());
        ans=abs(V[V.size()-1]-V[0]);
        rep(i,0,n){
            rep(j,i+1,n){
                rep(x,0,2) rep(y,0,2){
                    int left=V[i]+arr[x]*K;
                    int right=V[j]+arr[y]*K;
                    if(left>right) swap(left,right);
                    bool flag=true;
                    rep(k,0,n){
                        if(k==i || k==j) continue;
                        int pos1=V[k]+K;
                        int pos2=V[k]-K;
                        if(!(pos1<=right && pos1>=left) && !(pos2<=right && pos2>=left)) flag=false;
                    }
                    if(flag) ans=min(ans,abs(left-right));
                }
            }
        }
        return ans;
    }
};

// CUT badsaegin
ifstream data("TaroFriends.sample");

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

bool do_test(vector<int> V, int X, int __expected) {
    time_t startClock = clock();
    TaroFriends *instance = new TaroFriends();
    int __result = instance->getNumber(V, X);
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
        vector<int> V;
        from_stream(V);
        int X;
        from_stream(X);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(V, X, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed qith : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1505484459;
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
        cout << "TaroFriends (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
