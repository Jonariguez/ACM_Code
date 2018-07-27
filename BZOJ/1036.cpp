/****************
*PID:bzoj1036
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

const int maxn=30000+10;
int head[maxn],vv[maxn*2],nxt[maxn*2],e,dfs_clock;
int par[maxn],top[maxn],son[maxn],Size[maxn],start[maxn],End[maxn],mp[maxn],val[maxn],deep[maxn];

void Init(){
    memset(head,0,sizeof(head));
    memset(par,0,sizeof(par));
    memset(top,0,sizeof(top));
    e=1;dfs_clock=0;
}

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

void dfs(int u,int pa){
    Size[u]=1;son[u]=0;par[u]=pa;
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
    start[u]=++dfs_clock;
    mp[u]=dfs_clock;
    top[u]=tp;
    if(son[u]) dfs2(son[u],u,tp);
    for(int i=head[u];i;i=nxt[i]){
        int v=vv[i];
        if(v==pa) continue;
        if(son[u]==v) continue;
        dfs2(v,u,v);
    }
    End[u]=dfs_clock;
}

typedef struct Segment{
    int sum[maxn*4],maxv[maxn*4];
    void pushUp(int k){
        sum[k]=sum[k*2]+sum[k*2+1];
        maxv[k]=max(maxv[k*2],maxv[k*2+1]);
    }
    void build(int k,int l,int r){
        sum[k]=0;maxv[k]=-2000000;
        if(l==r){
            return ;
        }
        int m=(l+r)/2;
        build(lson);
        build(rson);
    }
    void update(int p,int v,int k,int l,int r){
        if(l==r){
            sum[k]=maxv[k]=v;return ;
        }
        int m=(l+r)/2;
        if(p<=m)
            update(p,v,lson);
        else update(p,v,rson);
        pushUp(k);
    }
    int ask_sum(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        int m=(l+r)/2,res=0;
        if(a<=m)
            res+=ask_sum(a,b,lson);
        if(b>m)
            res+=ask_sum(a,b,rson);
        return res;
    }
    int ask_max(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return maxv[k];
        int m=(l+r)/2,res=-1000000;
        if(a<=m)
            res=max(res,ask_max(a,b,lson));
        if(b>m)
            res=max(res,ask_max(a,b,rson));
        return res;
    }
}Tree;

Tree tree;

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        Init();
        for(i=1;i<n;i++){
            int a,b;
            sc(a);sc(b);
            add(a,b);add(b,a);
        }
        deep[1]=1;
        dfs(1,0);
        dfs2(1,0,1);
        tree.build(1,1,n);
        for(i=1;i<=n;i++){
            sc(val[i]);
            tree.update(mp[i],val[i],1,1,n);
        }
        scanf("%d",&m);
        char str[11];
        while(m--){
            int x,y;
            scanf("%s%d%d",str,&x,&y);
            if(str[0]=='C')
                tree.update(mp[x],y,1,1,n);
            else if(str[1]=='S'){
                int res=0,tx,ty;
                while((tx=top[x])!=(ty=top[y])){
                    if(deep[tx]<deep[ty]) swap(x,y);
                    res+=(res,tree.ask_sum(mp[top[x]],mp[x],1,1,n));
                    x=par[top[x]];
                }
                if(deep[x]>deep[y]) swap(x,y);
                res+=(res,tree.ask_sum(mp[x],mp[y],1,1,n));
                printf("%d\n",res);
            }else {
                int res=-19999999,fx,fy;
                while((fx=top[x])!=(fy=top[y])){
                    if(deep[top[x]]<deep[top[y]]) swap(x,y);
                    res=max(res,tree.ask_max(mp[top[x]],mp[x],1,1,n));
                    x=par[top[x]];
                }
                if(deep[x]>deep[y]) swap(x,y);
                res=max(res,tree.ask_max(mp[x],mp[y],1,1,n));
                printf("%d\n",res);
            }
        }
    }
    return 0;
}


