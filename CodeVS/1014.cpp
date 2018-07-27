/****************
*PID:
*Auth:Jonariguez
*****************
±³°ü
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=35;
int dp[maxn][20005],a[maxn];

int main()
{
    int i,j,n,v;
    scanf("%d%d",&v,&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<=n;i++) dp[i][0]=1;
    for(i=0;i<n;i++){
        for(j=0;j<=v;j++){
            if(dp[i][j]){
                if(j+a[i]<=v)
                    dp[i+1][j+a[i]]=1;
                dp[i+1][j]=1;
            }
        }
    }
    for(i=v;i>=0;i--)
        if(dp[n][i]) break;
    printf("%d\n",v-i);
    return 0;
}
