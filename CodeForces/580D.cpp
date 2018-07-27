/****************
*PID:580d div2
*Auth:Jonariguez
*****************
dp[i][j]:已经吃了的才用i表示，且最后吃的j
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=21;
LL c[maxn][maxn],a[maxn],dp[1228230][maxn];


int main()
{
    LL i,j,n,m,k,res;
    while(scanf("%I64d%I64d%I64d",&n,&m,&k)!=EOF){
        for(i=0;i<n;i++)
            scanf("%I64d",&a[i]);
        for(i=0;i<k;i++){
            LL x,y,v;
            scanf("%I64d%I64d%I64d",&x,&y,&v);
            c[x-1][y-1]=v;
        }
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
            dp[(1<<i)][i]=a[i];
        LL mask;
        for(mask=0;mask<(1<<n);mask++){
            for(i=0;i<n;i++){
                if(mask&(1<<i)){
                    for(j=0;j<n;j++)
                        if((mask&(1<<j))==0)
                            dp[mask|(1<<j)][j]=max(dp[mask|(1<<j)][j],dp[mask][i]+c[i][j]+a[j]);
                }
            }
        }
        LL res=0;
        for(mask=0;mask<(1<<n);mask++){
            LL cnt=0;
            for(i=0;i<n;i++)
                if(mask&(1<<i)) cnt++;
            if(cnt==m)
                for(i=0;i<n;i++)
                    if(mask&(1<<i))
                        res=max(res,dp[mask][i]);
        }
        printf("%I64d\n",res);
    }
    return 0;
}
