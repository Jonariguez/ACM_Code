/****************
*PID:610c div2
*Auth:Jonariguez
*****************
左上，右上，左下一样，右下取反
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int vis[600][600];

void solve(int n,int x,int y,int v){
    if(n==1){
        vis[x][y]=v;
        return ;
    }
    solve(n/2,x,y,v);
    solve(n/2,x,y+n/2,v);
    solve(n/2,x+n/2,y,v);
    solve(n/2,x+n/2,y+n/2,-v);
}

int main()
{
    int i,j,n,k;
    scanf("%d",&k);
    n=(1<<k);
    solve(n,0,0,1);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            if(vis[i][j]==1)
                printf("+");
            else printf("*");
        printf("\n");
    }
    return 0;
}
