/****************
*PID:poj2533
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

const int maxn=1000+10;
int a[maxn],dp[maxn];

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    dp[0]=1;
    int res=1;
    for(i=1;i<n;i++){
        dp[i]=1;
        for(j=0;j<i;j++)
            if(a[j]<a[i])
                dp[i]=max(dp[i],dp[j]+1);
        res=max(res,dp[i]);
    }
    printf("%d\n",res);
    return 0;
}
