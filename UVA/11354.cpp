/****************
*PID:uva11354
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=50000+10;
const int INF=1e9+7;
int par[maxn],fa[maxn],cost[maxn],anc[maxn][20],maxcost[maxn][20];
int deep[maxn];
vector<int> G[maxn],C[maxn];

struct Edge{
    int a,b,w;
}s[maxn*2];

int cmp(const Edge &x,const Edge &y){
    return x.w<y.w;
}

void Init(int n){
    for(int i=0;i<=n;i++){
        G[i].clear();par[i]=i;
        C[i].clear();
    }
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

bool Union(int u,int v){
    if((u=find(u))==(v=find(v))) return false;
    par[u]=v;
    return true;
}

void dfs(int u,int pa,int W,int D){
    fa[u]=pa;
    cost[u]=W;
    deep[u]=D;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==pa) continue;
        dfs(v,u,C[u][i],D+1);
    }
}


int main()
{
    int i,j,n,m,kcase=0;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(kcase++) puts("");
        for(i=1;i<=m;i++)
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].w);
        sort(s+1,s+m+1,cmp);
        Init(n);
        int cnt=0;
        for(i=1;i<=m;i++){
            if(Union(s[i].a,s[i].b)){
                G[s[i].a].push_back(s[i].b);
                C[s[i].a].push_back(s[i].w);
                G[s[i].b].push_back(s[i].a);
                C[s[i].b].push_back(s[i].w);
                if(++cnt==n-1) break;
            }
        }
        dfs(1,-1,0,1);
        for(i=1;i<=n;i++){
            anc[i][0]=fa[i];maxcost[i][0]=cost[i];
            for(j=1;(1<<j)<=n;j++) anc[i][j]=-1;
        }
        for(j=1;(1<<j)<=n;j++){
            for(i=1;i<=n;i++){
                if(anc[i][j-1]!=-1){
                    int a=anc[i][j-1];
                    anc[i][j]=anc[a][j-1];
                    maxcost[i][j]=max(maxcost[i][j-1],maxcost[a][j-1]);
                }
            }
        }
        scanf("%d",&m);
        while(m--){
            int p,q;
            scanf("%d%d",&p,&q);
            if(deep[p]<deep[q])
                swap(p,q);
            int log;
            for(log=1;(1<<log)<=deep[p];log++);
            log--;
            int res=-INF;
            for(int i=log;i>=0;i--)
                if(deep[p]-(1<<i)>=deep[q]){
                    res=max(res,maxcost[p][i]);
                    p=anc[p][i];
                }
            if(p==q){
                printf("%d\n",res);continue;
            }
            for(i=log;i>=0;i--){
                if(anc[p][i]!=anc[q][i]){
                    res=max(res,maxcost[p][i]);
                    res=max(res,maxcost[q][i]);
                    p=anc[p][i];q=anc[q][i];
                }
            }
            res=max(res,max(cost[p],cost[q]));
            printf("%d\n",res);
        }
    }
    return 0;
}
