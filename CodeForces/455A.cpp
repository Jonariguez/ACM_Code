/****************
*PID:455a div1
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

const int maxn=100000+10;
int a[maxn],cnt[maxn];
LL dp[maxn][2];

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        memset(cnt,0,sizeof(cnt));
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        sort(a+1,a+n+1);
        memset(dp,0,sizeof(dp));
        a[0]=-1;
        for(i=a[1];i<=a[n];i++){
            dp[i][1]=dp[i-1][0]+(LL)i*cnt[i];
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        }
        printf("%I64d\n",max(dp[a[n]][0],dp[a[n]][1]));
    }
    return 0;
}


