
class segment_tree{
	public:
	int n;
	vector<ll> seg;
	vector<ll> lazy;
	vector<ll> arr;
	
	void init(vector<int>& temp){
		n=temp.size();
		seg.resize(4*n+4);
		lazy.resize(4*n+4);
		arr=temp;
	}
	
	// depending on need of max/min/sum. Update this function.
	void merge(int node){
		seg[node]=max(seg[2*node], seg[2*node+1]);
	}
	
	// Please add only the values which needs to be added in seg node.
	// Currently works with min/max/sum.
	void be_lazy(int node, int start, int end){
		if(lazy[node]!=0){
			seg[node]+=lazy[node];
			if(start!=end){
				lazy[node*2]+=lazy[node];
				lazy[node*2+1]+=lazy[node];
			}
			lazy[node]=0;
		}
	}
	
	void build(int node, int start,  int end){
		if(start==end){
			seg[node]=arr[start];
			return;
		}
		int mid = (start+end)>>1;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		merge(node);
	}
	
	void update(int node, int start, int end, int l, int r, int val){
		be_lazy(node, start, end);
		if(start>end || l>end || r<start || l>r) return;
		if(start>=l && end<=r){
			// for max and min as changing value on range will change across all
			// values and min max would change by  same. Use (end-start+1) if
			// storing sum of range.
			seg[node]+=val;
			if(start!=end){
				lazy[2*node]+=val;
				lazy[2*node+1]+=val;
			}
			return;
		}
		int mid=(start+end)>>1;
		update(node*2, start,  mid, l, r, val);
		update(node*2+1,  mid+1, end, l, r, val);
		merge(node);
	}
	
	long long query(int node, int start, int end, int l, int r){
		be_lazy(node, start, end);
		if(start>end || l>r || l>end || r<start){
			// Change according to expectation. Need max elements so using
			// minimum possible value  here.
			return -1e18;
		}
		if(start>=l && end<=r){
			return seg[node];
		}
		int mid =  (start+end)>>1;
		long long left_query = query(node*2, start,  mid, l, r);
		long long right_query =  query(node*2+1, mid+1, end, l, r);
		// Change as per expectation here. Need max hence  returning max of both
		// children heres.
		return max(left_query, right_query);
	}
};
