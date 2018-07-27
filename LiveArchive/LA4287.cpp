/****************
*PID:la4287
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

const int maxn=20000+5;
int low[maxn],pre[maxn],sccno[maxn],in[maxn],out[maxn],dfs_clock,scc_cnt;
vector<int> G[maxn];
stack<int> S;

void dfs(int u,int pa){
    low[u]=pre[u]=++dfs_clock;
    S.push(u);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!pre[v]){        // 利用树边更新
            dfs(v,u);
            low[u]=min(low[u],low[v]);
        }else if(!sccno[v]){        //利用反向边更新
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
    dfs_clock=scc_cnt=0;
    memset(sccno,0,sizeof(sccno));
    memset(pre,0,sizeof(sccno));
    for(int i=0;i<n;i++)
        if(!pre[i]) dfs(i,-1);
}

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            G[i].clear();
        int u,v;
        for(i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            u--;v--;
            G[u].push_back(v);
        }
        find_scc(n);
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int u=0;u<n;u++){
            for(j=0;j<G[u].size();j++){
                int v=G[u][j];
                if(sccno[u]!=sccno[v])
                    in[sccno[v]]=out[sccno[u]]=1;
            }
        }
        int a=0,b=0;
        for(i=1;i<=scc_cnt;i++){
            if(!in[i]) a++;
            if(!out[i]) b++;
        }
        int res=max(a,b);
        if(scc_cnt==1) res=0;
        printf("%d\n",res);
    }
    return 0;
}
