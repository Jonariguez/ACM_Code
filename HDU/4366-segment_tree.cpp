/****************
*PID:hdu4366
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
struct staff{
    int abi,loy,id;
}s[maxn];
int start[maxn],End[maxn],res[maxn],dfs_clock,n;

vector<int> son[maxn];

void Init(){
    for(int i=0;i<=n;i++)
        son[i].clear();
    dfs_clock=0;
}

void add(int u,int v){
    son[u].push_back(v);
}

int cmp(const staff &x,const staff &y){
    if(x.abi==y.abi)
        return x.id<y.id;
    return x.abi>y.abi;
}

void dfs(int u){
    start[u]=++dfs_clock;
    for(int i=0;i<son[u].size();i++)
        dfs(son[u][i]);
    End[u]=dfs_clock;
}

struct node{
    int loy,id;
    bool operator < (const node &r) const {
        return loy<r.loy;
    }
};

struct Segment{
    node sum[maxn*4];
    void pushUp(int k){
        sum[k]=max(sum[k*2],sum[k*2+1]);
    }
    void build(int k,int l,int r){
        sum[k].loy=-1;
        sum[k].id=0;
        if(l==r) return ;
        int m=(l+r)/2;
        build(lson);
        build(rson);
    }
    void Insert(int p,int v,int id,int k,int l,int r){
        if(l==r){
            sum[k].loy=v;sum[k].id=id;
            return ;
        }
        int m=(l+r)/2;
        if(p<=m)
            Insert(p,v,id,lson);
        else Insert(p,v,id,rson);
        pushUp(k);
    }
    node ask(int a,int b,int k,int l,int r){
        if(a<=l && r<=b)
            return sum[k];
        int m=(l+r)/2;
        node res;
        res.loy=-1;res.id=0;
        if(a<=m)
            res=max(res,ask(a,b,lson));
        if(b>m)
            res=max(res,ask(a,b,rson));
        return res;
    }
}tree;


int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        int m;
        scanf("%d%d",&n,&m);
        Init();
        for(i=2;i<=n;i++){
            int a;
            scanf("%d%d%d",&a,&s[i].loy,&s[i].abi);
            s[i].id=i;
            a++;
            add(a,i);
        }
        dfs(1);
        sort(s+2,s+n+1,cmp);
        memset(res,-1,sizeof(res));
        tree.build(1,1,n);
        for(i=2;i<=n;i++){
            int l=start[s[i].id],r=End[s[i].id];
            node ans=tree.ask(l,r,1,1,n);
            res[s[i].id]=ans.id-1;
            tree.Insert(l,s[i].loy,s[i].id,1,1,n);
        }
        res[1]=tree.ask(1,n,1,1,n).id-1;
        while(m--){
            int x;
            sc(x);
            x++;
            printf("%d\n",res[x]);
        }
    }
    return 0;
}




