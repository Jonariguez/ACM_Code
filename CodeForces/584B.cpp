/****************
*PID:584B div1
*Auth:Jonariguez
*****************
n=1ʱ f[1]=20
n=1ʱһ����3*3*3=27�����������Ҫ�����20������������Ҫ�����7����
��n��1���ӵ�2ʱ������Ҫ��ķ��������������
�ٵ�n=1ʱ����ʱ������������ȱ������ο��Է��ϣ�Ҳ���Բ����ϣ���27���������f[n=1]*27
�ڵ�����������ȱ������η������ʱ����20�����������ôn=1���Ǹ�������Ӧ�ò������������7�֣�27-20������20*(27-20)
������������Ż᲻�ز�©�ĸ���ȫ�������
������n=iʱ�Ĵ�Ϊf[i],��n=i+1ʱ����ʱ����
f[i+1]=f[i]*27+(sum-f[i-1])*20
        ��               ��
sumΪi���ȱ������ε�ȫ���������27^i
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef __int64 LL;

const int maxn=100000+10;
const int MOD=1e9+7;
LL f[maxn];

void pre_solve(){
    LL sum=27;
    f[1]=20;
    for(LL i=2;i<=100000;i++){
        f[i]=f[i-1]*27+(sum-f[i-1])*20;
        f[i]%=MOD;
        sum=(sum*27)%MOD;
    }
}

int main()
{
    int i,n;
    pre_solve();
    while(scanf("%d",&n)!=EOF)
        printf("%I64d\n",f[n]);
    return 0;
}
