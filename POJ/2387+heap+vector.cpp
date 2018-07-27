/*
最短路：Dijkstra+heap+vector
*/
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=30000+10;
const int INF=1000000000;
int n,m,dis[maxn];

struct Edge{
    int to,v;
    Edge(int _to=1,int _v=INF):to(_to),v(_v){}
    bool operator < (const Edge &e) const {
        return v>e.v;           //注意这里是>，因为小的先出
    }
};

vector<vector<Edge> > G(maxn);

void Input(){
    int i,a,b,c;
    scanf("%d%d",&m,&n);
    for(i=0;i<=n;i++)
        G[i].clear();
    for(i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        G[a].push_back(Edge(b,c));      //有向
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
        for(i=0;i<G[E.to].size();i++){
            Edge ee = G[E.to][i];
            if(dis[ee.to]>dis[E.to]+ee.v){
                dis[ee.to]=dis[E.to]+ee.v;
                pq.push(Edge(ee.to,dis[ee.to]));
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

