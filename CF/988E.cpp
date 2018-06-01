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
#define MAX 200005
#define INF 1+1e18
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
ll arr[MAX];
map<ll,bool> M;
string str;
ll cnt[10];
ll n;
bool did=false;
ll pos(int chk, char temp){
	// cout<<temp<<endl;
	rep(i,0,str.length()){
		if(str[i]==temp) chk--;
		if((i==str.length()-1)&& str[i-1]=='0') return 10000;
		if(chk==0) return i;
	}
}
ll helper(ll curr){
	if(curr==0){
		if(cnt[0]<2) return 1000;
		return (pos(2,'0')-1+pos(1,'0'));
	}
	// cout << curr << endl;
	int di1=curr%10;
	int di2=(curr/10);
	if(cnt[di2]==0 || cnt[di1]==0) return 1000;
	// cout << curr << endl;
	if(str[0]==(di1+'0') && str[1]==di2+'0') return 0;
	if(str[1]==di1+'0' && str[0]=='0'+di2) return 1;

	if(str[0]==di1+'0'){
		if(did){
			if(pos(1,'0'+di2));
		}
		return pos(1,'0'+di2)-1;
	}
	if(str[0]=='0'+di2) return pos(1,di1+'0');
	if(str[1]=='0'+di2){
		return (pos(1,di1+'0')+1);
	}
	if(str[1]=='0'+di1){
		return (pos(1,'0'+di2));
	}
	if(pos(1,'0'+di1)<pos(1,'0'+di2)){
		return pos(1,di1+'0')+pos(1,'0'+di2)-1;
	}
	return pos(1,di1+'0')+pos(1,'0'+di2);
}

void solve(){
    //solve the problem. You can and you will :) give your best shot..
	cin>>n;
	ll temp=n;
	if(n==0){
		cout<<0<<endl;
		return;
	}
	mem(cnt,0);
	str="";
	while(temp){
		cnt[(temp%10LL)]++;
		str.pb('0'+(temp%10LL));
		temp/=10LL;
	}
	if((cnt[0]>=2 || (cnt[2]&&cnt[5])||(cnt[0]&&cnt[5]) || (cnt[7]&&cnt[5]))==false){
		cout<<-1<<endl;
		return;
	}
	ll ans=5000;
	for(ll i=0; i<100; i+=25){
		string hel=str;
		ll currans=0,j;
		char fi='0'+(i%10);
		char se='0'+((i/10)%10);
		// cout<<'e';
		if(cnt[fi-'0']==0 || cnt[se-'0']==0) continue;
		if(i==0 && cnt[0]<2) continue;
		// cout<<'e';
		for(j=0; j<str.length(); j++){
			// cout<<hel[j]<<endl;
			if(hel[j]==fi){
				break;
			}
		}
		// cout<<hel<<endl;
		for(j; j>=1; j--){
			// cout<<j<<" " << hel << endl;
			swap(hel[j-1],hel[j]);
			currans++;
		}
		// cout<<hel<<endl;
		if(hel[hel.length()-1]=='0'){
			for(j=hel.length()-1; j>=0; j--)if(hel[j]!='0')break;
			if(hel[j]!='0')
			for(j;j<hel.length()-1;j++){
				swap(hel[j], hel[j+1]);
				currans++;
			}
		}
		for(j=1; j<str.length(); j++){
			if(hel[j]==se){
				break;
			}
		}

		for(j; j>=2; j--){
			swap(hel[j-1],hel[j]);
			currans++;
		}
		if(hel[hel.length()-1]=='0'){
			for(j=hel.length()-1; j>=2; j--)if(hel[j]!='0')break;
			if(hel[j]!='0')
			for(j;j<hel.length()-1;j++){
				swap(hel[j], hel[j+1]);
				currans++;
			}
		}
		// cout<<i << endl;
		// cout<<hel<<endl;
		if(hel[0]==fi && hel[1]==se && hel[hel.length()-1]!='0'){
			ans=min(ans, currans);
		}
	}
	cout<<ans<<endl;


}

int main(){
    fast_cin;
    int t=1; 
    // cin >> t;
    // rep(i,0,100)cout<< rand()%100000000000000000+10000000000 <<endl;

    while(t--){
        solve();
    }
    return 0;
}