/****************
*PID:hdu2874
*Auth:Jonariguez
*****************
是否联通当然还是用并查集。
虽然是森林，但是还是可以像一个树那样处理，因为
不同的联通块是独立的，所以线段树+LCA+dis一样处理。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+5;
int head[maxn],wei[maxn*2],vv[maxn*2],nxt[maxn*2],phi[maxn*2],d[maxn*2],pos[maxn],e,dfs_clock,dis[maxn];
bool vis[maxn];

void Init(){
    memset(vis,0,sizeof(vis));
    memset(head,0,sizeof(head));
    memset(dis,0,sizeof(dis));
    e=1;dfs_clock=0;
}

void add(int u,int v,int w){
    wei[e]=w;vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

typedef struct Node{
    int u,v;
    bool operator < (const Node &r) const {
        return v<r.v;
    }
}node;

typedef struct UFSet{
    int par[maxn];
    void Init(int n){
        for(int i=0;i<=n;i++) par[i]=i;
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    bool Union(int u,int v){
        if((u=find(u))==(v=find(v))) return false;
        par[u]=v;
    }
}UFSet;

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
UFSet ufset;

void dfs(int u,int pa,int deep,int dist){
    phi[++dfs_clock]=u;d[dfs_clock]=deep;
    pos[u]=dfs_clock;
    dis[u]=dist;
    vis[u]=1;
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
    int i,j,n,m,q;
    while(scanf("%d%d%d",&n,&m,&q)!=EOF){
        Init();
        ufset.Init(n);
        int u,v,w;
        for(i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            ufset.Union(u,v);
            add(u,v,w);add(v,u,w);
        }
        for(i=1;i<=n;i++)
            ufset.find(i);
        for(i=1;i<=n;i++)
            if(vis[i]==0)
                dfs(i,-1,0,0);
        tree.build(1,1,dfs_clock);
        int x,y;
        node res;
        while(q--){
            scanf("%d%d",&u,&v);
            if(ufset.find(u)!=ufset.find(v)){
                printf("Not connected\n");
                continue;
            }
            x=min(pos[u],pos[v]);y=max(pos[u],pos[v]);
            res=tree.ask(x,y,1,1,dfs_clock);
            printf("%d\n",dis[u]+dis[v]-2*dis[res.u]);
        }
    }
    return 0;
}
