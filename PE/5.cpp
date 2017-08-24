#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
int arr[10000001];

int main(){
	int ans=1;
	//Can be improved by calculating prime early
	for(int i=1; i<=100000; i++){
		int temp=i;
		for(int j=2; j<=sqrt(i); j++){
			int cnt=0;
			while((temp%j)==0) {
				cnt++;
				temp/=j;
			}
			//cout << i << " " << j << " " << arr[j] << " " << ans<< endl;
			if(arr[j]>=cnt) continue;
			ans*=(pow(j,cnt-arr[j]));
			arr[j]=cnt;
		}
		if(temp>1){
			if(arr[temp]>=1) continue;
			ans*=(pow(temp,1));
			arr[temp]=1;
		}
	}
	cout << ans;
	return 0;
}