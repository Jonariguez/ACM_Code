/****************
*PID:hdu5115
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=200+20;
const int INF=1000000000;
int a[maxn],b[maxn],dp[maxn][maxn],sum[maxn];

int main()
{
    int i,j,n,m,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int res=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            res+=a[i];
        }
        sum[0]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&b[i]);
            sum[i]=sum[i-1]+b[i];
        }
        memset(dp,0,sizeof(dp));
        sum[n+1]=sum[n];
        b[0]=0;b[n+1]=0;a[0]=0;a[n+1]=0;
        for(i=1;i<=n;i++){
            dp[i][i]=b[i-1]+b[i+1];
        }
        for(i=n;i>0;i--){
            for(j=i;j<=n;j++){
                dp[i][j]=INF;
                for(int k=i;k<=j;k++)
                    dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+b[i-1]+b[j+1]);
            }
        }/*
        for(int p=0;p<=n;p++){
            for(i=1;i<n+1-p;i++){
                j=i+p;
                dp[i][j]=INF;
                for(int k=i;k<=j;k++)
                    dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+b[i-1]+b[j+1]);
            }
        }*/
        printf("Case #%d: %d\n",kcase++,dp[1][n]+res);
    }
    return 0;
}
