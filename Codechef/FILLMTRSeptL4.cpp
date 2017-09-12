#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%lld\n",n)
#define pis(n) printf("%d ",n)
#define plls(n) printf("%lld ",n)
#define rep(i, start, end) for(ll i=start; i<end; i++)
#define S second
#define F first
#define P pair<int,int>
#define PP pair<P,ll>
#define mod 1000000007
#define MAX 500005
#define s second
#define f first
#define newLine printf("\n")
int n,q;
// int visited[100005];
// int value[100005];
int main(){
    int t; si(t);
    while(t--){
        si(n); si(q);
        map<pair<int,int>, int> MM;
        bool ans=true;
        rep(i,0,q){
            int a,b,c;
            si(a); si(b); si(c);
            if(a==b && c!=0) ans=false;
            if(a==b) continue;
            auto it=MM.find({b,a});
            if(it!=MM.end()){
                if(it->second!=c){
                    ans=false;
                }
            }
            it=MM.find({a,b});
            if(it!=MM.end()){
                if(it->second!=c){
                    ans=false;
                }
            }
            if(a>b) swap(a,b);
            MM[{a,b}]=c;
        }
        if(!ans){
            printf("no\n");
            continue;
        }
        map<int, vector<pair<int,int> > > mapp;
        for(auto it=MM.begin(); it!=MM.end(); it++){
            mapp[it->f.f].push_back({it->f.s, it->s});
            mapp[it->f.s].push_back({it->f.f, it->s});
        }





        unordered_map<int,bool> one;
        unordered_map<int,bool> zero;
        unordered_map<int,bool> visited;
        for(auto it2=mapp.begin(); ans && it2!=mapp.end(); it2++){
            int curr=it2->f;
            //if visited continue
            if(visited.find(curr)!=visited.end()) continue;
            visited[curr]=true;
            //end if visited

            //node to visit
            
            queue<int> Q;
            Q.push(curr);

            while(ans && !Q.empty()){
                int node=Q.front();
                Q.pop();
                auto it=mapp.find(node);
                vector<pair<int,int> > current=it->second;
                int grp=zero.find(node)!=zero.end()?0:(one.find(node)!=one.end()?1:-1);

                //start for inner
                for(int i=0; ans && i<current.size(); i++){
                    //pair<int,int> p=it->first;
                    int secondValue=current[i].f;
                    int val=current[i].s;
                    int sec=zero.find(secondValue)!=zero.end()?0:(one.find(secondValue)!=one.end()?1:-1);
                    if(grp==-1 && sec==-1){
                        zero[node]=true;
                        if(val==1) one[secondValue]=true;
                        else zero[secondValue]=true;
                    }
                    else if(grp!=-1 && sec==-1){
                        if(val==1) {int temp=(grp+1)%2; if(temp) one[secondValue]=true; else zero[secondValue]=true;}
                        else {if(grp) one[secondValue]=true; else zero[secondValue]=true;};
                    }
                    else if(grp==-1 && sec!=-1){
                        if(val==1) { int temp=(sec+1)%2; if(temp) one[node]=true; else zero[node]=true;}
                        else {if(sec) one[node]=true; else zero[node]=true; }
                    }
                    else{
                        if(val){
                            if(sec==grp) ans=false;
                        }
                        else{
                            if(sec!=grp) ans=false;
                        }
                    }
                    if(visited.find(secondValue)==visited.end()){
                       // cout << node << " " << secondValue << endl;
                        Q.push(secondValue);
                        //cout << secondValue << endl;
                        visited[secondValue]=true;
                    }
                }
                //end of inner for loop

            }
            //end of while loop


        }
        // rep(i,1,n+1){
        //     cout << i << " " << ((one.find(i)!=one.end())?1:0) << endl;
        // }
        
        if(ans)printf("yes\n");
        else printf("no\n");
 
 
    }
    return 0;
} 
