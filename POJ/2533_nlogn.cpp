/****************
*PID:poj2533
*Auth:Jonariguez
*****************
LIS nlogn
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
const int INF=1e6;
int a[maxn],dp[maxn];

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    fill(dp,dp+n+1,INF);
    for(i=0;i<n;i++)
        *lower_bound(dp,dp+n,a[i])=a[i];
    printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
    return 0;
}
