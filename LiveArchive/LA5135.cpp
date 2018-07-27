/****************
*PID:la5135
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
const int maxn=100000+10;
vector<int> G[maxn],bcc[maxn];
int pre[maxn],iscut[maxn],bccno[maxn],vis[maxn],dfs_clock,bcc_cnt;
struct Edge{
    int u,v;
    Edge(int u=0,int v=0):u(u),v(v){}
};
stack<Edge> S;

int dfs(int u,int pa){
    int lowu=pre[u]=++dfs_clock,son=0,i;
    for(i=0;i<G[u].size();i++){
        int v=G[u][i];
        Edge e=Edge(u,v);
        if(!pre[v]){
            son++;
            S.push(e);
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
        }else if(v!=pa && pre[v]<pre[u]){
            S.push(e);
            lowu=min(lowu,pre[v]);
        }
    }
    if(pa<0 && son==1) iscut[u]=0;
    return lowu;
}


void find_bcc(int n){
    memset(pre,0,sizeof(pre));
    memset(bccno,0,sizeof(bccno));
    memset(iscut,0,sizeof(iscut));
    dfs_clock=bcc_cnt=0;
    for(int i=0;i<n;i++)
        if(!pre[i])
            dfs(i,-1);
}

int main()
{
    int i,j,n,kcase=1;
    while(scanf("%d",&n),n){
        int u,v,cnt=0;
        memset(vis,0,sizeof(vis));
        for(i=0;i<n*2;i++)
            G[i].clear();
        for(i=1;i<=n;i++){
            scanf("%d%d",&u,&v);
            u--;v--;
            G[u].push_back(v);
            G[v].push_back(u);
            if(vis[u]==0) cnt++;
            if(vis[v]==0) cnt++;
            vis[u]=vis[v]=1;
        }
        find_bcc(cnt);
        LL res1=0,res2=1;
        for(i=1;i<=bcc_cnt;i++){
            int cut_cnt=0;
            for(j=0;j<bcc[i].size();j++)
                if(iscut[bcc[i][j]]) cut_cnt++;
            if(cut_cnt==1){
                res1++;res2*=(LL)(bcc[i].size()-cut_cnt);
            }
        }
        if(bcc_cnt==1){
            res1=2;res2=(LL)(bcc[1].size()-1)*bcc[1].size()/2;
        }
        printf("Case %d: %lld %lld\n",kcase++,res1,res2);
    }
    return 0;
}
