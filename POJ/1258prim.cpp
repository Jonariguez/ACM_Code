/*
Prim+heap
很少写，照的模板写的
写Prim是为了写次小生成树
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=100+10;
const int INF=100000+10;
int n;

struct Edge{
    int b,v;
    Edge(int _b=0,int _v=INF):b(_b),v(_v){}
    bool operator < (const Edge &e) const {
        return v>e.v;
    }
};

vector<vector<Edge> > G(maxn);

void Prim_Input(){
    int i,j;
    for(i=0;i<=n;i++)
        G[i].clear();
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            int t;
            scanf("%d",&t);
            G[i].push_back(Edge(j,t));
        }
}

int HeapPrim(){
    int i,j,k;
    int vis[maxn],dis[maxn],tot=0;
    priority_queue<Edge> pq;
    memset(vis,0,sizeof(vis));
    for(i=0;i<=n;i++)
        dis[i]=INF;
    int TreeLong=0;
    pq.push(Edge(1,0));
    while(tot<n && !pq.empty()){
        Edge E;
        do {
            E=pq.top();pq.pop();
        }while(vis[E.b]==1 && !pq.empty());
        if(vis[E.b]==0){
            TreeLong+=E.v;vis[E.b]=1;tot++;
            for(i=0;i<G[E.b].size();i++){
                int d=G[E.b][i].b;
                if(vis[d]==0){
                    int w=G[E.b][i].v;
                    if(dis[d]>w){
                        dis[d]=w;
                        pq.push(Edge(d,w));
                    }
                }
            }
        }
    }
    if(tot<n)
        return -1;
    return TreeLong;
}


int main()
{
    int i;
    while(scanf("%d",&n)!=EOF){
        Prim_Input();
        printf("%d\n",HeapPrim());
    }
    return 0;
}
