#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;
#define ll long long
#define si(n) cin >> n
#define sll(n) cin >> n
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%i64d\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(int i=start; i<end; i++)
#define S second
#define F first
#define P pair<int,int>
#define PP pair<P,int>
#define mod 1000000007
#define MAX 100005
#define newLine printf("\n")



int n,m;
string s;
struct  segmentTree
{
	int SEG[4*MAX];
	int Lazy[4*MAX];
	void build(int node, int start, int end, int ch){
		Lazy[node]=-1;
		if(start>end) return;
		if(start==end){
			SEG[node]=((s[start]-'a')==ch)?1:0;
			return;
		}
		int mid=(start+end)>>1;
		build(2*node, start, mid, ch);
		build(2*node+1, mid+1, end, ch);
		SEG[node]=SEG[2*node]+SEG[2*node+1];
		return;
	}
	int query(int node, int start, int end, int l, int r, int ch){
		if(start>end || l>end || r<start) return 0;
		if(Lazy[node]!=-1){
			if(start!=end){
				int mid=(start+end)>>1;
				SEG[2*node]=(mid-start+1)*Lazy[node];
				SEG[2*node+1]=(end-mid)*Lazy[node];
				Lazy[2*node]=Lazy[node];
				Lazy[2*node+1]=Lazy[node];
			}
			Lazy[node]=-1;
		}
		if(l<=start && r>=end){
			return SEG[node];
		}
		int mid=(start+end)>>1;
		int left=query(2*node, start, mid, l, r, ch);
		int right=query(2*node+1, mid+1, end, l, r, ch);
		return (left+right);
	}
	void update(int node, int start, int end, int l, int r, int ch, int val){
		if(Lazy[node]!=-1){
			if(start!=end){
				int mid=(start+end)>>1;
				SEG[2*node]=(mid-start+1)*Lazy[node];
				SEG[2*node+1]=(end-mid)*Lazy[node];
				Lazy[2*node]=Lazy[node];
				Lazy[2*node+1]=Lazy[node];
			}
			Lazy[node]=-1;
		}
		if(start>end || l>end || r<start) return;
		if(l<=start && r>=end){
			SEG[node]=(end-start+1)*val;
			Lazy[node]=val;
			return;
		}
		int mid=(start+end)>>1;
		update(2*node, start, mid, l, r, ch, val);
		update(2*node+1, mid+1, end, l, r, ch, val);
		SEG[node]=SEG[2*node]+SEG[2*node+1];
		return;
	}
	
}seg[26];

int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	si(n);
	si(m);
	cin >> s;
	rep(i,0,26) seg[i].build(1,0,n-1,i);

	rep(qqq,0,m){
		int l,r;
		sll(l); sll(r);
		l--;r--;
		int odd=0;
		int temp[26];
		for(int i=0; i<26; i++){
			temp[i]=seg[i].query(1,0,n-1,l,r,i);
			if(temp[i]&1) odd++;
		}
		if((l-r+1)%2==0){
			if(odd==0){
				rep(i,0,26)	seg[i].update(1,0,n-1,l,r,i,0);
				int curr=0;
				while(curr<26){
					int len=temp[curr]/2;
					len--;
					if(len>=0) seg[curr].update(1,0,n-1,l,l+len,curr,1);
					if(len>=0) seg[curr].update(1,0,n-1,r-len,r,curr,1);
					curr++;
					l=l+len+1;
					r=r-len-1;
				}
			}
		}
		else{
			if(odd==1){
				rep(i,0,26)	seg[i].update(1,0,n-1,l,r,i,0);
				int curr=0;
				while(curr<26){
					int len=temp[curr];
					if(len==0 && ++curr) continue;
					if(len%2!=0){
						odd=curr;
						len--;
					}
					len/=2;
					len--;
					if(len>=0) seg[curr].update(1,0,n-1,l,l+len,curr,1);
					if(len>=0) seg[curr].update(1,0,n-1,r-len,r,curr,1);
					curr++;
					l=l+len+1;
					r=r-len-1;
				}
				seg[odd].update(1,0,n-1,l,r,odd,1);
			}
		}
	}
	
	rep(j,0,n) rep(i,0,26) if(seg[i].query(1,0,n-1,j,j,i)) {
		s[j]=i+'a';
		break;
	}
	
	cout << s;
	//cout << 26*log2(1e5)*(1e5) << endl;
	return 0;
}