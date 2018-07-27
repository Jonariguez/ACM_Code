/****************
*PID:uva1347
*Auth:Jonariguez
*****************
dp[i][j]:1~i(i>j)全部走过，且两个人的当前位置分别是i和j
还需要走多长的距离。
转移：dp[i][j]-> dp[i+1][j]或dp[i+1][i]
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
double dp[maxn][maxn];
double x[maxn],y[maxn],dist[maxn][maxn];

int main()
{
    int i,j,n,res;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&x[i],&y[i]);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                dist[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        for(i=n-1;i>=2;i--){
            for(j=1;j<i;j++){
                if(i==n-1) dp[i][j]=dist[i][n]+dist[j][n];
                else dp[i][j]=min(dp[i+1][j]+dist[i][i+1],dp[i+1][i]+dist[i+1][j]);
            }
        }
        printf("%.2lf\n",dp[2][1]+dist[1][2]);
    }
    return 0;
}
