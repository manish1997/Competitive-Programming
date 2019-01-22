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
#define MAX 100005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
int cnt;
string ask(ll a, ll b){
	cnt++;
	cout <<"? " << a << " " << b << endl;
	fflush(stdout);
	string s;cin>>s;
	return s;
}

int main(){
    fast_cin;
    string s;
    while(cin>>s){
    	if(s!="start"){
    		break;
    	}
    	cnt=0;
    	string ans = ask(1,2);

    	if(ans=="x"){
    		//a is 1 or 2
			ans=ask(2,1);

			if(ans=="y"){
				cout << "! " << 2 << endl;
				fflush(stdout);
			}
			else{
				cout << "! " << 1 << endl;
				fflush(stdout);	
			}
			continue;
    	}
    	//can't be 1/2 now
    	ll start= 2;
    	ll end= 4;
    	while(cnt<=60){
    		ans=ask(start, end);
    		if(ans=="y"){
    			start*=2;
    			end*=2;
    		}
    		else{
    			break;
    		}
    	}

    	ans=ask(end-1,end);

    	if(ans=="x"){
    		//ans is end or start. it can't be start
    		cout << "! " << end << endl;
    		fflush(stdout);
    		continue;
    	}
    	ll highest = end;

    	start++;
    	end--;
    	while(start<=end && cnt<=60){
    		ll mid = (start+end)>>1;
    		ans=ask(mid,highest);
    		if(ans=="x"){
    			start=mid+1;
    		}
    		else{
    			end=mid-1;
    		}
    	}

    	cout << "! "<< start << endl;
    	fflush(stdout);
    }
    return 0;
}