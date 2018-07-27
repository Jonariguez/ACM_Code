/****************
*PID:uva12563
*Auth:Jonariguez
*****************
DP
dp[i+1][j]:前i首歌恰好用了j秒最多能唱几首歌
通过题目我们可以想到，我们就保证在t之前（即j<=t-1)
结束，然后再唱一首678秒的《劲歌》,所以递推时
j循环到t-1即可，然后遍历j找到dp的最大值，在
最大值有多个时，就使j（即结束时间）尽量大，
这样再加上+678秒也同样是最长时
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=55;
int dp[maxn][10000];
int a[maxn];

int main()
{
    int i,j,res,n,t,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&t);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<=t;i++)
            dp[0][i]=-1;
        dp[0][0]=0;
        for(i=0;i<n;i++){
            for(j=0;j<t;j++){
                dp[i+1][j]=dp[i][j];
                if(j>=a[i])
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j-a[i]]+1);
            }
        }
        int l=0;
        res=0;
        for(i=0;i<t;i++){
            if(dp[n][i]>=res){
                res=dp[n][i];l=i;
            }
        }
        printf("Case %d: %d %d\n",kcase++,res+1,l+678);  //加1是为在结束之前唱《劲歌》
    }
    return 0;
}
