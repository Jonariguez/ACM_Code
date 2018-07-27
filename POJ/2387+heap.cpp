/*
最短路：Dijkstra+heap+array
47ms
*/
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
const int INF=1000000000;
int n,m,map[maxn][maxn],dis[maxn];

struct Edge{
    int to,v;
    Edge(int _to=1,int _v=INF):to(_to),v(_v){}
    bool operator < (const Edge &e) const {
        return v>e.v;           //注意这里是>，因为小的先出
    }
};

void Input(){
    int i,j,a,b,c;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            map[i][j]=INF;
    for(i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(map[a][b]>c)
            map[a][b]=map[b][a]=c;
    }
}

int HeapDijkstra(int s,int e){
    int i;
    fill(dis,dis+n+1,INF);
    dis[s]=0;
    priority_queue<Edge> pq;
    pq.push(Edge(s,0));
    while(!pq.empty()){
        Edge E=pq.top();
        pq.pop();
        if(dis[E.to]<E.v) continue;
        for(i=1;i<=n;i++){
            if(map[E.to][i]<INF && dis[i]>dis[E.to]+map[E.to][i]){
                dis[i]=dis[E.to]+map[E.to][i];
                pq.push(Edge(i,dis[i]));
            }
        }
    }
    return dis[e];
}

int main()
{
    Input();
    printf("%d\n",HeapDijkstra(1,n));
    return 0;
}

