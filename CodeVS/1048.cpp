/****************
*PID:cdvs1048
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
const int INF=1000000000;
int dp[maxn][maxn],sum[maxn],a[maxn];

int dfs(int i,int j){
    if(i>=j) return 0;
    int &ans=dp[i][j];
    if(ans>=0) return ans;
    int k;
    ans=INF;
    for(k=i;k<=j;k++)
        ans=min(ans,dfs(i,k)+dfs(k+1,j)+sum[j]-sum[i-1]);
    return ans;
}

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        sum[0]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n",dfs(1,n));
    }
    return 0;
}
