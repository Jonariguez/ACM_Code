/****************
*PID:uva10048
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
const int INF=1e9;

int a[maxn][maxn],res[maxn][maxn];
int n,m,q;

void floyd(){
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][k] && a[k][j])
                a[i][j]=min(a[i][j],max(a[i][k],a[k][j]));
}

int main()
{
    int i,j,kcase=0;
    while(scanf("%d%d%d",&n,&m,&q)){
        if(n==0 && m==0 && q==0) break;
        if(kcase++)
            printf("\n");
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
            a[i][j]=INF;
        int x,y,d;
        for(i=0;i<m;i++){
            scanf("%d%d%d",&x,&y,&d);
            a[x][y]=a[y][x]=d;
        }
        floyd();
        printf("Case #%d\n",kcase);
        while(q--){
            scanf("%d%d",&x,&y);
            if(a[x][y]<INF)
                printf("%d\n",a[x][y]);
            else
                printf("no path\n");
        }
    }
    return 0;
}
