/****************
*PID:584B div1
*Auth:Jonariguez
*****************
n=1时 f[1]=20
n=1时一共有3*3*3=27中情况，符合要求的有20个，即不符合要求的有7个。
当n从1增加到2时，符合要求的方案有两种情况：
①当n=1时符合时，新增的这个等边三角形可以符合，也可以不符合（共27情况），共f[n=1]*27
②当新增的这个等边三角形符合情况时（共20种情况），那么n=1的那个三角形应该不符合情况（共7种：27-20），共20*(27-20)
以上两种情况才会不重不漏的覆盖全部情况。
所以由n=i时的答案为f[i],向n=i+1时递推时就是
f[i+1]=f[i]*27+(sum-f[i-1])*20
        ①               ②
sum为i个等边三角形的全部情况，即27^i
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
