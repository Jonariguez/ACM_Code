/****************
*PID:uva11324
*Auth:Jonariguez
*****************
将强连通分量缩点，然后得到SCC图g，每个点的权值等于
每个联通分量的顶点的个数，SCC图是个DAG，求最大路径用dp
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000+5;
int pre[maxn],low[maxn],sccno[maxn],Size[maxn],dfs_clock,scc_cnt;
int dp[maxn];
bool vis[maxn][maxn];
vector<int> G[maxn],g[maxn];
stack<int> S;

void Tarjan(int u,int pa){
    low[u]=pre[u]=++dfs_clock;
    S.push(u);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!pre[v]){        //利用树边更新
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }else if(!sccno[v]){    //利用反向边更新
            low[u]=min(low[u],pre[v]);
        }
    }
    if(low[u]==pre[u]){
        scc_cnt++;
        for(;;){
            int x=S.top();S.pop();
            sccno[x]=scc_cnt;
            if(x==u) break;
        }
    }
}

void find_scc(int n){
    memset(pre,0,sizeof(pre));
    memset(sccno,0,sizeof(sccno));
    memset(Size,0,sizeof(Size));
    dfs_clock=scc_cnt=0;
    for(int i=1;i<=n;i++)
        if(!pre[i]) Tarjan(i,-1);
}

int DP(int u){
    if(dp[u]) return dp[u];
    if(g[u].size()==0)
        return dp[u]=Size[u];
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        dp[u]=max(dp[u],DP(v));
    }
    dp[u]+=Size[u];
    return dp[u];
}

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        int u,v;
        for(i=0;i<=n;i++){
            G[i].clear();
            g[i].clear();
        }
        for(i=1;i<=m;i++){
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        find_scc(n);
        memset(vis,0,sizeof(vis));
        for(u=1;u<=n;u++){
            Size[sccno[u]]++;    //保存每个强联通分量的节点个数，为dp做权值
            for(i=0;i<G[u].size();i++){
                v=G[u][i];
                if(sccno[v]!=sccno[u]){
                    int sv=sccno[v],su=sccno[u];
                    if(vis[sv][su]==0)
                        g[sv].push_back(su);
                    vis[sv][su]=1;
                }
            }
        }
        memset(dp,0,sizeof(dp));
        int res=0;
        for(i=1;i<=scc_cnt;i++)
            res=max(res,DP(i));
        printf("%d\n",res);
    }
    return 0;
}

