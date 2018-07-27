/****************
*PID:463d div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1000+10;
int a[6][maxn],pos[6][maxn],dp[maxn];

int main()
{
    int i,j,n,k,res;
    while(scanf("%d%d",&n,&k)!=EOF){
        for(i=1;i<=k;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
                pos[i][a[i][j]]=j;
            }
        }
        dp[0]=0;
        for(i=1;i<=n;i++){
            int t=a[1][i];
            dp[i]=1;
            for(j=1;j<i;j++){
                int v=a[1][j],d;
                for(d=1;d<=k;d++)
                    if(pos[d][v]>pos[d][t]) break;
                if(d<=k) continue;
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        res=0;
        for(i=1;i<=n;i++) res=max(res,dp[i]);
        printf("%d\n",res);
    }
    return 0;
}

