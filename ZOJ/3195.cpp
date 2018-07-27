/****************
*PID:zoj3195
*Auth:Jonariguez
*****************
对于给定的3个点a，b，c，两两求最近距离求和然后/2
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=50000+5;
int head[maxn],wei[maxn*2],vv[maxn*2],nxt[maxn*2],phi[maxn*2],d[maxn*2],pos[maxn],e,dfs_clock,dis[maxn];

void Init(){
    memset(head,0,sizeof(head));
    memset(dis,0,sizeof(dis));
    e=1;dfs_clock=0;
}

int add(int u,int v,int w){
    wei[e]=w;vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

typedef struct Node{
    int u,v;
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
    phi[++dfs_clock]=u;
    d[dfs_clock]=deep;
    pos[u]=dfs_clock;
    dis[u]=dist;
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
    int i,j,n,m,T_T=0;
    while(scanf("%d",&n)!=EOF){
        if(T_T++) puts("");
        Init();
        for(i=1;i<n;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            u++;v++;
            add(u,v,w);add(v,u,w);
        }
        dfs(1,-1,0,0);
        tree.build(1,1,dfs_clock);
        int a,b,c;
        scanf("%d",&m);
        while(m--){
            int sum=0;
            scanf("%d%d%d",&a,&b,&c);
            a++;b++;c++;
            int x=min(pos[a],pos[b]),y=max(pos[a],pos[b]);
            node res=tree.ask(x,y,1,1,dfs_clock);
            sum+=dis[a]+dis[b]-2*dis[res.u];
            x=min(pos[a],pos[c]);y=max(pos[a],pos[c]);
            res=tree.ask(x,y,1,1,dfs_clock);
            sum+=dis[a]+dis[c]-2*dis[res.u];
            x=min(pos[c],pos[b]);y=max(pos[c],pos[b]);
            res=tree.ask(x,y,1,1,dfs_clock);
            sum+=dis[c]+dis[b]-2*dis[res.u];
            printf("%d\n",sum/2);
        }
    }
    return 0;
}
