/****************
*PID:hdu2391
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

const int maxn=1000+5;
int dp[maxn][maxn],a[maxn][maxn];

int main()
{
    int i,j,n,m,T,kcase=1;
    sc(T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                sc(a[i][j]);
        dp[n][m]=a[n][m];
        for(i=n;i>=1;i--){
            for(j=m;j>=1;j--){
                if(i==n && j==m) continue;
                dp[i][j]=max(dp[i][j+1],max(dp[i+1][j],dp[i+1][j+1]))+a[i][j];
            }
        }
        printf("Scenario #%d:\n%d\n\n",kcase++,dp[1][1]);
    }
    return 0;
}



