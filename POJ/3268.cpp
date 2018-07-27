/****************
*PID:poj3268
*Auth:Jonariguez
*****************
首先求x到其他点的最短距离，跑Dij
然后将所有的边方向，再跑Dij就是每个点到x的最短路
两个d数组对应的点的和的最大值就是答案。
mp[0]是原图，mp[1]是方向边
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
const int INF=1e9;
int mp[2][maxn][maxn],d[2][maxn],vis[maxn],n,m,x;

void Dij(int t){
    memset(vis,0,sizeof(vis));
    d[t][x]=0;
    int i;
    for(i=1;i<=n;i++)
        d[t][i]=mp[t][x][i];
    vis[x]=1;
    while(1){
        int v=-1;
        for(i=1;i<=n;i++){
            if(vis[i]==0 && (v==-1 || d[t][v]>d[t][i]))
                v=i;
        }
        if(v==-1) break;
        vis[v]=1;
        for(i=1;i<=n;i++){
            if(mp[t][v][i]<INF && d[t][i]>d[t][v]+mp[t][v][i])
                d[t][i]=d[t][v]+mp[t][v][i];
        }
    }
}


int main()
{
    int i,j;
    scanf("%d%d%d",&n,&m,&x);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            mp[0][i][j]=mp[1][i][j]=INF;
        }
        d[0][i]=d[1][i]=INF;
    }
    for(i=1;i<=n;i++) mp[0][i][i]=mp[1][i][i]=0;    //一定要有这个初始化，不然WA
    for(i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        mp[0][a][b]=c;mp[1][b][a]=c;
    }
    Dij(0);
    Dij(1);
    int res=0;
    for(i=1;i<=n;i++)
        res=max(res,d[0][i]+d[1][i]);
    printf("%d\n",res);
    return 0;
}
