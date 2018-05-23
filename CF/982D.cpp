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
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
int n;

pair<int,int> arr[MAX];
int BIT[MAX];
int maxsize,eqmaxsize,locations;

void update(int idx, int val){
	while(idx<=n){
		BIT[idx]+=val;
		idx+=(idx&-idx);
	}
}

int query(int idx){
	int ret=0;
	while(idx>0){
		ret+=BIT[idx];
		idx-=(idx&-idx);
	}
	return ret;
}
int size(int type, int idx){
	if(type==0){
		int start=1;
		int end=idx;
		while(start<=end){
			int mid=(start+end)>>1;
			if(query(idx)-query(mid-1)==(idx-mid+1)){
				end=mid-1;
			}
			else{
				start=mid+1;
			}
		}
		return idx-end;
	}
	else{
		int start=idx;
		int end=n;
		while(start<=end){
			int mid=(start+end)>>1;
			if(query(mid)-query(idx-1)==mid-idx+1){
				start=mid+1;
			}
			else{
				end=mid-1;
			}
		}
		return end-idx+1;
	}
}
bool comp(pair<int,int> A, pair<int,int> B){
	if(A.f!=B.f) return A.f>B.f;
	return A.s<B.s;
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n;
    rep(i,1,n+1){
    	cin>>arr[i].f;
    	arr[i].s=i;
    }

    sort(arr+1,arr+n+1);
    vector<pair<int,int> > ans;

    rep(i,1,n+1){
    	int curr=arr[i].f;
    	int idx=arr[i].s;
    	int last=query(idx-1)-((idx>=2)?query(idx-2):0);
    	int next=query(idx+1)-query(idx);

    	if(last&&next){
    		int leftsize=size(0,idx-1);
    		int rightsize=size(1,idx+1);
    		if(leftsize==maxsize) eqmaxsize--;
    		if(rightsize==maxsize) eqmaxsize--;
    		locations-=1;
    		if(leftsize+rightsize+1>maxsize){
    			maxsize=leftsize+rightsize+1;
    			eqmaxsize=1;
    		}
    		else if(leftsize+rightsize+1==maxsize){
    			eqmaxsize+=1;
    		}
    		if(eqmaxsize==locations){
    			ans.pb({locations, arr[i].f+1});
    		}
    	}
    	else if(last){
    		int leftsize=size(0,idx-1);
    		if(leftsize==maxsize) eqmaxsize--;

    		if(leftsize+1>maxsize){
    			maxsize=leftsize+1;
    			eqmaxsize=1;
    		}
    		else if(leftsize+1==maxsize){
    			eqmaxsize+=1;
    		}

    		if(eqmaxsize==locations){
    			ans.pb({locations, arr[i].f+1});
    		}
    	}
    	else if(next){
    		int rightsize=size(1,idx+1);
    		if(rightsize==maxsize) eqmaxsize--;
    		if(rightsize+1>maxsize){
    			maxsize=rightsize+1;
    			eqmaxsize=1;
    		}
    		else if(rightsize+1==maxsize){
    			eqmaxsize+=1;
    		}
    		if(eqmaxsize==locations){
    			ans.pb({locations, arr[i].f+1});
    		}
    	}
    	else{
    		locations+=1;
    		if(1>maxsize){
    			maxsize=1;
    			eqmaxsize=1;
    		}
    		else if(1==maxsize){
    			eqmaxsize+=1;
    		}
    		if(eqmaxsize==locations){
    			ans.pb({locations, arr[i].f+1});
    		}
    	}
    	update(idx,1);
    }
    sort(ans.begin(), ans.end(),comp);
    // rep(i,0,ans.size())cout << ans[i].s <<" " << ans[i].f<< endl;
    cout << ans[0].s << endl;



}

int main(){
    fast_cin;
    int t=1; 
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}