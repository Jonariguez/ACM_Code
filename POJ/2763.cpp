/****************
*PID:poj2763
*Auth:Jonariguez
*****************
对于Message A，求两点的距离还是先求LCA，然后求距离。
对于Message B，修改边权，那么位于该边下面的子树中的
节点都要修改其dis值(该节点到树根1的距离),这可以借助
dfs序，利用线段进行区间修改，单点查询。
注意：d[a]并不代表节点a的深度。。。。。！！！！
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int head[maxn],wei[maxn*2],vv[maxn*2],nxt[maxn*2],e,dfs_clock,dfsn;
int dis[maxn],d[maxn*2],phi[maxn*2],pos[maxn],start[maxn],end[maxn],dp[maxn*2][31];

struct Edge{
    int a,b,w;
}s[maxn];

void Init(){
    memset(head,0,sizeof(head));
    e=1;dfs_clock=0;dfsn=0;
}

void add(int u,int v,int w){
    wei[e]=w;vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

void dfs(int u,int pa,int deep,int dist){
    pos[u]=++dfs_clock;
    phi[dfs_clock]=u;
    d[dfs_clock]=deep;dis[u]=dist;
    start[u]=++dfsn;
    for(int i=head[u];i;i=nxt[i]){
        int v=vv[i],w=wei[i];
        if(v==pa) continue;
        dfs(v,u,deep+1,dist+w);
        phi[++dfs_clock]=u;
        d[dfs_clock]=deep;
    }
    end[u]=dfsn;
}

struct Segment{
    int sum[maxn*8],add[maxn*8];
    void pushUp(int k){
        sum[k]=sum[k*2]+sum[k*2+1];
    }
    void pushDown(int k,int l,int r){
        if(add[k]){
            int lc=k*2,rc=k*2+1,m=(l+r)/2;
            add[lc]+=add[k];add[rc]+=add[k];
            sum[lc]+=add[k]*(m-l+1);
            sum[rc]+=add[k]*(r-m);
            add[k]=0;
        }
    }
    void build(int k,int l,int r){
        add[k]=sum[k]=0;
        if(l==r) return ;
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
       // pushUp(k);
    }
    void update(int a,int b,int v,int k,int l,int r){
        if(a<=l && r<=b){
            add[k]+=v;sum[k]+=v*(r-l+1);return ;
        }
        pushDown(k,l,r);
        int m=(l+r)/2;
        if(a<=m)
            update(a,b,v,k*2,l,m);
        if(b>m)
            update(a,b,v,k*2+1,m+1,r);
        pushUp(k);
    }
    int ask(int p,int k,int l,int r){
        if(l==r)
            return sum[k];
        pushDown(k,l,r);
        int m=(l+r)/2,res=0;
        if(p<=m)
            res=ask(p,k*2,l,m);
        else res=ask(p,k*2+1,m+1,r);
        pushUp(k);
        return res;
    }
}tree;

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

int RMQ(int x,int y){
    int k=(int)(log((double)(y-x+1))/log(2.0));
    int a=dp[x][k],b=dp[y-(1<<k)+1][k];
    if(d[a]<d[b]) return a;
    return b;
}

int LCA(int u,int v){
    u=pos[u];v=pos[v];
    if(u>v) swap(u,v);
    return phi[RMQ(u,v)];
}

int main()
{
    int i,j,n,q,S;
    while(scanf("%d%d%d",&n,&q,&S)!=EOF){
        Init();
        for(i=1;i<n;i++){
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].w);
            add(s[i].a,s[i].b,s[i].w);
            add(s[i].b,s[i].a,s[i].w);
        }
        dfs(1,-1,1,0);
        ST(dfs_clock);
        tree.build(1,1,dfsn);
        for(i=1;i<=n;i++){
            tree.update(start[i],start[i],dis[i],1,1,dfsn);
          //  tree.update(end[i],end[i],dis[i],1,1,dfsn);
        }
        int o,u,w;
        while(q--){
            scanf("%d",&o);
            if(o==0){
                scanf("%d",&u);
                int lca=LCA(u,S);
                int du=tree.ask(start[u],1,1,dfsn);
                int dS=tree.ask(start[S],1,1,dfsn);
                int dA=tree.ask(start[lca],1,1,dfsn);
                printf("%d\n",du+dS-2*dA);
                S=u;
            }else {
                scanf("%d%d",&u,&w);
                int a=s[u].a,b=s[u].b;
                if(start[a]<start[b])
                    swap(a,b);
               // printf("a=%d\n",a);
                tree.update(start[a],end[a],w-s[u].w,1,1,dfsn);
                s[u].w=w;   //s[u],非s[i]
            }
        }
    }
    return 0;
}
