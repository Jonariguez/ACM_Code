/****************
*PID:474c div2
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
const int mod=1e9+7;
LL dp[maxn];

int main()
{
    int i,j,t,k;
    scanf("%d%d",&t,&k);
    for(i=0;i<k;i++)
        dp[i]=1;
    for(i=k;i<=100000;i++)
        dp[i]=(dp[i-1]+dp[i-k])%mod;
    for(i=1;i<=100000;i++){
        dp[i]+=dp[i-1];
        dp[i]%=mod;
    }
    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        LL res=(dp[b]-dp[a-1])%mod;
        if(res<0) res+=mod;
        printf("%I64d\n",res);
    }
    return 0;
}
