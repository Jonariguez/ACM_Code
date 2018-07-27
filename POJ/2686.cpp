/****************
*PID:poj2686
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=8;
const int maxm=30;
const int INF=1<<29;
int t[maxn],d[maxm][maxm];
double dp[1<<maxn][maxm];

int main()
{
    int i,j,n,m,a,b,p;
    while(scanf("%d%d%d%d%d",&n,&m,&p,&a,&b)){
        if(n==0 && m==0) break;
        for(i=0;i<n;i++) scanf("%d",&t[i]);
        memset(d,-1,sizeof(d));
        for(i=0;i<p;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            u--;v--;
            d[u][v]=d[v][u]=w;
        }
        for(i=0;i<(1<<n);i++)
            fill(dp[i],dp[i]+m+1,INF);
    //    printf("a=%d b=%d\n",a,b);
        dp[(1<<n)-1][a-1]=0.0;
        int S;
        double res=INF;
        for(S=(1<<n)-1;S>=0;S--){
            for(j=0;j<m;j++){
                for(i=0;i<n;i++){
                    if((S>>i)&1){
                        for(int k=0;k<m;k++){
                            if(d[j][k]>=0){
                                dp[S-(1<<i)][k]=min(dp[S-(1<<i)][k],dp[S][j]+(double)d[j][k]/t[i]);
                            }
                        }
                    }
                }
            }
        }
        for(S=0;S<(1<<n);S++)
            res=min(res,dp[S][b-1]);
        if(res!=INF)
            printf("%.3f\n",res);
        else printf("Impossible\n");
    }
    return 0;
}
