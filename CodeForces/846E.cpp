/****************
*PID:
*Auth:Jonariguez
*****************
自底向上满足.
多了就送给父亲，少了就向父亲要
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("%d%d",&x,&y)
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

double a[maxn],b[maxn]; //可能会爆long long

struct node{
    int to,w;
};

vector<node> con[maxn];

void dfs(int u,int pa,int w){
    for(int i=0;i<con[u].size();i++){
        int v=con[u][i].to,w=con[u][i].w;
        dfs(v,u,w);
    }
    if(b[u]>=a[u]){
        b[pa]+=b[u]-a[u];b[u]=a[u];
    }else {
        b[pa]-=(a[u]-b[u])*w;b[u]=a[u];
    }
}

int main()
{
    int i,j,n,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%lf",&b[i]);
    for(i=1;i<=n;i++)
        scanf("%lf",&a[i]);
    for(i=2;i<=n;i++){
        int x,k;
        SS(x,k);
        con[x].push_back((node){i,k});
    }
    dfs(1,0,1);
    if(b[0]>=0)     //看根节点有没有向其父亲“借"
        puts("YES");
    else puts("NO");
    return 0;
}


