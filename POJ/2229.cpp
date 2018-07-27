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
typedef long long LL;

const int maxn=1000000+5;
const int mod=1e9;

LL a[20],dp[maxn];


int main()
{
    LL i,j,n,m;
    scanf("%I64d",&n);
    dp[1]=1;
    for(i=2;i<=n;i++){
        if(i&1) dp[i]=dp[i-1];
        else dp[i]=(dp[i-1]+dp[i/2])%mod;
    }
    printf("%I64d\n",dp[n]);
    return 0;
}
