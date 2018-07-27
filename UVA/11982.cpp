/****************
*PID:uva11982
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
const int MOD=1e9+7;
char str[maxn];
LL dp[maxn][maxn],n;

int main()
{
    LL i,j;
    int T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str);
        n=strlen(str);
        LL cnt=0;
        for(i=0;i<n;i++)
            if(str[i]!='E') str[cnt++]=str[i];
        n=cnt;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(i=0;i<n;i++){
            for(j=0;j<=i;j++){
                if(str[i]=='D'){
                    dp[i+1][j]=(dp[i+1][j]+dp[i][j]*j)%MOD;
                    if(j)
                        dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j]*j*j)%MOD;
                }else if(str[i]=='U'){
                    dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%MOD;
                    dp[i+1][j]=(dp[i+1][j]+dp[i][j]*j)%MOD;
                }
            }
        }
        printf("Case %d: %lld\n",kcase++,dp[n][0]);
    }
    return 0;
}
