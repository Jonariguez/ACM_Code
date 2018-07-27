/****************
*PID:
*Auth:Jonariguez
*****************
dp[i][k][j]表示：前i个数字中，第i个数字选取策略为k，且余数为j时的方案数
转移：
dp[i][0][j]=dp[i-1][0][j]+dp[i-1][1][j];
dp[i][1][(j*10+t)%4]+=dp[i-1][1][j];    //0<=j<=3,t=str[i]
dp[i][1][t%4]++;
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=300000+10;
LL dp[maxn][2][4];
char str[maxn];

int main()
{
    LL i,j,n;
    while(scanf("%s",str+1)!=EOF){
        n=strlen(str+1);
        memset(dp,0,sizeof(dp));
     //   dp[0][1][0]=1;
        for(i=1;i<=n;i++){
            int t=(str[i]-'0');
            for(j=0;j<4;j++){
                dp[i][1][(j*10+t)%4]+=dp[i-1][1][j];
                dp[i][0][j]=dp[i-1][0][j]+dp[i-1][1][j];
            }
            dp[i][1][t%4]++;
        }
        printf("%I64d\n",dp[n][0][0]+dp[n][1][0]);
    }
    return 0;
}
