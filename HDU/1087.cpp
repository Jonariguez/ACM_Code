/****************
*PID:hdu1087
*Auth:Jonariguez
*****************
LIS
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000+10;
LL a[maxn],dp[maxn];

int main()
{
    LL i,j,res,n;
    while(scanf("%lld",&n),n){
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        res=0;
        dp[1]=a[1];
        for(i=2;i<=n;i++){
            dp[i]=a[i];
            for(j=1;j<i;j++){
                if(a[j]<a[i])
                    dp[i]=max(dp[i],dp[j]+a[i]);
            }
            res=max(res,dp[i]);
        }
        printf("%lld\n",res);
    }
    return 0;
}
