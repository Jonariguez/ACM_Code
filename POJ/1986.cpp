/****************
*PID:poj1986
*Auth:Jonariguez
*****************
类似于hdu2586，这里的东西南北方向是没用的，不用处理
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=40000+5;
int head[maxn],wei[maxn*2],vv[maxn*2],nxt[maxn*2],dfs_clock,e,phi[maxn*2],d[maxn*2],pos[maxn],dis[maxn];

void add(int u,int v,int w){
    wei[e]=w;vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

typedef struct Node{
    int v,u;
    bool operator < (const Node &r) const {
        return v<r.v;
    }
}node;

typedef struct segment{
    node sum[maxn*8];
    void pushUp(int k){
        sum[k]=min(sum[k*2],sum[k*2+1]);
    }
    void build(int k,int l,int r){
        if(l==r){
            sum[k].v=d[l];sum[k].u=phi[l];return ;
        }
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
        pushUp(k);
    }
    node ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        int m=(l+r)/2;
        node res;
        res.v=maxn;
        if(a<=m)
            res=min(res,ask(a,b,k*2,l,m));
        if(b>m)
            res=min(res,ask(a,b,k*2+1,m+1,r));
        return res;
    }
}Tree;

Tree tree;

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
    dfs(1,-1,0,0);
    tree.build(1,1,dfs_clock);
    scanf("%d",&k);
    while(k--){
        scanf("%d%d",&u,&v);
        int x=min(pos[u],pos[v]),y=max(pos[u],pos[v]);
        node res=tree.ask(x,y,1,1,dfs_clock);
        printf("%d\n",dis[u]+dis[v]-2*dis[res.u]);
    }
    return 0;
}
