#include <bits/stdc++.h>
using namespace std;
char chessboard[8][8];
pair<int,int> blackking;

pair<int,int> whiteking;
bool valid(int i, int j){
    return (i>=0 && j>=0 && i<8 && j<8);
}
bool check(){
    //check is black king is in attacked position
    int x=blackking.first;
    int y=blackking.second;
    //K,Q,N,B,R,P
    //hit by a King
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0 && j==0) continue;
            if(valid(x+i, y+j) && chessboard[x+i][y+j]=='K') return true;
        }
    }
    //hit by a Queen
    //horizontal
    for(int j=y-1; j>=0; j--) if(chessboard[x][j]=='Q') return true; else if(chessboard[x][j]!='#') break;
    for(int j=y+1; j<8; j++) if(chessboard[x][j]=='Q') return true; else if(chessboard[x][j]!='#') break;
    
    //vertical
    for(int i=x+1; i<8; i++) if(chessboard[i][y]=='Q') return true; else if(chessboard[i][y]!='#') break;
    for(int i=x-1; i>=0; i--) if(chessboard[i][y]=='Q') return true; else if(chessboard[i][y]!='#') break;
    
    //diagonal
    for(int i=x+1, j=y-1; i<8 && j>=0; i++, j--) if(chessboard[i][j]=='Q') return true; else if(chessboard[i][j]!='#') break;
    for(int i=x+1, j=y+1; i<8 && j<8; i++, j++) if(chessboard[i][j]=='Q') return true; else if(chessboard[i][j]!='#') break;
    
    for(int i=x-1, j=y+1; i>=0 && j<8; i--, j++) if(chessboard[i][j]=='Q') return true; else if(chessboard[i][j]!='#') break;
    for(int i=x-1, j=y-1; i>=0 && j>=0; i--, j--) if(chessboard[i][j]=='Q') return true; else if(chessboard[i][j]!='#') break;

    

    //hit by Bishop
    for(int i=x+1, j=y-1; i<8 && j>=0; i++, j--) if(chessboard[i][j]=='B') return true; else if(chessboard[i][j]!='#') break;
    for(int i=x+1, j=y+1; i<8 && j<8; i++, j++) if(chessboard[i][j]=='B') return true; else if(chessboard[i][j]!='#') break;
    
    for(int i=x-1, j=y+1; i>=0 && j<8; i--, j++) if(chessboard[i][j]=='B') return true; else if(chessboard[i][j]!='#') break;
    for(int i=x-1, j=y-1; i>=0 && j>=0; i--, j--) if(chessboard[i][j]=='B') return true; else if(chessboard[i][j]!='#') break;

    //hit by Rook
    for(int i=x+1; i<8; i++) if(chessboard[i][y]=='R') return true; else if(chessboard[i][y]!='#') break;
    for(int i=x-1; i>=0; i--) if(chessboard[i][y]=='R') return true; else if(chessboard[i][y]!='#') break;
    for(int j=y-1; j>=0; j--) if(chessboard[x][j]=='R') return true; else if(chessboard[x][j]!='#') break;
    for(int j=y+1; j<8; j++) if(chessboard[x][j]=='R') return true; else if(chessboard[x][j]!='#') break;
    
    //hit by Pawn
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0 && j==0) continue;
            if(abs(i)!=abs(j)) continue;
            if(valid(x+i, y+j) && chessboard[x+i][y+j]=='P') return true;
        }
    }

    //hit by Knight
    //Knight
    int i=x+1;
    int j=y-2;
    if(valid(i,j) && chessboard[i][j]=='N') return true;
    j=y+2;
    if(valid(i,j) && chessboard[i][j]=='N') return true;
    i=x+2;
    j=y-1;
    if(valid(i,j) && chessboard[i][j]=='N') return true;
    j=y+1;
    if(valid(i,j) && chessboard[i][j]=='N') return true;
    i=x-1;
    j=y-2;
    if(valid(i,j) && chessboard[i][j]=='N') return true;
    j=y+2;
    if(valid(i,j) && chessboard[i][j]=='N') return true;
    i=x-2;
    j=y-1;
    if(valid(i,j) && chessboard[i][j]=='N') return true;
    j=y+1;
    if(valid(i,j) && chessboard[i][j]=='N') return true;
    return false;
}
bool whiteattack(){
    //check is black king is in attacked position
    int x=whiteking.first;
    int y=whiteking.second;
    //K,Q,N,B,R,P
    //hit by a King
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0 && j==0) continue;
            if(valid(x+i, y+j) && chessboard[x+i][y+j]=='k') return true;
        }
    }
    //hit by a Queen
    //horizontal
    for(int j=y-1; j>=0; j--) if(chessboard[x][j]=='q') return true; else if(chessboard[x][j]!='#') break;
    for(int j=y+1; j<8; j++) if(chessboard[x][j]=='q') return true; else if(chessboard[x][j]!='#') break;
    
    //vertical
    for(int i=x+1; i<8; i++) if(chessboard[i][y]=='q') return true; else if(chessboard[i][y]!='#') break;
    for(int i=x-1; i>=0; i--) if(chessboard[i][y]=='q') return true; else if(chessboard[i][y]!='#') break;
    
    //diagonal
    for(int i=x+1, j=y-1; i<8 && j>=0; i++, j--) if(chessboard[i][j]=='q') return true; else if(chessboard[i][j]!='#') break;
    for(int i=x+1, j=y+1; i<8 && j<8; i++, j++) if(chessboard[i][j]=='q') return true; else if(chessboard[i][j]!='#') break;
    
    for(int i=x-1, j=y+1; i>=0 && j<8; i--, j++) if(chessboard[i][j]=='q') return true; else if(chessboard[i][j]!='#') break;
    for(int i=x-1, j=y-1; i>=0 && j>=0; i--, j--) if(chessboard[i][j]=='q') return true; else if(chessboard[i][j]!='#') break;

    

    //hit by Bishop
    for(int i=x+1, j=y-1; i<8 && j>=0; i++, j--) if(chessboard[i][j]=='b') return true; else if(chessboard[i][j]!='#') break;
    for(int i=x+1, j=y+1; i<8 && j<8; i++, j++) if(chessboard[i][j]=='b') return true; else if(chessboard[i][j]!='#') break;
    
    for(int i=x-1, j=y+1; i>=0 && j<8; i--, j++) if(chessboard[i][j]=='b') return true; else if(chessboard[i][j]!='#') break;
    for(int i=x-1, j=y-1; i>=0 && j>=0; i--, j--) if(chessboard[i][j]=='b') return true; else if(chessboard[i][j]!='#') break;

    //hit by Rook
    for(int i=x+1; i<8; i++) if(chessboard[i][y]=='r') return true; else if(chessboard[i][y]!='#') break;
    for(int i=x-1; i>=0; i--) if(chessboard[i][y]=='r') return true; else if(chessboard[i][y]!='#') break;
    for(int j=y-1; j>=0; j--) if(chessboard[x][j]=='r') return true; else if(chessboard[x][j]!='#') break;
    for(int j=y+1; j<8; j++) if(chessboard[x][j]=='r') return true; else if(chessboard[x][j]!='#') break;
    
    //hit by Pawn
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0 && j==0) continue;
            if(abs(i)!=abs(j)) continue;
            if(valid(x+i, y+j) && chessboard[x+i][y+j]=='p') return true;
        }
    }

    //hit by Knight
    //Knight
    int i=x+1;
    int j=y-2;
    if(valid(i,j) && chessboard[i][j]=='n') return true;
    j=y+2;
    if(valid(i,j) && chessboard[i][j]=='n') return true;
    i=x+2;
    j=y-1;
    if(valid(i,j) && chessboard[i][j]=='n') return true;
    j=y+1;
    if(valid(i,j) && chessboard[i][j]=='n') return true;
    i=x-1;
    j=y-2;
    if(valid(i,j) && chessboard[i][j]=='n') return true;
    j=y+2;
    if(valid(i,j) && chessboard[i][j]=='n') return true;
    i=x-2;
    j=y-1;
    if(valid(i,j) && chessboard[i][j]=='n') return true;
    j=y+1;
    if(valid(i,j) && chessboard[i][j]=='n') return true;
    return false;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t; 
    cin>>t;
    while(t--){
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++) {
                cin>>chessboard[i][j];
                if(chessboard[i][j]=='k'){
                    blackking={i,j};
                }
                if(chessboard[i][j]=='K'){
                    whiteking={i,j};
                }
                
            }
        }
        if(whiteattack()){
            cout << 0 << endl;
            continue;
        }
        int i=1;
        int ans=0;
        for(int j=0; j<8; j++){
            if(chessboard[i][j]=='P' && chessboard[i-1][j]=='#'){
                chessboard[i][j]='#';
                for(int k=0; k<4; k++) {
                    if(k==0){
                        chessboard[i-1][j]='Q';
                    }
                    else if(k==1){
                        chessboard[i-1][j]='R';
                    }
                    else if(k==2){
                        chessboard[i-1][j]='B';
                    }
                    else{
                        chessboard[i-1][j]='N';
                    }
                    if(check()) ans++;
                }
                break;
            }
        }
        cout << ans << endl;
       
    }
    return 0;
}
