/****************
*PID:485c div2
*Auth:Jonariguez
*****************
贪心：
从L的二进制表示的地位向高位一直化0为1
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

LL fact[70],bit[70];

int main()
{
    LL i,j,L,R;
    fact[0]=1;
    for(i=1;i<=62;i++)
        fact[i]=fact[i-1]*2;
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%I64d%I64d",&L,&R);
        memset(bit,0,sizeof(bit));
        LL cnt=0,t=L;
        while(t){
            bit[cnt++]=t%2;
            t/=2;
        }
        LL rescnt=cnt,res=L,now=L;
        for(i=0;i<63;i++){
            if(bit[i]==0){
                now+=fact[i];
                if(now<=R){
                    rescnt++;res=now;
                }
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}
