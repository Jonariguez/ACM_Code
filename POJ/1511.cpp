/****************
*PID:poj1511
*Auth:Jonariguez
*****************
从1到各点的最短距离用Dij求。
然后从各点回到1的最短距离，就将边反向，然后再以1为起点跑Dij
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=2000000+10;
const LL INF=(LL)1e18;
LL n,m,dis[maxn];
LL head[maxn],nxt[maxn],wei[maxn],vv[maxn],e;
LL a[maxn],b[maxn],c[maxn];
int vis[maxn];

void add(LL u,LL v,LL w){
    wei[e]=w;vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

struct cmp{
    bool operator () (const LL a,const LL b){
        return dis[a]>dis[b];
    }
};

void Dijkstra(){
    memset(vis,0,sizeof(vis));
    fill(dis,dis+n+1,INF);
    LL i;
    priority_queue<LL,vector<LL>,cmp> que;
    dis[1]=0;
    que.push(1);
    while(!que.empty()){
        LL u=que.top();que.pop();
        vis[u]=1;
        for(i=head[u];i;i=nxt[i]){
            LL v=vv[i],w=wei[i];
            if(vis[v]==0 && dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                que.push(v);
            }
        }
    }
}

int main()
{
    LL i,j;
    int T_T;
    scanf("%d",&T_T);
    while(T_T--){
        scanf("%I64d%I64d",&n,&m);
        memset(head,0,sizeof(head));
        e=1;
        for(i=1;i<=m;++i){
            scanf("%I64d%I64d%I64d",&a[i],&b[i],&c[i]);
            add(a[i],b[i],c[i]);
        }
        LL res=0;
        Dijkstra();
        for(i=1;i<=n;i++) res+=dis[i];
        memset(head,0,sizeof(head));
        e=1;
        for(i=1;i<=m;i++)
            add(b[i],a[i],c[i]);
        Dijkstra();
        for(i=1;i<=n;i++) res+=dis[i];
        printf("%I64d\n",res);
    }
    return 0;
}

