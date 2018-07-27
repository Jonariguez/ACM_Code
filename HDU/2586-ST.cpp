/****************
*PID:hdu2586
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=80000+10;
int head[maxn],vv[maxn*2],nxt[maxn*2],wei[maxn*2],phi[maxn*2],dis[maxn],d[maxn*2],e,dfs_clock;
int start[maxn],dp[maxn*2][25];

void Init(){
    memset(head,0,sizeof(head));
    e=1;dfs_clock=0;
}

void add(int u,int v,int w){
    vv[e]=v;wei[e]=w;nxt[e]=head[u];head[u]=e++;
}

void dfs(int u,int pa,int deep,int D){
    start[u]=++dfs_clock;phi[dfs_clock]=u;
    d[dfs_clock]=deep;dis[u]=D;
    for(int i=head[u];i;i=nxt[i]){
        int v=vv[i],w=wei[i];
        if(v==pa) continue;
        dfs(v,u,deep+1,D+w);
        phi[++dfs_clock]=u;
        d[dfs_clock]=deep;
    }
}

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        Init();
        int u,v,w;
        for(i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);add(v,u,w);
        }
        dfs(1,-1,1,0);
        for(i=1;i<=dfs_clock;i++)
            dp[i][0]=i;
        int k=(int)(log((double)dfs_clock)/log(2.0));
        for(i=1;i<=k;i++){
            for(j=1;j+(1<<i)-1<=dfs_clock;j++){
                if(d[dp[j][i-1]]<d[dp[j+(1<<(i-1))][i-1]])
                    dp[j][i]=dp[j][i-1];
                else dp[j][i]=dp[j+(1<<(i-1))][i-1];
            }
        }
        while(m--){
            scanf("%d%d",&u,&v);
            int x=start[u],y=start[v];
            if(x>y)
                swap(x,y);
            int k=(int)(log((double)(y-x+1))/log(2.0));
            int res;
            if(d[dp[x][k]]<d[dp[y-(1<<k)+1][k]])
                res=dp[x][k];
            else res=dp[y-(1<<k)+1][k];
            printf("%d\n",dis[u]+dis[v]-2*dis[phi[res]]);
        }
    }
    return 0;
}
