/****************
*PID:cdvs1017
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

const int maxn=50;
char str[maxn];
LL digit[maxn];
LL dp[maxn][maxn],part[maxn][maxn];

int main()
{
    LL i,j,n,k;
    scanf("%lld%lld",&n,&k);
    scanf("%s",str);
    for(i=1;i<=n;i++)
        digit[i]=str[i-1]-'0';
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
            part[i][j]=part[i][j-1]*10+digit[j];
    for(i=1;i<=n;i++)
        dp[i][0]=part[1][i];
    for(j=1;j<=k;j++){
        for(i=2;i<=n;i++){
            for(int v=1;v<i;v++){
                dp[i][j]=max(dp[i][j],dp[v][j-1]*part[v+1][i]);
            }
        }
    }
    printf("%lld\n",dp[n][k]);
    return 0;
}
