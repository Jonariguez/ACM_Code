/****************
*PID:534b div2
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

const int maxn=100000+10;
LL dp[105][1005];

int main()
{
    LL i,j,t,n,v1,v2,d;
    scanf("%I64d%I64d%I64d%I64d",&v1,&v2,&t,&d);
    memset(dp,-1,sizeof(dp));
    dp[t][v2]=v2;
    for(i=t-1;i>0;i--){
        for(j=0;j<=1000;j++){
           // dp[i][j+k]=-1;
            for(int k=-d;k<=d;k++){
                if(dp[i+1][j]>=0 && j+k>=0)
                    dp[i][j+k]=max(dp[i][j+k],dp[i+1][j]+j+k);
            }
        }
    }
    printf("%I64d\n",dp[1][v1]);
    return 0;
}
