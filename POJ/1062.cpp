/****************
*PID:poj1062
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100+10;
const LL INF=1000000000;
int dis[maxn][maxn],p[maxn],l[maxn],x[maxn],P[maxn][maxn],L[maxn][maxn];

int main()
{
    int i,j,n,m;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++){
        scanf("%d%d%d",&p[i],&l[i],&x[i]);
        for(j=1;j<=x[i];j++)
            scanf("%d%d",&L[i][j],&P[i][j]);
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++) dis[i][j]=INF;
    for(i=1;i<=n;i++){
        if(abs(l[i]-l[1])>m) continue;
        for(j=1;j<=x[i];j++){
            if(abs(l[L[i][j]]-l[1])>m) continue;
            dis[i][L[i][j]]=P[i][j];
        }
    }
    for(i=1;i<=n;i++) dis[i][i]=0;
    for(int k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }
    int res=1000000000;
    for(i=1;i<=n;i++)
        res=min(res,dis[1][i]+p[i]);
    printf("%d\n",res);
    return 0;
}

