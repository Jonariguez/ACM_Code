/****************
*PID:485b div2
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
    LL i,l,r,u,d,x,y,n;
    scanf("%I64d",&n);
    scanf("%I64d%I64d",&x,&y);
    l=r=x;u=d=y;
    for(i=1;i<n;i++){
        scanf("%I64d%I64d",&x,&y);
        l=min(l,x);r=max(r,x);
        d=min(d,y);u=max(u,y);
    }
    x=max(abs(r-l),abs(u-d));
    printf("%I64d\n",x*x);
    return 0;
}
