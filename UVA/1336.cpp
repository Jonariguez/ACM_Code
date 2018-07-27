/****************
*PID:uva1336
*Auth:Jonariguez
*****************
因为根据贪心原则，如果经过一个点不修复的话那是傻子，
所以已经修好的点肯定是连续的一段区间，并且会停留在区间的端点处，
那么这就是我们设计状态的依据：
dp[i][j][k]:将区间[i,j]修复好，且最终停留在k(k=0为i，k=1为j)处的min花费。
这题是计算“未来费用”的好题，因为我们dp过程是枚举的，无法衡量出每次枚举
的好坏，所以对于选中要修理的点，所以在总花费要加上修理该点的费用，还要
加上其余还没有修复的点在这段时间内增加的费用，这也要加到状态里（可以
理解为因为修理这个点而引起或者耽误的费用）
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

const int maxn=1000+10;
const double INF=100000000000;
LL sum[maxn];
double dp[maxn][maxn][2];
int vis[maxn][maxn][2],kcase=0;
int n,v,x;

struct pp{
    int x,c,d;
    bool operator < (const pp &r) const {
        return x<r.x;
    }
}s[maxn];

double dfs(int l,int r,int k){
    if(dp[l][r][k]>-1.0) return dp[l][r][k];
    if(l==r){
        double t=abs(x-s[l].x)*1.0/v;
        dp[l][r][k]=t*sum[n]+s[l].c;
       // vis[l][r][k]=kcase;
        return dp[l][r][k];
    }
    if(k==0){
        double L=dfs(l+1,r,0);
        double R=dfs(l+1,r,1);
        LL S=sum[l]+sum[n]-sum[r];
        double tl=(double)(s[l+1].x-s[l].x)/v;
        double tr=(double)(s[r].x-s[l].x)/v;
        dp[l][r][k]=min(L+tl*S,R+tr*S)+(double)s[l].c;
       // vis[l][r][k]=kcase;
        return dp[l][r][k];
    }else {
        double L=dfs(l,r-1,0);
        double R=dfs(l,r-1,1);
        LL S=sum[l-1]+sum[n]-sum[r-1];
        double tl=(double)(s[r].x-s[l].x)/v;
        double tr=(double)(s[r].x-s[r-1].x)/v;
        dp[l][r][k]=min(L+tl*S,R+tr*S)+(double)s[r].c;
     //   vis[l][r][k]=kcase;
        return dp[l][r][k];
    }
}

int main()
{
    int i,j;
    while(~scanf("%d%d%d",&n,&v,&x)){
        if(n+x+v==0) break;
        for(i=1;i<=n;i++)
            scanf("%d%d%d",&s[i].x,&s[i].c,&s[i].d);
        sort(s+1,s+n+1);
        sum[0]=0;
        for(i=1;i<=n;i++)
            sum[i]=sum[i-1]+s[i].d;
        memset(dp,-1.0,sizeof(dp));
        printf("%d\n",int(min(dfs(1,n,0),dfs(1,n,1))));
    }
    return 0;
}
