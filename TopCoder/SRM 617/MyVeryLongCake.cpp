#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define s second
#define f first

using namespace std;

class MyVeryLongCake {
    public:
    int cut(int n) {
        //n=999999999;
        unordered_map<int,int> M;
        int temp=n;
        int c=0;
        while(temp%2==0){
            temp/=2;
            c++;
        }
        if(c) M[2]=c;
        int k=3;
        while(true){
            c=0;
            while(temp%k==0){
                temp/=k;
                c++;
            }
            if(c) M[k]=c;
            k+=2;
            if(temp==1 || k>sqrt(n)) break;
        }
        if(temp!=1) M[temp]=1;
        int ans=1;
        for(auto it=M.begin(); it!=M.end(); it++){
            ans*=(pow(it->f,it->s)-pow(it->f,it->s-1));
        }
        ans=n-2-ans;
        return ans+2;
    }
};

// CUT badsaegin
ifstream data("MyVeryLongCake.sample");

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

bool do_test(int n, int __expected) {
    time_t startClock = clock();
    MyVeryLongCake *instance = new MyVeryLongCake();
    int __result = instance->cut(n);
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
        int n;
        from_stream(n);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed qith : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1505605423;
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
        cout << "MyVeryLongCake (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
