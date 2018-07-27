/****************
*PID:uva12063
*Auth:Jonariguez
*****************
dp，独立完成
dp[i][v][j][k]:表示第i位为v，且i位中有j个1，余数为k的方案数
答案为：dp[n][1][n/2][0]
转移方程：
dp[i][1][j][(k+((ULL)1<<(i-1)))%m]+=dp[i-1][0][j-1][k]+dp[i-1][1][j-1][k];
dp[i][0][j][k]+=dp[i-1][0][j][k]+dp[i-1][1][j][k];
注意用unsigned long long和n为奇数要特判
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;

ULL dp[65][2][65][100];

int main()
{
    ULL i,j,k,v,n,m;
    int T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%llu%llu",&n,&m);
        printf("Case %d: ",kcase++);
        if(n&1){
            printf("0\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0][0][0]=1;
        for(i=1;i<=n;i++){
            for(j=0;j<=n;j++){
             /*   for(k=0;k<m;k++){
                    ULL &ans=dp[i][0][j][k];
                    ans=0;
                    if(dp[i-1][0][j][k]>0) ans+=dp[i-1][0][j][k];
                    if(dp[i-1][1][j][k]>0) ans+=dp[i-1][1][j][k];
                }*/
              //  if(j){
                    for(k=0;k<m;k++){
                        if(j!=0)            //注意是1<<(i-1)，而不是1<<i
                            dp[i][1][j][(k+((ULL)1<<(i-1)))%m]+=dp[i-1][0][j-1][k]+dp[i-1][1][j-1][k];
                        dp[i][0][j][k]+=dp[i-1][0][j][k]+dp[i-1][1][j][k];
                    }
              //  }
            }
        }
        printf("%llu\n",dp[n][1][n/2][0]);
    }
    return 0;
}
