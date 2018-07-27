/****************
*PID:hdu5653
*Auth:Jonariguez
*****************
事实证明Log2太慢，需要预处理。
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

const int maxn=2000+10;
const double INF=1000000;
int vis[maxn][maxn],p[maxn],sum[maxn];
double dp[maxn][maxn],Log2[maxn];
double DP(int x,int y){
    if(x>=y) return 0;
    if(vis[x][y]) return dp[x][y];
    vis[x][y]=1;
    double &ans=dp[x][y];
    ans=0;
    if(sum[y]-sum[x-1]==1)
        return ans=Log2[y-x+1];
    int cnt=0,i=x;
    while(p[i]==0) i++;
    if(i>y) return ans=-INF;
    i++;
    for(;i<=y;i++){
        ans=max(ans,Log2[i-x]+DP(i,y));
        if(p[i]) break;
    }
    i=y;
    while(p[i]==0) i--;
    i--;
    for(;i>=x;i--){
        ans=max(ans,Log2[y-i]+DP(x,i));
        if(p[i]) break;
    }
    return ans;
}

int main()
{
    int i,j,n,T;
    for(i=1;i<=2001;i++)
        Log2[i]=log2(i);
    scanf("%d",&T);
    while(T--){
        int m;
        sc(n);sc(m);
        memset(vis,0,sizeof(vis));
        memset(p,0,sizeof(p));
        for(i=1;i<=m;i++){
            int x;
            sc(x);x++;
            p[x]=1;
        }
        sum[0]=0;
        for(i=1;i<=2001;i++)
            sum[i]=sum[i-1]+p[i];
        double res=DP(1,n);
        printf("%I64d\n",(LL)floor(1000000.0*res));
    }
    return 0;
}
