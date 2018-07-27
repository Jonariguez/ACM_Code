/****************
*PID:poj2631
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
int head[maxn],vv[maxn*2],nxt[maxn*2],wei[maxn*2],d[maxn],e;

void Init(){
    memset(head,0,sizeof(head));
    e=1;
}

void add(int u,int v,int w){
    vv[e]=v;wei[e]=w;nxt[e]=head[u];head[u]=e++;
}

void dfs(int u,int pa,int w){
    d[u]=d[pa]+w;
    for(int i=head[u];i;i=nxt[i]){
        int v=vv[i],ww=wei[i];
        if(v==pa) continue;
        dfs(v,u,ww);
    }
}

int main()
{
    int i,j,n=0;
    int u,v,w;
    Init();
    while(scanf("%d%d%d",&u,&v,&w)!=EOF){
        add(u,v,w);
        add(v,u,w);
        n=max(n,u);
        n=max(n,v);
       // if(n==5) break;
    }
    memset(d,0,sizeof(d));
    d[0]=0;
    dfs(1,0,0);
    v=-1;
    for(i=1;i<=n;i++)
        if(v==-1 || d[v]<d[i]) v=i;
    memset(d,0,sizeof(d));
    dfs(v,0,0);
    v=0;
    for(i=1;i<=n;i++)
        v=max(v,d[i]);
    pfn(v);
    return 0;
}




