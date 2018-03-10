#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897
#define ll long long
#define tr1(n) cout << n << endl
#define tr2(n1,n2) cout << n1 << " " << n2 << endl
#define mem(A,i) memset(A, i, sizeof(A))
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define repDown(i, start, end) for(ll i=start; i>=end; i--)
#define mod 1000000007
#define MAX (10+(1<<18))
#define s second
#define f first
#define pb push_back
#define fast_in std::ios::sync_with_stdio(false);
#define fast_cin fast_in; ios_base::sync_with_stdio(false); cin.tie(NULL);
ll SEG[4*MAX];
ll lazy[4*MAX];
ll arr[MAX];
ll k=0;
ll n,q;
 
void belazy(ll node, ll start, ll end){
    if(lazy[node]!=-1){
        SEG[node]=lazy[node];
        if(start!=end) lazy[2*node]=lazy[2*node+1]=lazy[node];
    }
    lazy[node]=-1;
}
 
void build(ll node, ll start, ll end){
    lazy[node]=-1;
    if(start==end){
        SEG[node]=arr[start];
    }
    else{
        ll mid=(start+end)>>1;
        build(node<<1, start, mid);
        build(1+(node<<1), mid+1, end);
        SEG[node]=max(SEG[node<<1],SEG[1+(node<<1)]);
    }
}
void update(ll node, ll start, ll end, ll l, ll r, ll val){
    belazy(node, start, end);
    ll mid=(start+end)>>1;
    //without these it will be wrong answer. see into swapped area for more details ;)
    if(start!=end){
            belazy(2*node, start, mid);
            belazy(2*node+1, mid+1, end);
    }
    if(start>end || l>end || r<start) return;
    ll elements=end-start+1;
    elements>>=1;
    if(k&elements){
        //swap hua hai ye level
        if(start>=l && end<=r){
            SEG[node]=val;
            if(start!=end) lazy[2*node]=lazy[2*node+1]=val;
            return;
        }
        if(l>mid){
            update(2*node, start, mid, l-(elements), r-elements, val);
        }
        else if(r<=mid){
            update(2*node+1, mid+1, end, l+(elements), r+elements, val);
        }
        else{
            update(2*node, start, mid, 0, r-elements, val);
            update(2*node+1, mid+1, end, l+(elements), end, val);
        }
        SEG[node]=max(SEG[2*node], SEG[2*node+1]);
        return;
    }
    else{
        if(start>=l && end<=r){
            SEG[node]=val;
            if(start!=end) lazy[2*node]=lazy[2*node+1]=val;
            return;
        }
        update(node<<1, start, mid, l, r, val);
        update(1+(node<<1), mid+1, end, l, r, val);
        SEG[node]=max(SEG[2*node], SEG[2*node+1]);
        return;
    }
}
ll query(ll node, ll start, ll end, ll l, ll r){
	belazy(node, start, end);
	ll mid=(start+end)>>1;
    if(start>end || l>end || r<start) return -1;
    
    ll elements=end-start+1;
    elements>>=1LL;
    if(k&elements){
        //swap hua hai ye level
        if(start>=l && end<=r){
            return SEG[node];
        }
        if(l>mid){
            return query(2*node, start, mid, l-(elements), r-elements);
        }
        else if(r<=mid){
            return query(2*node+1, mid+1, end, l+(elements), r+elements);
        }
        else{
            return max(query(2*node, start, mid, 0, r-elements)
            			,query(2*node+1, mid+1, end, l+(elements), end));
        }
    }
    else{
        if(start>=l && end<=r){
            return SEG[node];
        }
        return max(query(node<<1, start, mid, l, r),
        			query(1+(node<<1), mid+1, end, l, r));
    }
 
}
void solve(){
    //solve the problem. You can and you will :) give your best shot..
    cin>>n>>q;
    ll N=(1<<n)-1;
    rep(i,0,N+1) cin>>arr[i];
    build(1,0,N);
    while(q--){
    	ll type;
    	cin>>type;
    	if(type==1){
    		ll l,r;
    		cin>>l>>r;
    		cout << query(1,0,N, l, r) << endl;
    	}
    	else if(type==2){
    		ll l,r,v;
    		cin>>l>>r>>v;
    		update(1,0,N,l,r,v);
    	}
    	else{
    		ll p;cin>>p;
    		k=k^p;
    	}
    }    
}
 
int main(){
    // fast_cin;
    ll t=1; 
    while(t--){
        solve();
    }
    return 0;
}