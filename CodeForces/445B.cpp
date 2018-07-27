/****************
*PID:445b div2
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
int a[maxn],vis[maxn],vis2[maxn],deep[maxn];
vector<int> G[maxn],cc;

void dfs(int u,int pa,int d){
  //  res=max(res,d);
    vis[u]=1;
    deep[u]=d;
    cc.push_back(u);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(vis[v] || v==pa) continue;
        dfs(v,u,d+1);
    }
}

void dfs2(int u,int pa,int d){
    vis2[u]=1;
    deep[u]=d;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(vis2[v] || v==pa) continue;
        dfs2(v,u,d+1);
    }
}

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=0;i<=n;i++) G[i].clear();
        for(i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int cnt=0;
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++){
            if(!vis[i]){
                int res=1;
                cc.clear();
                dfs(i,-1,1);
              /*  int b=0,now=-1;
                for(j=0;j<cc.size();j++){
                  //  printf("dp=%d\n",deep[cc[j]]);
                    if(now<deep[cc[j]]){
                        now=deep[cc[j]];b=cc[j];
                    }
                }
                memset(vis2,0,sizeof(vis2));
               // printf("b=%d\n",b);
                dfs2(b,-1,1);
                for(j=0;j<cc.size();j++)
                    res=max(res,deep[cc[j]]);*/
                cnt+=cc.size()-1;
            }
        }
        printf("%I64d\n",(1LL<<(cnt)));
    }
    return 0;
}

