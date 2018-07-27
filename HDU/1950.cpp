/****************
*PID:hdu1950
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=40000+10;
int a[maxn],dp[maxn];

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        fill(dp,dp+n+1,maxn);
        for(i=0;i<n;i++)
            *lower_bound(dp,dp+n,a[i])=a[i];
        printf("%d\n",lower_bound(dp,dp+n,maxn)-dp);
    }
    return 0;
}
