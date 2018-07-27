/****************
*PID:467c div2
*Auth:Jonariguez
*****************
dp[i][j]:前i个数分成k个的最大值
答案为dp[n][k]
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=5000+5;
LL dp[maxn][maxn],sum[maxn],a[maxn];

int main()
{
    int i,j,n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        sum[0]=0;
        for(i=1;i<=n;++i){
            scanf("%I64d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++){
            for(j=1;j<=k;j++){
               // if(k*m>i) break;
                dp[i][j]=dp[i-1][j];
                if(i>=m)
                    dp[i][j]=max(dp[i][j],dp[i-m][j-1]+sum[i]-sum[i-m]);
            }
        }
        printf("%I64d\n",dp[n][k]);
    }
    return 0;
}
