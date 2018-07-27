/****************
*PID:lightoj 1422
*Auth:Jonariguez
*****************
Çø¼ädp
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

const int maxn=100+10;
const int INF=1e8;
int a[maxn],dp[maxn][maxn];

int main()
{
    int i,j,k,T,kcase=1,n;
    sc(T);
    while(T--){
        sc(n);
        for(i=1;i<=n;i++){
            sc(a[i]);
        }
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
            dp[i][i]=1;
        for(i=n-1;i>=1;i--){
            for(j=i+1;j<=n;j++){
                dp[i][j]=dp[i+1][j]+1;
                for(k=i+1;k<=j;k++){
                    if(a[i]==a[k])
                        dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k][j]);
                }
            }
        }
        printf("Case %d: %d\n",kcase++,dp[1][n]);
    }
    return 0;
}



