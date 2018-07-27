/****************
*PID:hdu5492
*Auth:Jonariguez
*****************
dp[i][j][k]：到(i,j)序列和为k的，平方和的最小值
转移："我为人人"
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=33;
const int INF=2000000000;
int v[maxn][maxn],dp[maxn][maxn][1805];

int Pow(int x){
    return x*x;
}

int main()
{
    int i,j,k,n,m,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&v[i][j]);
                for(k=0;k<1800;k++)
                    dp[i][j][k]=INF;
            }
        }
        dp[1][1][v[1][1]]=Pow(v[1][1]);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(j<m){
                    for(k=0;k<1800;k++)
                        if(dp[i][j][k]!=INF)        //可达
                            dp[i][j+1][k+v[i][j+1]]=min(dp[i][j+1][k+v[i][j+1]],dp[i][j][k]+Pow(v[i][j+1]));
                }
                if(i<n){
                    for(k=0;k<1800;k++)
                        if(dp[i][j][k]!=INF)
                            dp[i+1][j][k+v[i+1][j]]=min(dp[i+1][j][k+v[i+1][j]],dp[i][j][k]+Pow(v[i+1][j]));
                }
            }
        }
        LL res=(1LL<<62),u=(LL)n+m-1;
        for(i=1;i<1800;i++)
            if(dp[n][m][i]!=INF)
                res=min(res,(LL)dp[n][m][i]*u-i*i);
        printf("Case #%d: %lld\n",kcase++,res);
    }
    return 0;
}
