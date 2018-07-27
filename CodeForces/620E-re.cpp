/****************
*PID:620e edu6
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

const int maxn=400000+10;
int head[maxn],nxt[maxn*2],vv[maxn*2],in[maxn],out[maxn],e,dfs_clock;
int c[maxn],id[maxn];

void Init(){
    memset(head,0,sizeof(head));
    e=1;dfs_clock=0;
}

void add(int u,int v){
    vv[e]=v;nxt[e]=head[u];head[u]=e++;
}

void dfs(int u,int pa){
    in[u]=++dfs_clock;
    id[dfs_clock]=u;
    for(int i=head[u];i;i=nxt[i]){
        int v=vv[i];
        if(v==pa) continue;
        dfs(v,u);
    }
    out[u]=dfs_clock;
}

typedef struct Segment{
    LL sum[maxn*4],set[maxn*4];
    void pushUp(int k){
        sum[k]=sum[k*2]|sum[k*2+1];
    }
    void pushDown(int k){
        if(set[k]>=0){
            int lc=k*2,rc=k*2+1;
            set[lc]=set[rc]=set[k];
            sum[lc]=(1LL<<set[k]);
            sum[rc]=(1LL<<set[k]);
            set[k]=-1;
        }
    }
    void build(int k,int l,int r){
        sum[k]=0;set[k]=-1;
        if(l==r){
            sum[k]=(1LL<<c[id[l]]);
            return ;
        }
        int m=(l+r)/2;
        build(lson);
        build(rson);
        pushUp(k);
    }
    void Set(int a,int b,int v,int k,int l,int r){
        if(a<=l && r<=b){
            set[k]=(LL)v;sum[k]=(1LL<<v);
            return ;
        }
        pushDown(k);
        int m=(l+r)/2;
        if(a<=m)
            Set(a,b,v,lson);
        if(b>m)
            Set(a,b,v,rson);
        pushUp(k);
    }
    LL ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        pushDown(k);
        int m=(l+r)/2;
        LL res=0;
        if(a<=m)
            res|=ask(a,b,lson);
        if(b>m)
            res|=ask(a,b,rson);
        pushUp(k);
        return res;
    }
}Tree;

Tree tree;

int cal(LL n){
    if(n==0) return 0;
    return cal(n/2)+(n&1);
}

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        Init();
        for(i=1;i<=n;i++)
            sc(c[i]);
        for(i=1;i<n;i++){
            int a,b;
            sc(a);sc(b);
            add(a,b);add(b,a);
        }
        dfs(1,0);
        tree.build(1,1,n);
        while(m--){
            int o,x,y;
            scanf("%d%d",&o,&x);
            if(o==1){
                sc(y);
                tree.Set(in[x],out[x],y,1,1,n);
            }else {
                LL ans=tree.ask(in[x],out[x],1,1,n);
                printf("%d\n",cal(ans));
            }
        }
    }
    return 0;
}

