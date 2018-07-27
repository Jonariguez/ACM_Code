/****************
*PID:cdvs1160
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
int a[maxn][maxn];

int main()
{
    int i,j,sum,tot,n,x,y;
    scanf("%d",&n);
    x=n;y=n+1;
    tot=n*n;
    while(tot){
        while(y-1>=1 && a[x][y-1]==0) a[x][--y]=tot--;
        while(x-1>=1 && a[x-1][y]==0) a[--x][y]=tot--;
        while(y+1<=n && a[x][y+1]==0) a[x][++y]=tot--;
        while(x+1<=n && a[x+1][y]==0) a[++x][y]=tot--;
    }
    sum=0;
    for(i=1;i<=n;i++){
        sum+=a[i][i];
        sum+=a[i][n-i+1];
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("%d\n",sum-1);
    return 0;
}
