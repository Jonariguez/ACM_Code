/****************
*PID:490d div2
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

LL a1,b1,a2,b2;

int main()
{
    LL i,j,n;
    while(scanf("%I64d%I64d",&a1,&b1)!=EOF){
        scanf("%I64d%I64d",&a2,&b2);
        LL a=a1*b1,b=a2*b2,t1=0,t2=0,res=0;
        while(a%3==0){
            t1++;a/=3;
        }
        while(b%3==0){
            t2++;b/=3;
        }
        res+=abs(t1-t2);
        while(t1>t2 && a1%3==0) a1-=a1/3,--t1;
        while(t1>t2 && b1%3==0) b1-=b1/3,--t1;
        while(t1<t2 && a2%3==0) a2-=a2/3,--t2;
        while(t1<t2 && b2%3==0) b2-=b2/3,--t2;
        if(t1!=t2){
            printf("-1\n");continue;
        }
        a=a1*b1;b=a2*b2;
        t1=t2=0;
        while(a%2==0){
            t1++;a/=2;
        }
        while(b%2==0){
            t2++;b/=2;
        }
        res+=abs(t1-t2);
        while(t1>t2 && a1%2==0) a1/=2,--t1;
        while(t1>t2 && b1%2==0) b1/=2,--t1;
        while(t1<t2 && a2%2==0) a2/=2,--t2;
        while(t1<t2 && b2%2==0) b2/=2,--t2;
        if(a1*b1!=a2*b2){
            printf("-1\n");continue;
        }
        printf("%I64d\n%I64d %I64d\n%I64d %I64d\n",res,a1,b1,a2,b2);
    }
    return 0;
}

