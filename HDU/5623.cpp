/****************
*PID:hdu5623
*Auth:Jonariguez
*****************
dp[i]表示：前i个数，先手能赢的最大分数。
转移：dp[i]=max{a[j+1]-dp[j]}(1<=j<i)
为什么是减呢？转移表示：现在先手取a[j+1..i]这些数，
取完之后剩j个数，同时对方变成了先手，那么对方的
得分就是dp[j]，而本方的得分是a[j+1]，故用a[j+1]-dp[j]
就是本方得分，然后取个最大值即可。
用now维护最大值，只要每确定一个状态dp[i]，那么就用
a[i+1]-dp[i]来更新now即可。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=50000+10;
LL dp[maxn],a[maxn];

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%I64d",&a[i]);
        sort(a+1,a+n+1);
        dp[0]=0;
        LL now=0;
        for(i=1;i<=n;i++){
            now=max(now,a[i]-dp[i-1]);
            dp[i]=now;
        }
        printf("%I64d\n",dp[n]);
    }
    return 0;
}
