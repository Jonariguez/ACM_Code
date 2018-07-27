/****************
*PID:uva10600
*Auth:Jonariguez
*****************
次小生成树
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

const int maxn=100+10;
int head[maxn],vv[maxn*2],wei[maxn*2],nxt[maxn*2],e;
int par[maxn],maxcost[maxn][maxn],vis[maxn*maxn];
vector<int> ver;

struct pp{
    int a,b,v;
}s[maxn*maxn];

int cmp(const pp &x,const pp &y){
    return x.v<y.v;
}

void Init(int n){
    for(int i=0;i<=n;i++) par[i]=i;
    memset(head,0,sizeof(head));
    memset(maxcost,0,sizeof(maxcost));
    memset(vis,0,sizeof(vis));
    ver.clear();
    e=1;
}

void add(int u,int v,int w){
    vv[e]=v;wei[e]=w;nxt[e]=head[u];head[u]=e++;
}

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

bool Union(int u,int v){
    if((u=find(u))==(v=find(v))) return false;
    par[u]=v;
    return true;
}

void dfs(int u,int pa,int W){
    int i,v,w;
    for(i=0;i<ver.size();i++){
        v=ver[i];
        maxcost[u][v]=maxcost[v][u]=max(maxcost[pa][v],W);
    }
    ver.push_back(u);
    for(i=head[u];i;i=nxt[i]){
        v=vv[i];w=wei[i];
        if(v==pa) continue;
        dfs(v,u,w);
    }
}

int main()
{
    int i,j,n,m,T;
    sc(T);
    while(T--){
        scanf("%d%d",&n,&m);
        Init(n);
        for(i=1;i<=m;i++)
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].v);
        sort(s+1,s+m+1,cmp);
        int cnt=0,res1=0,res2=0;
        for(i=1;i<=m;i++){
            if(Union(s[i].a,s[i].b)){
                add(s[i].a,s[i].b,s[i].v);add(s[i].b,s[i].a,s[i].v);
                res1+=s[i].v;
                vis[i]=1;
                if(++cnt==n-1) break;
            }
        }
        printf("%d ",res1);
        dfs(1,0,0);
        res2=1e9;
        for(i=1;i<=m;i++){
            if(vis[i]) continue;
            res2=min(res2,res1+s[i].v-maxcost[s[i].a][s[i].b]);
        }
        printf("%d\n",res2);
    }
    return 0;
}


