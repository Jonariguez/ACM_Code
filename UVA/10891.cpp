/****************
*PID:uva10891
*Auth:Jonariguez
*****************
dp[i][j]:从a[i..j]中选数，先手能得到的最高分。
dp[i][j]=sum[i..j]-min{dp[i+1][j]..dp[j][j],dp[i][j-1]..dp[i][i],0}(0是全选了，不给对手留)
这里取min的原因是：自己取完之后就该对手取了，所以min里面的都是对手的可能
得分，故要取对手最小的分。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100+10;
int dp[maxn][maxn],sum[maxn],vis[maxn][maxn],a[maxn];

int DP(int i,int j){
    if(vis[i][j]) return dp[i][j];
    vis[i][j]=1;
    int &ans=dp[i][j];
    int m=0;
    for(int k=i+1;k<=j;k++)
        m=min(m,DP(k,j));
    for(int k=j-1;k>=i;k--)
        m=min(m,DP(i,k));
    dp[i][j]=sum[j]-sum[i-1]-m;
    return dp[i][j];
}

int main()
{
    int i,j,n,res;
    while(scanf("%d",&n),n){
        sum[0]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        memset(vis,0,sizeof(vis));
        printf("%d\n",2*DP(1,n)-sum[n]);  //dp[1][n]-(sum[n]-dp[1][n])
    }
    return 0;
}
