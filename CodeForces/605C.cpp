/****************
*PID:605c div2
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
const int INF=10000000;
int a[maxn],b[maxn],dp[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            b[i]=-a[n-i-1];
        memset(dp,0,sizeof(dp));
       // for(i=0;i<n;i++)
       //     dp[a[i]]=1;
        for(i=0;i<n;i++)
            dp[a[i]]=max(1,dp[a[i]-1]+1);
        int res=0;
        for(i=1;i<=n;i++)
            res=max(res,dp[i]);
        printf("%d\n",n-res);
    }
    return 0;
}
