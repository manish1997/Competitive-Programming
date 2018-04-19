#include <iostream>
#include <algorithm>
 
#include <cmath>
#include <stack>
using namespace std;
#define rep(i, start, end) for(int i=start; i<end; i++)
#define repDown(i, start, end) for(int i=start; i>=end; i--)
#define mod 1000000007
#define MAX 100002
#define s second
#define f first
#define pb push_back
 
int SEG[4*MAX];
int LOG[MAX];
 
int lazy[4*MAX];
int n;
int L[MAX],R[MAX],A[MAX];
 
pair<int,int> B[MAX];
 
void belazy(int node, int start, int end){
    if(lazy[node]){
        SEG[node]=lazy[node];
        if(start!=end){
            lazy[node<<1]=lazy[(node<<1)+1]=lazy[node];
        }
        lazy[node]=0;
    }
}
 
void update(int node, int start, int end, int l, int r, int val){
    belazy(node, start, end);
    if(start>end || l>end || r<start) return;
    if(start>=l && end<=r){
        SEG[node]=val;
        if(start!=end){
            lazy[node<<1]=lazy[1+(node<<1)]=val;
        }
        return;
    }
    int mid=(start+end)>>1;
    if(r<=mid) update(node<<1, start, mid, l, r, val);
    else if(l>mid) update(1+(node<<1), mid+1, end, l, r, val);
    else{
        update(node<<1, start, mid, l, r, val);
        update(1+(node<<1), mid+1, end, l, r, val);
    }
    SEG[node]=min(SEG[node<<1], SEG[1+(node<<1)]);
    return;
}
int query(int node, int start, int end, int l, int r){
    if(start>end || l>end || r<start) return 1+1e9;
    belazy(node, start, end);
    if(start>=l && end<=r){
        return SEG[node];
    }
    int mid=(start+end)>>1;
    return min(query(node<<1, start, mid, l, r),query(1+(node<<1), mid+1, end, l, r));
}
void build(int node, int start, int end){
    lazy[node]=0;
    if(start==end){
        SEG[node]=A[start];
    }
    else{
        int mid=(start+end)>>1;
        build(node<<1, start, mid);
        build(1+(node<<1), mid+1, end);
        SEG[node]=min(SEG[node<<1], SEG[1+(node<<1)]);
    }
}
int M[MAX][22];
void solve(){
 
    scanf("%d",&n);
    rep(i,0,n){
        scanf("%d",&A[i]);
    }
    rep(i,0,n) M[i][0]=i;
    for(int j=1; (1<<j)<=n; j++){
        for(int i=0; i+(1<<j)-1<n; i++){
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]]) M[i][j] = M[i][j - 1];
            else M[i][j] = M[i + (1 << (j - 1))][j - 1];
        }
    }
    rep(i,0,n){
        scanf("%d",&B[i].f);
        B[i].s=i;
    }
 
    build(1,0,n-1);
    rep(i,0,n){
        if(A[i]<B[i].f){
            printf("-1\n");
            return;
        }
    }
    stack<int> S;
    rep(i,0,n){
    while(!S.empty() && B[S.top()].f<=B[i].f){
        S.pop();
    }
    if(S.empty()) L[i]=-1;
    else L[i]=S.top();
    S.push(i);
    }
    while(!S.empty()) S.pop();
    repDown(i,n-1,0){
        while(!S.empty() && B[S.top()].f<=B[i].f){
        S.pop();
    }
    if(S.empty()) R[i]=n;
    else R[i]=S.top();
    S.push(i);
    }
    sort(B,B+n);
 
    int ans=0;
    repDown(i,n-1,0){
        int idx=B[i].s;
        int val=B[i].f;
 
        int curr=query(1,0,n-1, idx, idx);
        if(curr==val){
            continue;
        }
        //find position in right upto which you can decrease to height B[i].f
        int start=idx;
        int end=R[idx]-1;
 
        while(start<=end){
            int mid=(start+end)>>1;
            int tempval;
                int k=LOG[(mid-idx+1)];
                if(A[M[idx][k]]<=A[M[mid-(1<<k)+1][k]]) tempval=M[idx][k];
                else tempval=M[mid-(1<<k)+1][k];
            if(A[tempval]>=val) start=mid+1;
            else end=mid-1;
        }
        //find position in left upto which you can decrease to height B[i].f
        int tempend=start-1;
        start=L[idx]+1;
        end=idx;
        while(start<=end){
            int mid=(start+end)>>1;
            int tempval;
                int k=LOG[(idx-mid+1)];
                if(A[M[mid][k]]<=A[M[idx-(1<<k)+1][k]]) tempval=M[mid][k];
                else tempval=M[idx-(1<<k)+1][k];
            if(A[tempval]>=val) end=mid-1;
            else start=mid+1;
        }
        update(1,0,n-1, start, tempend, val);
        ans++;
    }
    printf("%d\n",ans);
}
 
int main(){
    int t=1; 
    scanf("%d",&t);
    rep(i,1,MAX) LOG[i]=log2(i);
    while(t--){
        solve();
    }
    return 0;
} 