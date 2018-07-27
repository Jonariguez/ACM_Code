/****************
*ID:uva1650
*Auth:Jonariguez
*****************
dp
设dp[i][j]表示长度为i的序列，以j结尾的满足前i个条件的排列数
则当第i个要求为'?'时，很简单，即前面方案的总和。即dp[i][j]=sum(dp[i-1][k])(1<=k<i)
当第i个要求为'I'时，也容易理解。之前小于j的结尾数的方案都能累加过来。
即dp[i][j]=sum(dp[i-1][k])(1<=k<j)
但当第i个要求为'D'时，需要特殊理解下，对于某个j，为了保持排列的性质不变，
我们把大于等于j的数字都+1，这样就保证不改变状态了。其实‘I’的时候也是这样处理的。
只是处理后还是(1<=k<i)。但是‘D’的时候，k的取值应该是[j,i)。因为等于j的时候，由于之前
大于等于j的数字都加1了。所以之前的j变成了j+1。一样满足'D'条件。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
const int MOD=1000000007;
long long dp[maxn][maxn];
char str[maxn];

int main()
{
    int i,j,n;
    while(scanf("%s",str+1)!=EOF){
        n=strlen(str+1);
        memset(dp,0LL,sizeof(dp));
        dp[1][1]=1;
        for(i=2;i<=n+1;i++){
            if(str[i-1]=='?'){
                long long sum=0;
                for(j=1;j<i;j++)
                    sum=(sum+dp[i-1][j])%MOD;
                for(j=1;j<=i;j++)
                    dp[i][j]=sum;
            }else if(str[i-1]=='I'){
                dp[i][1]=0;
                for(j=2;j<=i;j++)
                    dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%MOD;
            }else {
                dp[i][i]=0;
                for(j=i-1;j>=1;j--)
                    dp[i][j]=(dp[i][j+1]+dp[i-1][j])%MOD;
            }
        }
        long long res=0;
        for(i=1;i<=n+1;i++)
            res=(res+dp[n+1][i])%MOD;
        printf("%lld\n",res);
    }
    return 0;
}
