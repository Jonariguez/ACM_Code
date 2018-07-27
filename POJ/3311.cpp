/****************
*PID:poj3311
*Auth:Jonariguez
*****************
TSPŒ Ã‚
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=11;
const int INF=1000000000;
int dp[1<<maxn][maxn];
int vis[maxn][maxn],n;

void floyd(){
    int i,j,k;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                vis[i][j]=min(vis[i][j],vis[i][k]+vis[k][j]);
    }
}

int main()
{
    int i,j;
    while(scanf("%d",&n),n){
        n++;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&vis[i][j]);
        floyd();
        int mask;
        for(mask=0;mask<(1<<n);mask++)
            fill(dp[mask],dp[mask]+n,INF);
        dp[(1<<n)-1][0]=0;
        for(mask=(1<<n)-2;mask>=0;mask--){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(((mask>>j)&1)==0)
                        dp[mask][i]=min(dp[mask][i],dp[mask|(1<<j)][j]+vis[i][j]);
                }
            }
        }
        printf("%d\n",dp[0][0]);
    }
    return 0;
}
