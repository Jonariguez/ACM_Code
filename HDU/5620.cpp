/****************
*PID:hdu5620
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long LL;

LL f[1000];

int main()
{
    LL i,j,n,cnt=3,sum=3;
    int T;
    f[1]=1;f[2]=2;
    for(;;cnt++){
        f[cnt]=f[cnt-1]+f[cnt-2];
        sum+=f[cnt];
        if(sum>=1e18) break;
    }
   // printf("cnt=%I64d\n",cnt);
    scanf("%d",&T);
    while(T--){
        scanf("%llu",&n);
        if(n<3){
            printf("1\n",n);continue;
        }
        sum=0;
        for(i=1;i<=cnt;i++){
            if(sum+f[i]>n) break;
            sum+=f[i];
        }
        printf("%llu\n",i-1);
    }
    return 0;
}
