/****************
*PID:cf535b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef __int64 LL;

const int maxn=100000+10;
LL sum[11],m[11];
LL bit[12];


int main()
{
    int i,j;
    LL cnt,n;
    sum[0]=1;
    sum[1]=2;
    for(i=2;i<=10;i++)
        sum[i]=sum[i-1]*2;
    m[0]=0;
    for(i=1;i<=10;i++)
        m[i]=m[i-1]+sum[i];
    while(scanf("%I64d",&n)!=EOF){
        if(n==4){
            printf("1\n");continue;
        }
        if(n==7){
            printf("2\n");continue;
        }
        cnt=0;
        LL t=n;
        int tot=0;
        while(t){
            bit[tot++]=t%10;t/=10;
        }
        cnt=m[tot-1];
        for(i=tot-1;i>=0;i--)
            if(bit[i]==7){
              //  if(i)
                    cnt+=sum[i];
            }
          //  printf("cnt=%I64d\n",cnt);
        printf("%I64d\n",cnt+1);
    }
    return 0;
}
