/****************
*PID:478d div2
*Auth:Jonariguez
*****************
dp[i][j]:表示build到第i层用j个红色的方块的方案数。
i=0,1，数组翻转使用
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=200000+10;
const int mod=1e9+7;
LL dp[2][maxn];

int main()
{
    LL i,j,x,y,r,g;
    while(scanf("%I64d%I64d",&r,&g)!=EOF){
        if(r==0 || g==0){
            printf("1\n");continue;
        }
     //   LL h=(LL)sqrt(2*(r+g));
     //   while(h*(h+1)>2*(r+g)) h--;
        LL t=r+g,h=1;
        while(t>=h){
            t-=h;h++;
        }
        LL sum=h*(h-1)/2;
        h--;
        dp[1][1]=1;dp[1][0]=1;
        int d=1,b;
        LL now=1,to;
        for(i=2;i<=h;i++){
            now+=i;
            b=d^1;
            to=min(now,r);
            for(j=max(0LL,now-g);j<=to;j++){    //优化这里的循环控制条件,不然会超时。
                dp[b][j]=dp[d][j]%mod;
                if(j>=i) dp[b][j]+=dp[d][j-i];
                if(dp[b][j]>=mod)
                    dp[b][j]%=mod;
            }
            for(j=0;j<=r;j++) dp[d][j]=0;
            d^=1;
        }
        LL res=0;
        for(i=0;i<=r;i++){
            res+=dp[d][i];
            dp[d][i]=0;
            if(res>=mod) res%=mod;
        }
        if(res<0) res+=mod;
        printf("%I64d\n",res%mod);
    }
    return 0;
}
