/****************
*PID:la4080
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
        memset(par,-1,sizeof(par))      //-1表示往上没有树边，即根。
        edges.clear();
    }
    void add(int from,int to,int dist){
        edges.push_back((Edge){from,to,dist});
        m=edges.size();
        G[from].push_back(m-1);
    }
    void dijkstra(int s,int no){        //在edges中，下标为no的边删掉，即不用。
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
                if(G[u][i]==no) continue;   //该边已经删，不用改边。
                Edge& e=edges[G[u][i]];
                if(d[e.to]>d[u]+e.dist){
                    d[e.to]=d[u]+e.dist;
                    par[e.to]=G[u][i];
                    Q.push((HeapNode){d[e.to],e.to});
                }
            }
        }
    }
    void getTreeEdges(vector<int>& tree){
        for(int i=1;i<=n;i++)
            if(par[i]) tree.push_back(par[i]);
    }
}solve;

vector<int> tree;

int main()
{
    int i,j,n,m,L;
    while(scanf("%d%d%d",&n,&m,&L)!=EOF){
        solve.init(n);
        int u,v,w;
        for(i=0;i<m;i++){
            scanf("%d%d%dd",&u,&v,&w);
            solve.add(u,v,w);
            solve.add(v,u,w);
        }
        solve.dijkstra(1,-1);   //-1表示暂不删边，所有的边都用
        tree.clear();
        solve.getTreeEdge(tree);
        LL res=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=

