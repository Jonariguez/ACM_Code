/****************
*PID:uva11374
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=500+10;
const int maxm=1000+10;
const int INF=1e9;
struct Edge{
    int from,to,dist;
};
struct HeapNode{
    int d,u;
    bool operator < (const HeapNode &r) const {
        return d>r.d;
    }
};
struct Dijkstra{
    int n,m,d[maxn],par[maxn];
    bool vis[maxn];
    vector<Edge> edges;
    vector<int> G[maxn];
    void init(int n){
        this->n=n;
        for(int i=0;i<=n;i++) G[i].clear();
        edges.clear();
    }
    void add(int from,int to,int dist){
        edges.push_back((Edge){from,to,dist});
        m=edges.size()-1;
        G[from].push_back(m);
    }
    void dijkstra(int s){
        priority_queue<HeapNode> Q;
        for(int i=0;i<=n;i++) d[i]=INF;
        d[s]=0;
        memset(vis,0,sizeof(vis));
        Q.push((HeapNode){0,s});
        while(!Q.empty()){
            HeapNode x=Q.top();Q.pop();
            int u=x.u;
            if(vis[u]) continue;
            vis[u]=1;
            for(int i=0;i<G[u].size();i++){
                Edge& e=edges[G[u][i]];
                if(d[e.to]>d[u]+e.dist){
                    d[e.to]=d[u]+e.dist;
                    par[e.to]=G[u][i];
                    Q.push((HeapNode){d[e.to],e.to});
                }
            }
        }
    }
    void GetShortestPaths(int s,int *dist,vector<int>* path){
        dijkstra(s);
        for(int i=1;i<=n;i++){
            dist[i]=d[i];
            path[i].clear();
            int t=i;
            path[i].push_back(t);
            while(t!=s){
                path[i].push_back(edges[par[t]].from);
                t=edges[par[t]].from;
            }
            reverse(path[i].begin(),path[i].end());
        }
    }
}solve;

int d1[maxn],d2[maxn];
vector<int> path1[maxn],path2[maxn];

int main()
{
    int i,j,n,m,s,e,kcase=0;
    while(scanf("%d%d%d",&n,&s,&e)!=EOF){
        solve.init(n);
        scanf("%d",&m);
        int u,v,w;
        for(i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            solve.add(u,v,w);solve.add(v,u,w);
        }
        solve.GetShortestPaths(s,d1,path1);
        solve.GetShortestPaths(e,d2,path2);
        vector<int> path=path1[e];
        int res=d1[e],midpoint=-1;
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            for(j=0;j<2;j++){
                if(res>d1[u]+d2[v]+w){
                    res=d1[u]+d2[v]+w;
                    path=path1[u];
                    for(int z=path2[v].size()-1;z>=0;z--)
                        path.push_back(path2[v][z]);
                    midpoint=u;
                }
                swap(u,v);
            }
        }
        if(kcase) puts("");
        kcase++;
        printf("%d",s);
        for(i=1;i<path.size();i++)
            printf(" %d",path[i]);
        if(midpoint==-1)
            printf("\nTicket Not Used\n");
        else printf("\n%d\n",midpoint);
        printf("%d\n",res);
    }
    return 0;
}

