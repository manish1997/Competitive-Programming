//  Credits is all of : https://cp-algorithms.com/string/manacher.html . Awesome editorial.
class manacher{
	public:
	// Vector where d1[i] = (number of palindrome with odd length (centre is i)).
	vector<int> d1;
	// Vector where d2[i] = (number of palindrome with even length (centre is (i-1,i))).
	vector<int> d2;
	// Size of string.
	int n;
	void init(string s){
		d1.resize(s.length());
		d2.resize(s.length());
		n = s.length();
		// calculate d1.
		// l and r is palindrome found with  maximum r till now.
		for(int i=0, l=0, r=-1; i<s.length(); i++){
			d1[i]= i > r ? 1 : min(d1[l+r-i],r-i+1);
			while(i-d1[i]>=0 && i+d1[i]<n  &&  s[i-d1[i]]==s[i+d1[i]]){
				d1[i]++;
			}
			if(i+d1[i]-1>r){
				r=i+d1[i]-1;
				l=i-d1[i]+1;
			}
		}
		// calculate d2.
		for(int i=0, l=0, r=-1; i<s.length(); i++){
			d2[i] =  (i>r) ? 0 : min(d2[l+r-i+1], r-i+1);
			while(i-d2[i]-1>=0 && i+d2[i]<n && s[i-d2[i]-1]==s[i+d2[i]]){
				d2[i]++;
			}
			if(i+d2[i]-1>r){
				r=i+d2[i]-1;
				l=i-d2[i];
			}
		}
	}
};
