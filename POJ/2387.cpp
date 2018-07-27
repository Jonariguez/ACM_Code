/*
Dijkstra模板题
*/
#include <stdio.h>
#include <string.h>

const int maxn=1000+10;
const int INF=1000000000;    //一开始INF太小了，所以一直WA
int map[maxn][maxn],vis[maxn],dis[maxn];
int n,m;

void Dijkstra_Input(){
    int i,j,a,b,c;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            map[i][j]=INF;
    for(i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(map[a][b]>c)
            map[a][b]=map[b][a]=c;      //有重边。。。
    }
}

int Dijkstra(int s,int e){
    int i,j,v;
    for(i=1;i<=n;i++)
        dis[i]=INF;
    for(i=1;i<=n;i++)
        dis[i]=map[s][i];
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    vis[s]=1;
    while(true){
        v=-1;
        for(i=1;i<=n;i++)
            if(!vis[i] && (v==-1 || dis[v]>dis[i]))
               v=i;
        if(v==-1) break;
        vis[v]=1;
        for(i=1;i<=n;i++)
            if(map[v][i]<INF && dis[i]>dis[v]+map[v][i])
                dis[i]=dis[v]+map[v][i];
    }
    return dis[e];
}

int main()
{
    scanf("%d%d",&m,&n);
    Dijkstra_Input();
    printf("%d\n",Dijkstra(1,n));
}
