/*
最短路：spfa算法 期望复杂度：O(E)   32ms(dijksral+heap:=47ms)
第一次写spfa，以前不知道时因为是多复杂多nb的算法，
其实就是Bellman-ford算法的改进，每次不再是盲目地
对所有的点的边进行判断并松弛，而是对那些上次因松弛
而dis改变的点进行松弛，这些点用一个队列维护即可
比Dijkstra+heap还要快
*/
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

const int maxn=1000+10;
const int inf=2000000;

int n,m,map[maxn][maxn],vis[maxn],dis[maxn];

void Input(){
    int i,j,a,b,c;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            map[i][j]=inf;
    for(i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(map[a][b]>c)
            map[a][b]=map[b][a]=c;
    }
}

int spfa(int s,int e){
    int i;
    memset(vis,0,sizeof(vis));
    fill(dis,dis+n+1,inf);
    dis[s]=0;vis[s]=1;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int t=que.front();que.pop();
        for(i=1;i<=n;i++)
            if(map[t][i]<inf && dis[i]>dis[t]+map[t][i]){
                dis[i]=dis[t]+map[t][i];
                que.push(i);
            }
    }
    return dis[e];
}

int main()
{
    Input();
    printf("%d\n",spfa(n,1));
    return 0;
}
