/****************
*PID:cf577B
*Auth:Jonariguez
*****************
第一次独立写出一个dp来，过了。
当n>=m时，由抽屉原理知必是YES
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=2000+10;
bool dp[maxn][maxn];
int a[maxn];

int main()
{
    int i,j,t,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n>=m){
            int b;
            for(i=0;i<n;i++)
                scanf("%d",&b);
            printf("YES\n");
            continue;
        }
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++){
            int x=a[i]%m;
            dp[i][x]=1;
            for(j=0;j<m;j++)
                if(dp[i-1][j]){
                    dp[i][j]=1;
                    dp[i][(j+x)%m]=1;
                }
        }
        if(dp[n][0])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
