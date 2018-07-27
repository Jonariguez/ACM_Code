/****************
*PID:608d div2
*Auth:Jonariguez
*****************
dp[i][j] = min(1 + dp[i + 1][j], dp[i + 1][k-1] + dp[k+1][j], 1 + dp[i + 2][j])
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=500+5;
bool vis[maxn][maxn];
int dp[maxn][maxn],a[maxn];

int dfs(int i,int j){
    if(i>j) return 0;
    if(i==j) return 1;
    int &ans=dp[i][j];
    if(ans>=0) return ans;
    ans=maxn;
    int k;
    for(k=i+2;k<=j;k++){
        if(a[i]==a[k])
            ans=min(ans,dfs(i+1,k-1)+dfs(k+1,j));
    }
    ans=min(ans,dfs(i+1,j)+1);
    if(a[i]==a[i+1])
        ans=min(ans,1+dfs(i+2,j));
    return ans;
}

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n",dfs(1,n));
    }
    return 0;
}


