// Not a refined version.
// Just call rolling_has_object.init(string) function to set hash prefix and suffix array.
// Call hash_l_to_r to get hash of (l----r) string.
// Call hash_r_to_l to get hash of reverse(l-----r) string.
class rolling_hash {
	private:
		ll base=29;
		ll mod=1000000007;
		ll max_size=1000005;
		string s;
		vector<ll> prefix,suffix,power;
	public:
		void init(string temp){
			s=temp;
			// reset all the values.
			prefix.resize(max_size);
			suffix.resize(max_size);
			power.resize(max_size);
			
			// find  power array for base. we need it later to get range hashes.
			power[0]=1;
			for(int i=1; i<max_size; i++) power[i]=(base*power[i-1])%mod;
			// find prefix array of hashes.
			for(int i=0; i<s.length(); i++){
				prefix[i]=s[i]-'a'+1;
				if(i!=0){
					prefix[i]+=(prefix[i-1]*base);
					prefix[i]%=mod;
				}
			}
			// find suffix array of hashes.
			for(int i=s.length()-1; i>=0; i--){
				suffix[i]=s[i]-'a'+1;
				if(i!=s.length()-1){
					suffix[i]+=(suffix[i+1]*base);
					suffix[i]%=mod;
				}
			}
		}
		
		
		ll hash_l_to_r(int left, int right){
			// ideally these values should not be passed. Return mod+1 in this case
			// and consider it as invalid.
			if(right>=s.length() || left<0 || left>right) return mod+1;
			return ((prefix[right]-(((left>=1?prefix[left-1]:0)*power[right-left+1])%mod)+mod)%mod);
		}
		
		ll hash_r_to_l(int left, int right){
			// ideally these values should not be passed. Return mod+1 in this case
			// and consider it as invalid.
			if(right>=s.length() || left<0 || left>right) return mod+1;
			return (suffix[left]-(((right+1==s.length()?0:suffix[right+1])*power[right+1-left])%mod)+mod)%mod;
		}
};
