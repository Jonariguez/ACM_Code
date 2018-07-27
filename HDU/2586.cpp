/****************
*PID:hdu2586
*Auth:Jonariguez
*****************
记录每个点到根的距离dis，则答案为：
dis[u]+dis[v]-2*dis[LCA(u,v)]
线段树维护的节点类型是node，即欧拉序列和深度序列。
按深度序列构造和查询线段树，真正取值是欧拉
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=40000+5;
int head[maxn],vv[maxn*2],wei[maxn*2],nxt[maxn*2],a[maxn*2],fan[maxn*2],b[maxn],dis[maxn],e,dfs_clock;

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
            sum[k].v=a[l];sum[k].u=fan[l];return ;
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

void dfs(int u,int pa,int deep,int d){
    a[++dfs_clock]=deep;b[u]=dfs_clock;dis[u]=d;
    fan[dfs_clock]=u;//printf("u=%d,deep=%d\n",u,deep);
    int i,flag=0;
    for(i=head[u];i;i=nxt[i]){
        int v=vv[i],w=wei[i];
        if(v!=pa){
            dfs(v,u,deep+1,d+w);
            a[++dfs_clock]=deep;//printf("u=%d,deep=%d\n",u,deep);
            fan[dfs_clock]=u;
          //  flag=1;
        }
    }
   // if(flag==0) return ;
}

int main()
{
    int i,j,n,res,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(head,0,sizeof(head));
        memset(dis,0,sizeof(dis));
        e=1;dfs_clock=0;
        for(i=1;i<n;i++){
            int u_,v_,w_;
            scanf("%d%d%d",&u_,&v_,&w_);
            add(u_,v_,w_);
            add(v_,u_,w_);
        }
        dfs(1,-1,0,0);
        tree.build(1,1,dfs_clock);
     //   for(i=1;i<=dfs_clock;i++) printf("a=%d\n",a[i]);
        int u,v;
        while(m--){
            scanf("%d%d",&u,&v);
            int x=min(b[u],b[v]),y=max(b[u],b[v]);
            node q=tree.ask(x,y,1,1,dfs_clock);
      //      printf("q.u=%d\n",q.u);
            printf("%d\n",dis[u]+dis[v]-2*dis[q.u]);
        }
        //printf("\n");
    }
    return 0;
}
