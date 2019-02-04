#include <bits/stdc++.h>
using namespace std;

vector<int> slidingMaximum(const vector<int> &A, int B) {
    if(B>=A.size()){
        return {*max_element(A.begin(),A.end())};
    }
    deque<int> Q;
    
    vector<int> ans;
    
    for(int i=0; i<A.size(); i++){
        
        //insert element to deque, remove all smaller element than current
        //element as they can't be answer for any window coming forward
        while(!Q.empty() && Q.back()<A[i]){
            Q.pop_back();
        }
        Q.push_back(A[i]);
        
        //if we don't have a window yet, continue inserting
        if(i<B-1) continue;
        
        //answer will be front of queue as this will be highest element in window
        ans.push_back(Q.front());
        
        //if highest was the first element of this window delete it from front        
        if(A[i-B+1]==Q.front()){
            Q.pop_front();
        }
    }
    return ans;
}


int main(){
    int windowSize = 2;
    vector<int> A = {1,2,3,4,5};
    vector<int> slidingWindow = slidingMaximum(A,windowSize);
    for(auto it: slidingWindow){
        cout << it << " ";
    }
    return 0;
}