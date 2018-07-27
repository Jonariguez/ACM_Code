/****************
*PID:poj3237
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
int head[maxn],vv[maxn*2],nxt[maxn*2],wei[maxn*2],e,dfs_clock;
int Size[maxn],son[maxn],par[maxn],top[maxn],deep[maxn],mp[maxn],val[maxn],twei[maxn];

struct Edge{
    int a,b,c;
}s[maxn];

void Init(){
    memset(head,0,sizeof(head));
    memset(val,0,sizeof(val));
    e=1;dfs_clock=0;
}

void add(int u,int v,int w){
    vv[e]=v;wei[e]=w;nxt[e]=head[u];head[u]=e++;
}

void dfs(int u,int pa){
    par[u]=pa;Size[u]=1;son[u]=0;
    for(int i=head[u];i;i=nxt[i]){
        int v=vv[i],w=wei[i];
        if(v==pa) continue;
        deep[v]=deep[u]+1;
        dfs(v,u);
        Size[u]+=Size[v];
        if(Size[son[u]]<Size[v]){
            son[u]=v;twei[u]=w;
        }
    }
}

void dfs2(int u,int pa,int tp,int weight){
    mp[u]=++dfs_clock;
    top[u]=tp;
    val[u]=weight;
    if(son[u])
        dfs2(son[u],u,tp,twei[u]);
    for(int i=head[u];i;i=nxt[i]){
        int v=vv[i],w=wei[i];
        if(v==pa || v==son[u]) continue;
        dfs2(v,u,v,w);
    }
   // End[u]=dfs_clock;
}

typedef struct Segment{
    int maxv[maxn*4],set[maxn*4];
    void pushUp(int k){
        maxv[k]=max(maxv[k*2],maxv[k*2+1]);
    }
    void pushDown(int k){
        if(set[k]>=0){
            set[k*2]=set[k*2+1]=set[k];
            maxv[k*2]=maxv[k*2+1]=set[k];
            set[k]=-1;
        }
    }
    void build(int k,int l,int r){
        maxv[k]=set[k]=-1;
        if(l==r)
            return ;
        int m=(l+r)/2;
        build(lson);
        build(rson);
    }
    void update(int a,int b,int v,int k,int l,int r){
        if(a<=l && r<=b){
            set[k]=v;maxv[k]=v;
            return ;
        }
        pushDown(k);
        int m=(l+r)/2;
        if(a<=m)
            update(a,b,v,lson);
        if(b>m)
            update(a,b,v,rson);
        pushUp(k);
    }
    int ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return maxv[k];
        pushDown(k);
        int m=(l+r)/2,res=-2;
        if(a<=m)
            res=max(res,ask(a,b,lson));
        if(b>m)
            res=max(res,ask(a,b,rson));
        pushUp(k);
        return res;
    }
}Tree;

Tree tree;

int main()
{
    int i,j,T,n;
    sc(T);
    while(T--){
        while (1){
			char cc = getchar();
			if (cc == '\r' || cc == '\n') break;
		}
        sc(n);
        Init();
        for(i=1;i<n;i++){
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
            add(s[i].a,s[i].b,s[i].c);
            add(s[i].b,s[i].a,s[i].c);
        }
        deep[1]=1;
        dfs(1,0);
        dfs2(1,0,1,-1);
        tree.build(1,1,n);
        for(i=1;i<=n;i++)
            tree.update(mp[i],mp[i],val[i],1,1,n);
        char str[22];
        while(scanf("%s",str) && str[0]!='D'){
            int x,y;
            sc(x);sc(y);
            if(str[0]=='C'){
                int v=min(mp[s[x].a],mp[s[x].b]);
                tree.update(v+1,v+1,y,1,1,n);
            }else if(str[0]=='N'){
                int tx,ty;
                while((tx=top[x])!=(ty=top[y])){
                    if(deep[tx]<deep[ty]) swap(x,y);
                    tree.update(mp[top[x]],mp[x],0,1,1,n);
                    x=par[top[x]];
                }
                if(deep[x]>deep[y])
                    swap(x,y);
                if(x!=y)
                    tree.update(mp[x]+1,mp[y],0,1,1,n);
            }else {
                int res=-111,tx,ty;
                while((tx=top[x])!=(ty=top[y])){
                    if(deep[tx]<deep[ty]) swap(x,y);
                    res=max(res,tree.ask(mp[top[x]],mp[x],1,1,n));
                    x=par[top[x]];
                }
              //  printf("mx=%d my=%d\n",deep[x],deep[y]);
                if(deep[x]>deep[y])
                    swap(x,y);
                if(x!=y)
                    res=max(res,tree.ask(mp[x]+1,mp[y],1,1,n));
                pfn(res);
            }
        }
    }
    return 0;
}


