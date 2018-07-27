/****************
*PID:bzoj4034
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

const int maxn=100000+10;
int head[maxn],vv[maxn*2],nxt[maxn*2],start[maxn],End[maxn],e,dfs_clock;
int par[maxn],top[maxn],Size[maxn],son[maxn],deep[maxn],mp[maxn],val[maxn];

void Init(){
    memset(head,0,sizeof(head));
    e=1;dfs_clock=0;
}

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

void dfs(int u,int pa){
    Size[u]=1;son[u]=0;
    par[u]=pa;
    for(int i=head[u];i;i=nxt[i]){
        int v=vv[i];
        if(v==pa) continue;
        deep[v]=deep[u]+1;
        dfs(v,u);
        Size[u]+=Size[v];
        if(Size[son[u]]<Size[v])
            son[u]=v;
    }
}

void dfs2(int u,int pa,int tp){
    start[u]=mp[u]=++dfs_clock;
    top[u]=tp;
    if(son[u])
        dfs2(son[u],u,tp);
    for(int i=head[u];i;i=nxt[i]){
        int v=vv[i];
        if(v==pa || son[u]==v) continue;
        dfs2(v,u,v);
    }
    End[u]=dfs_clock;
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
        if(l==r)
            return ;
        int m=(l+r)/2;
        build(lson);
        build(rson);
    }
    void Add(int a,int b,int v,int k,int l,int r){
        if(a<=l && r<=b){
            add[k]+=v;sum[k]+=(LL)v*(r-l+1);
            return ;
        }
        pushDown(k,l,r);
        int m=(l+r)/2;
        if(a<=m)
            Add(a,b,v,lson);
        if(b>m)
            Add(a,b,v,rson);
        pushUp(k);
    }
    LL ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        pushDown(k,l,r);
        int m=(l+r)/2;
        LL res=0;
        if(a<=m)
            res+=ask(a,b,lson);
        if(b>m)
            res+=ask(a,b,rson);
        pushUp(k);
        return res;
    }
}Tree;

Tree tree;

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        Init();
        for(i=1;i<=n;i++)
            sc(val[i]);
        for(i=1;i<n;i++){
            int a,b;
            sc(a);sc(b);
            add(a,b);add(b,a);
        }
        deep[1]=1;
        dfs(1,0);
        dfs2(1,0,1);
        for(i=1;i<=n;i++)
            tree.Add(mp[i],mp[i],val[i],1,1,n);
        while(m--){
            int o,x,y;
            scanf("%d",&o);
            if(o==1){
                scanf("%d%d",&x,&y);
                tree.Add(mp[x],mp[x],y,1,1,n);
            }else if(o==2){
                scanf("%d%d",&x,&y);
                tree.Add(start[x],End[x],y,1,1,n);
            }else {
                scanf("%d",&x);
                y=1;
                LL res=0;
                int tx,ty;
                while((tx=top[x])!=(ty=top[y])){
                    if(deep[tx]<deep[ty]) swap(x,y);
                    res+=tree.ask(mp[tx],mp[x],1,1,n);
                    x=par[tx];
                }
                if(deep[x]>deep[y])
                    swap(x,y);
                res+=tree.ask(mp[x],mp[y],1,1,n);
                printf("%lld\n",res);
            }
        }
    }
    return 0;
}





