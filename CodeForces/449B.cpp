/****************
*PID:449b div1
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

const int maxn=100000+5;
const int maxm=300000+5;
const LL INF=2e18;
int cnt;
struct Edge{
    LL from,to,dist;
    bool train;
};
struct HeapNode{
    LL d,u;
    bool operator < (const HeapNode &r) const {
        return d>r.d;
    }
};
struct Dijkstra{
    int n,m;
    LL d[maxn],par[maxn];
    bool vis[maxn];
    vector<Edge> edges;
    vector<LL> G[maxn];
    void init(int n){
        this->n=n;edges.clear();
        for(LL i=0;i<=n;i++){
            G[i].clear();par[i]=-1;
        }
    }
    void add(LL from,LL to,LL dist,bool train){
        edges.push_back((Edge){from,to,dist,train});
        m=edges.size();
        G[from].push_back(m-1);
    }
    void dijkstra(LL s){
        priority_queue<HeapNode> Q;
        for(LL i=0;i<=n;i++) d[i]=INF;
        d[s]=0;
        memset(vis,0,sizeof(vis));
        Q.push((HeapNode){0LL,s});
        while(!Q.empty()){
            HeapNode x=Q.top();Q.pop();
            LL u=x.u;
            if(vis[u]) continue;
            vis[u]=1;
            if(par[u]>=0 && edges[par[u]].train) cnt++;
            for(LL i=0;i<G[u].size();i++){
                Edge& e=edges[G[u][i]];
                if(d[e.to]>d[u]+e.dist || (d[e.to]==d[u]+e.dist && par[e.to]>=0 && edges[par[e.to]].train)){
                    d[e.to]=d[u]+e.dist;
                    par[e.to]=G[u][i];
                    Q.push((HeapNode){d[e.to],e.to});
                }
            }
        }
    }
}solve;

int main()
{
    int i,j,n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        solve.init(n);
        LL u,v,w;
        for(i=1;i<=m;i++){
            scanf("%I64d%I64d%I64d",&u,&v,&w);
            solve.add(u,v,w,false);solve.add(v,u,w,false);
        }
        for(i=1;i<=k;i++){
            scanf("%I64d%I64d",&u,&v);
            solve.add(1LL,u,v,true);
            solve.add(u,1LL,v,true);
        }
      //  for(i=1;i<=m;i++){
      //      solve.add(x[i],y[i],w[i],false);
      //      solve.add(y[i],x[i],w[i],false);
      //  }
        cnt=0;
        solve.dijkstra(1LL);
        printf("%d\n",k-cnt);
    }
    return 0;
}
