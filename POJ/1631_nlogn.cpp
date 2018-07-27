/****************
*PID:poj1631
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

const int maxp=40000+10;
int a[maxp],dp[maxp];

int main()
{
    int i,j,p,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&p);
        for(i=0;i<p;i++)
            scanf("%d",&a[i]);
        fill(dp,dp+p+1,maxp);
        for(i=0;i<p;i++)
            *lower_bound(dp,dp+p,a[i])=a[i];
        printf("%d\n",lower_bound(dp,dp+p,maxp)-dp);
    }
    return 0;
}
