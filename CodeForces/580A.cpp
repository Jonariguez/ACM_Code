/****************
*PID:580A div2
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

const int maxn=100000+10;
const int INF=1e9+5;
int dp[maxn],a[maxn];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        fill(dp,dp+n+1,INF);
        for(i=0;i<n;i++)
            *lower_bound(dp,dp+n,a[i])=a[i];
        printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
    }
    return 0;
}
