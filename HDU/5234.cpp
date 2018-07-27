/****************
*PID:hdu5234
*Auth:Jonariguez
*****************
dp[x][y][k]:从(x,y)开始走到(n,m)，最大量为k时，最多能吃多少。
答案为:dp[1][1][K]
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

const int maxn=100+5;
int dp[maxn][maxn][maxn],w[maxn][maxn];

int main()
{
    int i,j,k,n,m,K;
    while(scanf("%d%d%d",&n,&m,&K)!=EOF){
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++) scanf("%d",&w[i][j]);
        memset(dp,0,sizeof(dp));
        for(i=n;i>=1;i--){
            for(j=m;j>=1;j--){
                for(k=0;k<=K;k++){
                    if(k>=w[i][j]) dp[i][j][k]=max(dp[i+1][j][k-w[i][j]],dp[i][j+1][k-w[i][j]])+w[i][j];
                    dp[i][j][k]=max(dp[i][j][k],max(dp[i+1][j][k],dp[i][j+1][k]));
                }
            }
        }
        printf("%d\n",dp[1][1][K]);
    }
    return 0;
}



