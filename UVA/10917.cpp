/****************
*PID:uva10917
*Auth:Jonariguez
*****************
题目中说的不走回头路的意思就是:设d[i]为从点i到
家的最短距离，从A能走到B的条件是d[A]>d[B]
跑Dijkstra，然后由d数组，d[A]>d[B]，连边B->A，
建图得DAG，dp[i]表示从公司(点1)从点i的路径数。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000+10;
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
        m=edges.size();
        G[from].push_back(m-1);
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
}solve;

vector<int> G[maxn];
int dp[maxn],vis[maxn][maxn];

int dfs(int u){
    if(u==1) return 1;
    if(dp[u]>0) return dp[u];
    int sum=0;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        sum+=dfs(v);
    }
    return dp[u]=sum;
}

int main()
{
    int i,j,n,m,res;
    while(scanf("%d",&n),n){
        scanf("%d",&m);
        solve.init(n);
        int u,v,w;
        memset(vis,0,sizeof(vis));
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&w);
            vis[u][v]=vis[v][u]=1;
            solve.add(u,v,w);
            solve.add(v,u,w);
        }
        solve.dijkstra(2);
        for(i=0;i<=n;i++)
            G[i].clear();
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                if(!vis[i][j]) continue;    //前提是i和j之间有边。
                if(solve.d[i]>solve.d[j])
                    G[j].push_back(i);
                else if(solve.d[j]>solve.d[i])
                    G[i].push_back(j);
            }
        }
        memset(dp,0,sizeof(dp));
        printf("%d\n",dfs(2));
    }
    return 0;
}
