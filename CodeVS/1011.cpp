/****************
*PID:cdvs1011
*Auth:Jonariguez
*****************
i������ʱ��f[i]=f[i-1]
i��ż��ʱ��f[i]�ĸ���Ӧ��Ϊf[1]+f[2]+..+f[i/2]�����ټ�һ������
��sum[]������ǰ׺��
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
