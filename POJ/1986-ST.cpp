/****************
*PID:poj1986
*Auth:Jonariguez
*****************
ST
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=40000+5;
int head[maxn],wei[maxn*2],vv[maxn*2],nxt[maxn*2],dfs_clock,e,phi[maxn*2],d[maxn*2],pos[maxn],dis[maxn];
int dp[maxn*2][32];

void add(int u,int v,int w){
    wei[e]=w;vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

void dfs(int u,int pa,int deep,int dist){
    phi[++dfs_clock]=u;pos[u]=dfs_clock;dis[u]=dist;
    d[dfs_clock]=deep;
    int i;
    for(i=head[u];i;i=nxt[i]){
        int v=vv[i],w=wei[i];
        if(v!=pa){
            dfs(v,u,deep+1,dist+w);
            phi[++dfs_clock]=u;
            d[dfs_clock]=deep;
        }
    }
}

void ST(int len){
    int k=(int)(log((double)len)/log(2.0));
    int i,j;
    for(i=1;i<=len;i++) dp[i][0]=i;
    for(j=1;j<=k;j++){
        for(i=1;i+(1<<j)-1<=len;i++){
            int a=dp[i][j-1],b=dp[i+(1<<(j-1))][j-1];
            if(d[a]<d[b]) dp[i][j]=a;
            else dp[i][j]=b;
        }
    }
}

int RMQ(int x,int y){//RMQ只返回最小深度在深度序列d中的位置，d和phi是同步长度的，那么对应的位置对应的节点为phi序列中的
    int k=(int)(log((double)(y-x+1))/log(2.0));
    int a=dp[x][k],b=dp[y-(1<<k)+1][k];
    if(d[a]<d[b]) return a;
    return b;
}

int LCA(int u,int v){
    u=pos[u];v=pos[v];
    if(u>v)
        swap(u,v);
    return phi[RMQ(u,v)];   //这个位置对应的节点
}

int main()
{
    int i,j,n,m,k;
    scanf("%d%d",&n,&m);
    memset(head,0,sizeof(head));
    memset(dis,0,sizeof(dis));
    e=1;dfs_clock=0;
    char str[5];
    int u,v,w;
    for(i=0;i<m;i++){
        scanf("%d%d%d%s",&u,&v,&w,str);
        add(u,v,w);add(v,u,w);
    }
    dfs(1,-1,1,0);
    ST(dfs_clock);
    scanf("%d",&k);
    while(k--){
        scanf("%d%d",&u,&v);
        int lca=LCA(u,v);
        printf("%d\n",dis[u]+dis[v]-2*dis[lca]);
    }
    return 0;
}
