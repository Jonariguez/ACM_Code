/****************
*PID:450b div2
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
const LL MOD=1e9+7;
int main()
{
    LL i,j,n,m,x,y;
    while(scanf("%I64d%I64d%I64d",&x,&y,&n)!=EOF){
        n%=6;
        if(n==0){
            printf("%I64d\n",((x-y)%MOD+MOD)%MOD);
        }else if(n==1)
            printf("%I64d\n",((x)%MOD+MOD)%MOD);
        else if(n==2)
            printf("%I64d\n",((y)%MOD+MOD)%MOD);
        else if(n==3)
            printf("%I64d\n",((y-x)%MOD+MOD)%MOD);
        else if(n==4)
            printf("%I64d\n",((-x)%MOD+MOD)%MOD);
        else if(n==5)
            printf("%I64d\n",((-y)%MOD+MOD)%MOD);
    }
    return 0;
}
