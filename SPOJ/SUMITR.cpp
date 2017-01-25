#include <bits/stdc++.h> 
#define s(n) scanf("%d",&n)
int a[102][102],F,i,j,n,t;main(){t;s(t);while(t--){n;s(n);F=0;for(i=1;i<=n;i++)for(j=1;j<=i;j++){s(a[i][j]);a[i][j]+=std::max(a[i-1][j],a[i-1][j-1]);F=std::max(F,a[i][j]);};printf("%d\n",F);};}
