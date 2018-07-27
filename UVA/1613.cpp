/****************
*PID:uva1613
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

const int maxn=10000+10;
int ans[maxn],deg[maxn],k;
vector<int> G[maxn];

void init(int n){
    memset(deg,0,sizeof(deg));
    memset(ans,0,sizeof(ans));
    for(int i=0;i<=n;i++)
        G[i].clear();
}

int dfs(int u,int pa){
    int i,j,t;
    for(i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==pa) continue;
        if(ans[v]) continue;
        for(j=1;j<=k;j++){
            for(t=0;t<G[v].size();t++)
                if(ans[G[v][t]]==j) break;
            if(t>=G[v].size()) break;
        }
        ans[v]=j;
        dfs(v,u);
    }
}

int main()
{
    int i,j,n,m,kcase=0;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(kcase++) puts("");
        init(n);
        k=0;
        rep(i,1,m){
            int a,b;
            sc(a);sc(b);
            G[a].push_back(b);
            G[b].push_back(a);
            deg[a]++;deg[b]++;
            k=max(k,deg[a]);k=max(k,deg[b]);
        }
        if(k%2==0) k++;
        printf("%d\n",k);
        ans[1]=1;
        dfs(1,-1);
        for(i=1;i<=n;i++)
            pfn(ans[i]);
    }
    return 0;
}


