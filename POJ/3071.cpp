/****************
*PID:poj3071
*Auth:Jonariguez
*****************
概率dp
第奇数个赢家和前一个赢家比赛
第偶数个赢家和后一个赢家比赛
j号队在第i轮时，是第t=j/(1<<(i-1))个赢家
根据t的奇偶性向前或者向后找它第i轮的可能对手
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=8;
double p[(1<<7)][(1<<7)];
double dp[8][(1<<7)];

int main()
{
    int i,j,n;
    while(scanf("%d",&n) && n!=-1){
        for(i=0;i<(1<<n);i++){
            for(j=0;j<(1<<n);j++)
                scanf("%lf",&p[i][j]);
        }
        memset(dp,0,sizeof(dp));
        for(i=0;i<(1<<n);i++)
            dp[1][i]=p[i][i^1];
        for(i=2;i<=n;i++){
            for(j=0;j<(1<<n);j++){
                int t=j/(1<<(i-1));
                if(t&1){
                    for(int k=(t-1)*(1<<(i-1));k<(t-1)*(1<<(i-1))+(1<<(i-1));k++)
                        dp[i][j]+=dp[i-1][j]*dp[i-1][k]*p[j][k];
                }else {
                    for(int k=(t+1)*(1<<(i-1));k<(t+1)*(1<<(i-1))+(1<<(i-1));k++)
                        dp[i][j]+=dp[i-1][j]*dp[i-1][k]*p[j][k];
                }
            }
        }
        int res=0;
        for(i=1;i<(1<<n);i++)
            if(dp[n][res]<dp[n][i])
                res=i;
        printf("%d\n",res+1);
    }
    return 0;
}
