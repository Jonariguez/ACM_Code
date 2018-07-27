/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define X first
#define Y second
#define PI acos(-1.0)
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
const int MOD=1e9+7;

vector<int> vec[maxn],con[maxn];

int c[maxn];
bool vis[maxn],a[maxn];

bool dfs(int u,int pa){
    vis[u]=1;
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        if(v==pa) continue;
        if(c[v] && c[v]==c[u]) return false;
        c[v]=3-c[u];
        if(!dfs(v,u)) return false;
    }
    return true;
}

int main()
{
    int i,j,n,m,x;
    scanf("%d%d",&n,&m);
    int k=max(n,m);
    for(i=1;i<=k;i++){
        vec[i].clear();
        con[i].clear();
    }
    for(i=1;i<=n;++i){
        int z;
        scanf("%d",&z);
        a[i]=z;
    }
    for(i=1;i<=m;i++){
        sc(x);
        int v;
        while(x--){
            scanf("%d",&v);
            vec[v].push_back(i);
        }
    }
    for(i=1;i<=n;i++){
        if(a[i]) continue;
        con[vec[i][0]].push_back(vec[i][1]);
        con[vec[i][1]].push_back(vec[i][0]);
    }
    memset(c,0,sizeof(c));
    memset(vis,0,sizeof(vis));
    for(i=1;i<=m;i++){
        if(vis[i]) continue;
        c[i]=1;
        if(!dfs(i,0)){
            printf("NO\n");return 0;
        }
    }
    for(i=1;i<=n;i++){
        if(a[i]==0) continue;
        int x=vec[i][0],y=vec[i][1];
        if(c[x]!=c[y]){
            puts("NO");return 0;
        }
    }
    puts("YES");
    return 0;
}


