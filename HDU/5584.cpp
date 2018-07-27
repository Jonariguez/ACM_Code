/****************
*PID:hdu5584
*Auth:Jonariguez
*****************
当前点(x,y)，且y>x,则前一个点存在的话就一定是(x,y-z),其中z=LCM(x,y-z)，
不可能是x变小。
公式：gcd(x,y)=gcd(x,y-k*x)
有题意及题设得：x*(y-z)=z*gcd(x,y-z)
又z=LCM(x,y-z)，故z是x的整数倍，即k*x
所以gcd(x,y-z)=gcd(x,y-k*x)=gcd(x,y)
设g=gcd(x,y),则x*(y-z)=z*g
化简可得：z=(x*y)/(g+x)      (一定要是整除才行，如果(x*y)%(g+x)不等于0则退出)
同时保证z>=x && z<y 且z则是x和(y-z)的倍数。
当x==y时则前面就不可能再有点了，注意就是一直保证y>x
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    LL i,j,x,y,T,res,kcase=1;
    scanf("%I64d",&T);
    while(T--){
        scanf("%I64d%I64d",&x,&y);
        res=1;
        while(x!=y){
            LL g=gcd(x,y);
            if(x>y){
                LL t=x;x=y;y=t;
            }
            if((x*y)%(x+g)) break;
            LL z=(x*y)/(g+x);
            if(z%x || z<x || z>=y || z%(y-z)) break;
            y-=z;
            res++;
        }
        printf("Case #%I64d: %I64d\n",kcase++,res);
    }
    return 0;
}

