/****************
*PID:471c div2
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

LL res,n;

int main()
{
    LL i,j,h,k,t,sum;
    while(scanf("%I64d",&n)!=EOF){
        if(n==2){
            printf("1\n");continue;
        }
        k=(LL)sqrt(n);
        k++;//printf("k=%I64d\n",k);
        res=0;
        for(i=1;i<=1000000;i++){
            t=n-2*i;
            if(t<=0) break;
            sum=i*(i-1)/2;
            if(t>=3*sum && t%3==0){
                res++;//printf("t=%I64d\n",t);
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}
