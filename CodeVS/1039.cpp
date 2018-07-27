/****************
*PID:cdvs1039
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1000+5;

int dp[maxn][maxn];

int main()
{
    int i,j,n,k;
    scanf("%d%d",&n,&k);
    for(i=0;i<=n;i++)
        dp[i][1]=1;
    for(i=2;i<=k;i++){
        for(j=0;j<=n;j++){
            if(j>=i)
                dp[j][i]=dp[j-i][i]+dp[j][i-1];
            else dp[j][i]=dp[j][i-1];
        }
    }
    printf("%d\n",dp[n-k][k]);
    return 0;
}
