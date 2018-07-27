/****************
*PID:hdu5569
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=1000+10;
const int INF=1e9;
int dp[maxn][maxn],a[maxn][maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++) {
                scanf("%d",&a[i][j]);
              //  dp[i][j]=INF;
            }
        }
        for(i=0;i<=n+1;i++)
            for(j=0;j<=m+1;j++)
                dp[i][j]=INF;
        dp[n-1][m]=a[n][m]*a[n-1][m];
        dp[n][m-1]=a[n][m]*a[n][m-1];
        for(i=n;i>=1;i--){
            for(j=m;j>=1;j--){
                if(i==n && j==m) continue;
                if((n-i+m-j)%2==0){
                    if(i>1)
                        dp[i-1][j]=min(dp[i-1][j],a[i-1][j]*a[i][j]+min(dp[i+1][j],dp[i][j+1]));
                    if(j>1)
                        dp[i][j-1]=min(dp[i][j-1],a[i][j-1]*a[i][j]+min(dp[i+1][j],dp[i][j+1]));
                }
            }
        }
        printf("%d\n",dp[1][1]);
    }
    return 0;
}
