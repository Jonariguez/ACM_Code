/****************
*PID:poj2253
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define eps 1e-8
const int maxn=200+10;
const double INF=1000000000;

double mp[maxn][maxn],d[maxn],dis[maxn][maxn];
int x[maxn],y[maxn],vis[maxn],par[maxn];

int main()
{
    int i,j,n,kcase=1;
    while(scanf("%d",&n),n){
        for(i=1;i<=n;i++){
            scanf("%d%d",&x[i],&y[i]);
        }
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++) dis[i][j]=INF;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
               // dis[i][j]=INF;
            }
        }
      //  for(i=1;i<=n;i++) dis[i][i]=0;
        memset(vis,0,sizeof(vis));
      //  memset(dis,0,sizeof(dis));
        for(int k=1;k<=n;k++){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    if(dis[i][k] && dis[k][i])
                    dis[i][j]=min(dis[i][j],max(dis[i][k],dis[k][j]));
                }
            }
        }
        /*
        while(1){
            int v=-1;
            for(i=1;i<=n;i++)
                if(vis[i]==0 && (v==-1 || d[v]>d[i])) v=i;
            if(v==-1) break;
            printf("%.3f\n",dis[2]);
            printf("v=%d\n",v);
            vis[v]=1;
            for(i=1;i<=n;i++){
                if(i!=v){
                    d[i]=min(d[i],max(d[v],mp[v][i]));//dis[i]=max(dis[v],mp[v][i]);par[i]=v;puts("??");
                }
            }
        }
        double res=0;int x=2;
        while(x!=1){
            res=max(res,mp[x][par[x]]);
            x=par[x];
        }*/
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",kcase++,dis[1][2]);

    }
    return 0;
}
