/****************
*PID:478b div2
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

int main()
{
    LL i,j,res,n,m;
    while(scanf("%I64d%I64d",&n,&m)!=EOF){
        LL res1=0,res2=0;
        LL t=n-m+1;
        res2=t*(t-1)/2;
        LL p=n/m;
        LL cnt=n%m;
        res1=cnt*p*(p+1)/2;
        res1+=(m-cnt)*p*(p-1)/2;
        printf("%I64d %I64d\n",res1,res2);
    }
    return 0;
}
