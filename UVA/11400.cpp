/****************
*PID:uva11400
*Auth:Jonariguez
*****************
dp[i]表示1~i个最小开销
则dp[i]=min(dp[j]+(sum[i]-sum[j])*c[i]+k[i]) 处理一下前缀和
先按v升序排序
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
const int INF=1000000009;

struct pp{
    int v,k,c,L;
    bool operator < (const pp &r) const {
        return v<r.v;
    }
}s[maxn];

int dp[maxn],sum[maxn];

int main()
{
    int i,j,n;
    while(scanf("%d",&n),n){
        for(i=1;i<=n;i++)
            scanf("%d%d%d%d",&s[i].v,&s[i].k,&s[i].c,&s[i].L);
        sort(s+1,s+n+1);
        sum[1]=s[1].L;
        dp[1]=s[1].k+s[1].L*s[1].c;
        for(i=2;i<=n;i++){
            sum[i]=sum[i-1]+s[i].L;
            dp[i]=sum[i]*s[i].c+s[i].k;     //前i种全买第i种，不要初始化为INF
            for(j=1;j<i;j++)
                dp[i]=min(dp[i],dp[j]+(sum[i]-sum[j])*s[i].c+s[i].k);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
