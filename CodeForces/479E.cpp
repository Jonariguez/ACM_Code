/****************
*PID:479e div2
*Auth:Jonariguez
*****************
dp[i][j]:表示第i步到大j楼层的方案数
找到对于j楼层，第i-1步时能转移到j楼层的楼层，
因为是连续的，所以可以用sum前缀和来求。
O(nk)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=5000+10;
const int mod=1e9+7;

LL dp[2][maxn],sum[maxn];

int main()
{
    LL i,j,n,m,k,a,b;
    while(scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&k)!=EOF){
        memset(dp,0,sizeof(dp));
        sum[0]=0;
        dp[0][a]=1;
        for(i=1;i<=n;i++)
            sum[i]=(sum[i-1]+dp[0][i])%mod;
        int d=0,l,r;
        for(i=1;i<=k;i++){
            memset(dp[d^1],0,sizeof(dp[d^1]));
            for(j=1;j<=n;j++){
                if(j==b) continue;
                if(j<b){
                    l=1;r=j+(b-j-1)/2;//printf("r=%d\n",r);
                }else {
                    l=j-(j-b-1)/2;r=n;
                }
                dp[d^1][j]+=sum[r]-sum[l-1]-dp[d][j];
                if(dp[d^1][j]>=mod)
                    dp[d^1][j]%=mod;
            }
            sum[0]=0;
            for(j=1;j<=n;j++) sum[j]=(sum[j-1]+dp[d^1][j])%mod;
            d^=1;
          //  for(j=1;j<=n;j++)
          //      printf("%d ",dp[d][i]);
         //   puts("");
        }
        LL res=0;
        for(i=1;i<=n;i++)
            if(j!=b) res=(res+dp[d][i])%mod;
        if(res<0) res+=mod;
        printf("%I64d\n",res);
    }
    return 0;
}
