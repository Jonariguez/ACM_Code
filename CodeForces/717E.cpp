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

const int maxn=200000+10;
const int MOD=1e9+7;

vector<int> con[maxn],res;
int val[maxn],a[maxn],cnt[maxn];

void dfs2(int u,int pa){
    val[u]=a[u];
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        if(v==pa) continue;
        dfs2(v,u);
        val[u]+=val[v];
        if(val[v]) cnt[u]++;
    }
}

int f=0;

void dfs(int u,int pa){
    res.push_back(u);
    a[u]^=1;
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i];
        if(v==pa || val[v]==0) continue;
        dfs(v,u);
        res.push_back(u);
        a[u]^=1;
    }
    if(a[u]==1){
        res.push_back(pa);res.push_back(u);res.push_back(pa);a[u]^=1;
    }
}

int main()
{
    int i,j,n,m;
    scanf("%d",&n);
    int x;
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        if(x==-1)
            a[i]=val[i]=1;
    }
    int u,v;
    for(i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        con[u].push_back(v);
        con[v].push_back(u);
    }
    res.clear();
    a[1]^=1;
    dfs2(1,0);
    dfs(1,0);
    for(i=0;i<res.size();i++)
        printf("%d ",res[i]);
    puts("");
    return 0;
}


