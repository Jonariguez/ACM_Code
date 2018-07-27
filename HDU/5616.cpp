/****************
*PID:hdu5616
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=4000+10;
int dp[22][maxn],a[22];

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int sum=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(i=1;i<=n;i++){
            dp[i][a[i]]=1;
            for(j=0;j<=2000;j++){
                if(dp[i-1][j]==0) continue;
                dp[i][j]=1;
                dp[i][j+a[i]]=1;
                dp[i][abs(j-a[i])]=1;
            }
        }
        scanf("%d",&m);
        while(m--){
            int k;
            scanf("%d",&k);
            if(k>sum){
                puts("NO");continue;
            }
            if(dp[n][k])
                puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
