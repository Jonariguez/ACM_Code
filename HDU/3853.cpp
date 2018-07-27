/****************
*PID:hdu3853
*Auth:Jonariguez
*****************
dp[i][j]:从(i,j)出发到(n,m)的能量期望消耗，
dp[i][j]=dp[i+1][j]*down[i][j]+dp[i][j+1]*right[i][j]+dp[i][j]*stay[i][j]+2;
整理得到：dp[i][j]=(dp[i+1][j]*down[i][j]+dp[i][j+1]*Right[i][j]+2)/(1-stay[i][j]);
题目虽说了答案保证是1000000以内，但是允许出现stay[i][j]==1的情况，
这时只需要不走(i,j)这个格子就行了
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
#define eps 1e-8
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=1000+3;
double dp[maxn][maxn];
double stay[maxn][maxn],Right[maxn][maxn],down[maxn][maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%lf%lf%lf",&stay[i][j],&Right[i][j],&down[i][j]);
        memset(dp,0,sizeof(dp));
        dp[n][m]=0;
        for(i=n;i>=1;i--){
            for(j=m;j>=1;j--){
                if(i==n && j==m) continue;
               // dp[i][j]=dp[i+1][j]*down[i][j]+dp[i][j+1]*right[i][j]+dp[i][j]*stay[i][j]+2;
                if(fabs(1-stay[i][j])<eps){
                    dp[i][j]=0;continue;
                }
                dp[i][j]=(dp[i+1][j]*down[i][j]+dp[i][j+1]*Right[i][j]+2)/(1-stay[i][j]);
            }
        }
        printf("%.3f\n",dp[1][1]);
    }
    return 0;
}


