/****************
*PID:poj1014
*Auth:Jonariguez
*****************
DP
dp[i+1][j]:用前i种数加和得到j时第i种数最多能剩余多少个（得不到就等于-1)
(Ai:值  Mi：个数
           Mi             dp[i][j]>=0             (用前i-1个已经能加和得到j了，那么第i个数就全剩下了)
dp[i+1][j]=-1             j<Ai || dp[i+1][j-Ai]<=0  (j<Ai或者用前i个加和到j-Ai都不够或刚好用完Ai，那么就得不到j
           dp[i+1][j-Ai]-1
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int a[7],dp[8][20002*6];
//int dp[20002*6];

int main()
{
    int i,j,sum,n=6,kcase=1;
    while(scanf("%d",&a[1])){
        sum=a[1];
        for(i=2;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i]*i;
        }
        if(sum==0) break;
        printf("Collection #%d:\n",kcase++);
        if(sum&1){
            printf("Can't be divided.\n\n");continue;
        }
        memset(dp,-1,sizeof(dp));
    /*    dp[0]=0;
        for(i=1;i<=n;i++){
            for(j=0;j<=sum/2;j++){
                if(dp[j]>=0)
                    dp[j]=a[i];
                else if(j<i || dp[j-i]<=0)
                    dp[j]=-1;
                else dp[j]=dp[j-i]-1;
            }
        }*/
    //    for(i=0;i<=n+1;i++) dp[i][0]=0;
        dp[1][0]=0;
        for(i=1;i<=n;i++){
            for(j=0;j<=sum/2;j++){
                if(dp[i][j]>=0)
                    dp[i+1][j]=a[i];
                else if(j<i || dp[i+1][j-i]<=0)
                    dp[i+1][j]=-1;
                else  dp[i+1][j]=dp[i+1][j-i]-1;    //这里把dp[i+1][j-i]写成了dp[i][j-i]，一直WA啊
            }
        }
      //  for(i=1;i<=7;i++)
      //      if(dp[i][sum/2]>=0) break;
        if(dp[7][sum/2]>=0)
            printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
    return 0;
}
