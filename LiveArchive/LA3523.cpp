/****************
*PID:la3523
*Auth:Jonariguez
*****************
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
vector<int> G[maxn],bcc[maxn];
int odd[maxn],par[maxn],color[maxn],A[maxn][maxn];
int pre[maxn],iscut[maxn],bccno[maxn],dfs_clock,bcc_cnt;

struct Edge{
    int u,v;
    Edge(int u=0,int v=0):u(u),v(v){}
};
stack<Edge> S;

int dfs(int u,int pa){
    int lowu=pre[u]=++dfs_clock;
    int child=0,i;
    for(i=0;i<G[u].size();i++){
        int v=G[u][i];
        Edge e=(Edge){u,v};
        if(!pre[v]){
            S.push(e);
            child++;
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=pre[u]){
                iscut[u]=1;
                bcc_cnt++;bcc[bcc_cnt].clear();
                for(;;){
                    Edge x=S.top();S.pop();
                    if(bccno[x.u]!=bcc_cnt){
                        bcc[bcc_cnt].push_back(x.u);bccno[x.u]=bcc_cnt;
                    }
                    if(bccno[x.v]!=bcc_cnt){
                        bcc[bcc_cnt].push_back(x.v);bccno[x.v]=bcc_cnt;
                    }
                    if(x.u==u && x.v==v) break;
                }
            }
        }else if(pre[v]<pre[u] && v!=pa){
            S.push(e);
            lowu=min(lowu,pre[v]);
        }
    }
    if(pa<0 && child==1) iscut[u]=0;
    return lowu;
}

void find_bcc(int n){
    memset(pre,0,sizeof(pre));
    memset(iscut,0,sizeof(iscut));
    memset(bccno,0,sizeof(bccno));
    dfs_clock=bcc_cnt=0;
    for(int i=0;i<n;i++)
        if(!pre[i]) dfs(i,-1);
}

bool bipartite(int u,int b){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(bccno[v]!=b) continue;
        if(color[v]==color[u]) return false;
        if(!color[v]){
            color[v]=3-color[u];
            if(!bipartite(v,b))
                return false;
        }
    }
    return true;
}

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        for(i=0;i<=n;i++)
            G[i].clear();
        memset(A,0,sizeof(A));
        for(i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            u--;v--;
            A[u][v]=A[v][u]=1;
        }
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(!A[i][j]){
                    G[i].push_back(j);G[j].push_back(i);
                }
            }
        }
        find_bcc(n);
        memset(odd,0,sizeof(odd));
        for(i=1;i<=bcc_cnt;i++){
            memset(color,0,sizeof(color));
          //  for(j=0;j<bcc[i].size();j++)
          //      bccno[bcc[i][j]]=i;
            int u=bcc[i][0];
            color[u]=1;
            if(!bipartite(u,i))
                for(j=0;j<bcc[i].size();j++)
                    odd[bcc[i][j]]=1;
        }
        int res=n;
        for(i=0;i<n;i++)
            if(odd[i])
                res--;
        printf("%d\n",res);
    }
    return 0;
}
