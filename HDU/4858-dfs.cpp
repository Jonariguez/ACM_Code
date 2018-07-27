/****************
*PID:hdu4858
*Auth:Jonariguez
*****************
将图转成有根树，每次操作，树边上打标记，非树边暴力。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
vector<int> G[maxn],g[maxn];
//val记录节点的能量值，res[i]记录有根树上，在节点i以下，且和节点i相连的节点的能量值之和。
//由res的定义可知，每次对节点u的修改操作只修改u的父亲和u指向祖先的非树边，而指向子孙的边
//并不做处理，（因为在处理子孙时会把子孙的影响更新到u）
int par[maxn],pre[maxn],cnt[maxn],val[maxn],res[maxn],dfs_clock;    //pre[i]记录dfs序

void dfs(int u,int pa){
    pre[u]=++dfs_clock;
    par[u]=pa;cnt[u]++; //因为有重边，所以cnt[u]记录节点u指向父亲节点的边的个数
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==pa) continue;     //反向边不处理。
        if(!pre[v])         //没被访问过
            dfs(v,u);
        else if(pre[v]<pre[u]){    //非树边
            g[u].push_back(v);
            g[v].push_back(u);
        }else if(par[v]==u) //重边，那么u->v就多条边，即v指向父亲(u)的边就多一条。
            cnt[v]++;
    }
}

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=0;i<=n;i++){
            G[i].clear();g[i].clear();
            pre[i]=cnt[i]=0;
        }
        memset(val,0,sizeof(val));
        memset(res,0,sizeof(res));
        dfs_clock=0;
        for(i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs(1,0);
        int Q;
        scanf("%d",&Q);
        while(Q--){
            int o,u,v;
            scanf("%d",&o);
            if(o==0){
                scanf("%d%d",&u,&v);
                val[u]+=v;
                if(par[u])
                    res[par[u]]+=cnt[u]*v;  //修改对父亲的影响
                for(i=0;i<g[u].size();i++){
                    int t=g[u][i];
                    if(pre[t]<pre[u]){   //修改对祖先的影响
                        res[t]+=v;
                    }
                }
            }else {
                scanf("%d",&u);
                int ans=0;      //答案由3部分组成：父亲的能量值val[par[u]]+子孙的总影响res[u]+祖先对u的影响(暴力)
                if(par[u]) ans=cnt[u]*val[par[u]]; //注意不要忘了乘cnt[u]!!!!
                ans+=res[u];
                for(i=0;i<g[u].size();i++){
                    int t=g[u][i];
                    if(pre[t]<pre[u])
                        ans+=val[t];
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

/*
1
4 6
1 2
1 3
2 3
3 4
2 4
3 2
30
0 1 2

*/
