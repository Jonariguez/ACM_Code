/****************
*PID:hdu3078
*Auth:Jonariguez
*****************
求LCA
对于k>0的，求出最短路径上的全部点值保存，排序输出即可
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=80000+5;
int head[maxn],vv[maxn*2],nxt[maxn*2],d[maxn*2],phi[maxn*2],pos[maxn],par[maxn],e,dfs_clock,a[maxn];
int ans[maxn];

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
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

void dfs(int u,int pa,int deep){
    phi[++dfs_clock]=u;d[dfs_clock]=deep;
    pos[u]=dfs_clock;
    par[u]=pa;
    int i;
    for(i=head[u];i;i=nxt[i]){
        int v=vv[i];
        if(v!=pa){
            dfs(v,u,deep+1);
            phi[++dfs_clock]=u;d[dfs_clock]=deep;
        }
    }
}

int main()
{
    int i,j,n,q;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    e=1;dfs_clock=0;
    for(i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);add(b,a);
    }
    dfs(1,-1,0);
    tree.build(1,1,dfs_clock);
    int k,u,v,cnt;
    node res;
    while(q--){
        scanf("%d%d%d",&k,&u,&v);
        if(k==0){
            a[u]=v;continue;
        }
        cnt=0;
        int x=min(pos[u],pos[v]),y=max(pos[u],pos[v]);
        res=tree.ask(x,y,1,1,dfs_clock);
        while(u!=res.u){
            ans[++cnt]=a[u];u=par[u];
        }
        while(v!=res.u){
            ans[++cnt]=a[v];v=par[v];
        }
        ans[++cnt]=a[res.u];
        if(cnt<k)
            printf("invalid request!\n");
        else {
            sort(ans+1,ans+cnt+1);
            printf("%d\n",ans[cnt-k+1]);
        }
    }
    return 0;
}
