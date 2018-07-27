/****************
*PID:hdu5584
*Auth:Jonariguez
*****************
��ǰ��(x,y)����y>x,��ǰһ������ڵĻ���һ����(x,y-z),����z=LCM(x,y-z)��
��������x��С��
��ʽ��gcd(x,y)=gcd(x,y-k*x)
�����⼰����ã�x*(y-z)=z*gcd(x,y-z)
��z=LCM(x,y-z)����z��x������������k*x
����gcd(x,y-z)=gcd(x,y-k*x)=gcd(x,y)
��g=gcd(x,y),��x*(y-z)=z*g
����ɵã�z=(x*y)/(g+x)      (һ��Ҫ���������У����(x*y)%(g+x)������0���˳�)
ͬʱ��֤z>=x && z<y ��z����x��(y-z)�ı�����
��x==yʱ��ǰ��Ͳ��������е��ˣ�ע�����һֱ��֤y>x
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

