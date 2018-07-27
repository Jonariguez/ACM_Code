#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=350+10;

int a[maxn][maxn],dp[maxn][maxn];

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
        dp[n][i]=a[n][i];
    for(i=n-1;i>0;i--)
        for(j=1;j<=i;j++)
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
    printf("%d\n",dp[1][1]);
    return 0;
}
