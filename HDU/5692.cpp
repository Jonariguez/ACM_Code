#pragma comment(linker, "/STACK:1024000000,1024000000")
/****************
*PID:hdu5692
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

const int maxn=200000+10;
const LL INF=1e17;
int in[maxn],out[maxn],dfs_clock;
LL val[maxn],dis[maxn];
vector<int> con[maxn];

void Init(int n){
    for(int i=0;i<=n;i++)
        con[i].clear();
}

typedef struct Segment{
    LL sum[maxn*4],add[maxn*4];
    void pushUp(int k){
        sum[k]=max(sum[k*2],sum[k*2+1]);
    }
    void pushDown(int k,int l,int r){
        if(add[k]){
            int lc=k*2,rc=k*2+1,m=(l+r)/2;
            add[lc]+=add[k];add[rc]+=add[k];
            sum[lc]+=add[k];
            sum[rc]+=add[k];
            add[k]=0;
        }
    }
    void build(int k,int l,int r){
        sum[k]=0;add[k]=0;
        if(l==r){
            sum[k]=dis[l];
            return ;
        }
        int m=(l+r)/2;
        build(lson);
        build(rson);
        pushUp(k);
    }
    void update(int a,int b,LL v,int k,int l,int r){
        if(a<=l && r<=b){
            add[k]+=v;sum[k]+=v;
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
    LL ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        pushDown(k,l,r);
        int m=(l+r)/2;
        LL res=-INF;
        if(a<=m)
            res=max(res,ask(a,b,lson));
        if(b>m)
            res=max(res,ask(a,b,rson));
        pushUp(k);
        return res;
    }
}Tree;

Tree tree;

void dfs(int u,int pa,LL w){
    in[u]=++dfs_clock;
    dis[dfs_clock]=w;
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        if(v==pa) continue;
        dfs(v,u,w+val[v]);
    }
    out[u]=dfs_clock;
}


int main()
{
    int i,j,m,n,T,kcase=1;
    sc(T);
    while(T--){
        sc(n);sc(m);
        Init(n);
        int x,y;
        for(i=1;i<n;i++){
            sc(x);sc(y);
            x++;y++;
            con[x].push_back(y);
            con[y].push_back(x);
        }
        for(i=1;i<=n;++i)
            scanf("%lld",&val[i]);
        dfs_clock=0;
        dis[0]=0;
        dfs(1,0,val[1]);
        tree.build(1,1,n);
        printf("Case #%d:\n",kcase++);
        while(m--){
            int o;
            LL v;
            sc(o);sc(x);x++;
            if(o==0){
                scanf("%lld",&v);
                tree.update(in[x],out[x],v-val[x],1,1,n);
                val[x]=v;
            }else
                printf("%lld\n",tree.ask(in[x],out[x],1,1,n));
        }
    }
    return 0;
}
