/****************
*PID:hdu1176
*Auth:Jonariguez
*****************
二维dp
抽象成数塔
a[i][j]：第i秒在j位置掉下的馅饼数量
dp[i][j]:第i秒在j位置最多能接多少
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+5;
int dp[maxn][12],a[maxn][12];

int main()
{
    int i,j,n;
    while(scanf("%d",&n),n){
        memset(a,0,sizeof(a));
        int x,t,m=1;
        for(i=0;i<n;i++){
            scanf("%d%d",&x,&t);
            a[t][x]++;
            m=max(m,t);
        }
        for(i=0;i<=10;i++)
            dp[m][i]=a[m][i];
        for(i=m-1;i>=0;i--){
            for(j=0;j<=10;j++){
                if(j==0)
                    dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
                else if(j==10)
                    dp[i][j]=max(dp[i+1][j],dp[i+1][j-1])+a[i][j];
                else dp[i][j]=max(dp[i+1][j],max(dp[i+1][j-1],dp[i+1][j+1]))+a[i][j];
            }
        }
        printf("%d\n",dp[0][5]);
    }
    return 0;
}
