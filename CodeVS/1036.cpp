/****************
*PID:cdvs1036
*Auth:Jonariguez
*****************
对于m个城镇，只需按顺序求相邻两个的最近距离就行了
LCA
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=30000+5;
int head[maxn],vv[maxn*2],nxt[maxn*2],phi[maxn*2],d[maxn*2],pos[maxn],dis[maxn],e,dfs_clock;

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

struct segment{
    int sum[maxn*8];
    void pushUp(int k){
        sum[k]=min(sum[k*2],sum[k*2+1]);
    }
    void build(int k,int l,int r){
        if(l==r){
            sum[k]=d[l];
            return ;
        }
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
        pushUp(k);
    }
    int ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        int m=(l+r)/2,res=maxn;
        if(a<=m)
            res=min(res,ask(a,b,k*2,l,m));
        if(b>m)
            res=min(res,ask(a,b,k*2+1,m+1,r));
        return res;
    }
}tree;

void dfs(int u,int pa,int deep){
    phi[++dfs_clock]=u;d[dfs_clock]=deep;
    pos[u]=dfs_clock;dis[u]=deep;
    int i;
    for(i=head[u];i;i=nxt[i]){
        int v=vv[i];
        if(v!=pa){
            dfs(v,u,deep+1);
            phi[++dfs_clock]=u;
            d[dfs_clock]=deep;
        }
    }
}

int main()
{
    int i,j,n,m;
    scanf("%d",&n);
    memset(head,0,sizeof(head));
    memset(dis,0,sizeof(dis));
    e=1;dfs_clock=0;
    for(i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    dfs(1,-1,0);
    tree.build(1,1,dfs_clock);
    int now=1,u;
    LL res=0;
    scanf("%d",&m);
    while(m--){
        scanf("%d",&u);
        int x=min(pos[u],pos[now]),y=max(pos[u],pos[now]);
        int t=tree.ask(x,y,1,1,dfs_clock);
      //  printf("t=%d\n",t);
        res+=dis[u]+dis[now]-2*t;
      //  printf("res=%d\n",res);
        now=u;
    }
    printf("%lld\n",res);
    return 0;
}
