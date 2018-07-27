/****************
*PID:cdvs1576
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=5000+5;
int dp[maxn];
int a[maxn];

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dp[0]=0;
    for(i=1;i<=n;i++){
        dp[i]=1;
        for(j=1;j<i;j++){
            if(a[j]<a[i])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
