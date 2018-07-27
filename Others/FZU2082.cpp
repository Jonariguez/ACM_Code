/****************
*PID:fzu2082
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=50000+10;
int head[maxn],vv[maxn*2],nxt[maxn*2],wei[maxn*2],in[maxn],out[maxn],dfs_clock,e;
int id[maxn],dp[maxn][30],deep[maxn],par[maxn];
LL dis[maxn];

void Init(){
    memset(head,0,sizeof(head));
    e=1;dfs_clock=0;
}

void add(int u,int v,int w){
    vv[e]=v;wei[e]=w;nxt[e]=head[u];head[u]=e++;
}

struct pp{
    int a,b,w;
}s[maxn];

void dfs(int u,int pa,int w){
    in[u]=++dfs_clock;
    deep[u]=deep[pa]+1;
    par[u]=pa;
    dis[u]=dis[pa]+w;
    id[dfs_clock]=u;
    for(int i=head[u];i;i=nxt[i]){
        int v=vv[i],w=wei[i];
        if(v==pa) continue;
        dfs(v,u,w);
    }
    out[u]=dfs_clock;
}

typedef struct Segment{
    LL sum[maxn*4],add[maxn*4];
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
        sum[k]=0;add[k]=0;
        if(l==r){
            sum[k]=dis[id[l]];
            return ;
        }
        int m=(l+r)/2;
        build(lson);
        build(rson);
        pushUp(k);
    }
    void update(int a,int b,LL v,int k,int l,int r){
        if(a<=l && r<=b){
            add[k]+=v;sum[k]+=v*(r-l+1);
            return ;
        }
        int m=(l+r)/2;
        pushDown(k,l,r);
        if(a<=m)
            update(a,b,v,lson);
        if(b>m)
            update(a,b,v,rson);
        pushUp(k);
    }
    LL ask(int p,int k,int l,int r){
        if(l==r)
            return sum[k];
        pushDown(k,l,r);
        int m=(l+r)/2;
        LL res=0;
        if(p<=m)
            res+=ask(p,lson);
        else
            res+=ask(p,rson);
        pushUp(k);
        return res;
    }
}Tree;

Tree tree;

void Init_rmq(int n){
    memset(dp,0,sizeof(dp));
    int i,j;
    for(i=1;i<=n;i++)
        dp[i][0]=par[i];
    for(j=1;(1<<j)<n;j++){
        for(i=1;i<=n;i++){
            if(dp[i][j-1]==0) continue;
            int fa=dp[i][j-1];
            dp[i][j]=dp[fa][j-1];
        }
    }
}

int LCA(int u,int v){
    int temp,log,i;
    if(deep[u]<deep[v]) swap(u,v);
    for(log=1;(1<<log)<=deep[u];log++);
    log--;
    for(i=log;i>=0;i--){
        if(deep[u]-(1<<i)>=deep[v])
            u=dp[u][i];
    }
    if(u==v) return u;
    for(i=log;i>=0;i--){
        if(dp[u][i]!=-1 && dp[u][i]!=dp[v][i]){
            u=dp[u][i];v=dp[v][i];
        }
    }
    return par[u];
}

int main()
{
    int i,j,n,m,T;
    while(scanf("%d%d",&n,&m)!=EOF){
        Init();
        int u,v,w;
        for(i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            s[i].a=u;s[i].b=v;s[i].w=w;
            add(u,v,w);
            add(v,u,w);
        }
        dis[0]=0;
        deep[0]=0;
        dfs(1,0,0LL);
        tree.build(1,1,n);
        Init_rmq(n);
        while(m--){
            int o;
            sc(o);sc(u);sc(v);
            if(o==0){
                int a=s[u].a,b=s[u].b;
                if(deep[a]<deep[b])
                    swap(a,b);
                tree.update(in[a],out[a],(LL)v-s[u].w,1,1,n);
                s[u].w=v;
            }else {
                int lca=LCA(u,v);
                LL la=tree.ask(in[u],1,1,n);
                LL lb=tree.ask(in[v],1,1,n);
                LL lc=tree.ask(in[lca],1,1,n);
                printf("%I64d\n",la+lb-2*lc);
            }
        }
    }
    return 0;
}



