/****************
*PID:uva1025
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=55;
const int maxT=200+10;
const int INF=1000000000;

int dp[maxT][maxn],n,T,M1,M2;
int dis[maxn],a[maxn],b[maxn];
bool has[maxT][maxn][2];

void pre_solve(){
    int i,j,last;
    memset(has,0,sizeof(has));
    last=0;
    for(i=1;i<=M1;i++){
        last=a[i];
        for(j=1;j<n;j++){
            if(last<=T)
                has[last][j][0]=1;
            last+=dis[j];
        }
    }
    for(i=1;i<=M2;i++){
        last=b[i];
        for(j=n-1;j>=1;j--){
            if(last<=T)
                has[last][j+1][1]=1;
            last+=dis[j];
        }
    }
}

int main()
{
    int i,j,kcase=1;
    while(scanf("%d",&n),n){
        scanf("%d",&T);
        for(i=1;i<n;i++)
            scanf("%d",&dis[i]);
        scanf("%d",&M1);
        for(i=1;i<=M1;i++)
            scanf("%d",&a[i]);
        scanf("%d",&M2);
        for(i=1;i<=M2;i++)
            scanf("%d",&b[i]);
        pre_solve();
        for(i=1;i<=n-1;i++)
            dp[T][i]=INF;
        dp[T][n]=0;
        for(i=T-1;i>=0;i--)
            for(j=1;j<=n;j++){
                dp[i][j]=dp[i+1][j]+1;
                if(j<n && has[i][j][0] && i+dis[j]<=T)
                    dp[i][j]=min(dp[i][j],dp[i+dis[j]][j+1]);
                if(j>1 && has[i][j][1] && i+dis[j-1]<=T)
                    dp[i][j]=min(dp[i][j],dp[i+dis[j-1]][j-1]);
            }
        printf("Case Number %d: ",kcase++);
        if(dp[0][1]>=INF)
            printf("impossible\n");
        else
            printf("%d\n",dp[0][1]);
    }
    return 0;
}
