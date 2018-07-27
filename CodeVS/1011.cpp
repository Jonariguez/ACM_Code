/****************
*PID:cdvs1011
*Auth:Jonariguez
*****************
i是奇数时，f[i]=f[i-1]
i是偶数时，f[i]的个数应该为f[1]+f[2]+..+f[i/2]个，再加一个本身
用sum[]来保存前缀和
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000+10;
LL sum[maxn],f[maxn];

int main()
{
    LL i,j,n;
    sum[1]=1;
    f[1]=1;
    f[2]=2;
    sum[2]=3;
    scanf("%lld",&n);
    for(i=3;i<=n;i++){
        if(i&1) f[i]=f[i-1];
        else f[i]=sum[i/2]+1;
        sum[i]=sum[i-1]+f[i];
    }
    printf("%lld\n",f[n]);
    return 0;
}
