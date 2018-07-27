/****************
*PID:poj1797
*Auth:Jonariguez
*****************
Dij求路径最大值的最小值。
dis表示map
d表示从起点到目前点的的路径中的最大值
只需要更新求出d数组即可。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
const int INF=1000000000;
int dis[maxn][maxn],d[maxn],vis[maxn];

int main()
{
    int i,j,n,m,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++) dis[i][j]=0;
      //  for(i=1;i<=n;i++) dis[i][i]=0;
        for(i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            dis[a][b]=dis[b][a]=c;
        }
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
            d[i]=dis[1][i];
        d[1]=0;vis[1]=1;
        while(1){
            int v=-1;
            for(i=1;i<=n;i++)
                if(vis[i]==0 && (v==-1 || d[v]<d[i])) v=i;  //选择起点时还是以d为依据
            if(v==-1) break;
            vis[v]=1;
            for(i=1;i<=n;i++){
                if(vis[i]==0){
                    d[i]=max(d[i],min(d[v],dis[v][i]));//dis[i]=max(dis[v],mp[v][i]);par[i]=v;puts("??");
                }
            }
        }
        printf("Scenario #%d:\n%d\n\n",kcase++,d[n]);
    }
    return 0;
}
