/****************
*PID:602a div2
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
    LL i,n,bx,m,by;
    scanf("%I64d%I64d",&n,&bx);
    LL x=0,now=1,v;
    for(i=0;i<n;i++){
        scanf("%I64d",&v);
        x=x*bx+v;
    }
    scanf("%I64d%I64d",&n,&bx);
    LL y=0;
    for(i=0;i<n;i++){
        scanf("%I64d",&v);
        y=y*bx+v;
    }
    if(x==y)
        printf("=\n");
    else if(x<y)
        printf("<\n");
    else printf(">\n");
    return 0;
}
