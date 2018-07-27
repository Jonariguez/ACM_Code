/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+5;
const int MOD=1000000007;
long long dp[maxn][maxn];
int a[maxn];

int main()
{
    int i,j,n,p;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&p);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            a[i]%=p;
        }
        dp[0][0]=1;
        for(i=1;i<p;i++)
            dp[0][i]=0;
        for(i=1;i<=n;i++){
            for(j=0;j<p;j++)
                dp[i][j]=dp[i-1][j];
            int k=(p-a[i])%p;
            for(j=0;j<p;j++){
                dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
                k++;
                if(k==p) k=0;
            }
        }
        printf("%lld\n",dp[n][0]);
    }
    return 0;
}
