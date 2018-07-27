/****************
*PID:478c div2
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

LL c[5];

int main()
{
    int i,j,n=3;
    while(scanf("%I64d%I64d%I64d",&c[1],&c[2],&c[3])!=EOF){
        sort(c+1,c+4);
        LL res=0;
        if(c[3]>=2*(c[1]+c[2]))
            res=c[1]+c[2];
        else res=(c[1]+c[2]+c[3])/3;
      //  c[2]-=c[1];c[3]-=c[1];
      //  if(c[3]>=2*c[2]) res+=c[2];
      //  else res+=(c[2]+c[3])/3;
        printf("%I64d\n",res);
    }
    return 0;
}
