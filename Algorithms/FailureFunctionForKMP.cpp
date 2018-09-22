#define ll long long
#define MAX 100000
ll failure[MAX];
//failure[i] will contain size of longest suffix which is also a prefix in string s[0...i]
void buildFailure(string s){
    failure[0]=0;
    int len=0;
    //current length of equal prefix 
    //which is also a suffix when we
    //have processed till start
    int start=1;
    while(start<n){
        if(s[start]==s[len]){
            failure[start]=len+1;
            len++;
            start++;
        }
        else if(len==0){
            failure[start]=0;
            start++;
        }
        else{
            len=failure[len-1];
        }
    }
}
