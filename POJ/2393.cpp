/****************
*PID:poj2393
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

const int maxn=10000+10;
LL c,y,n,s;

int main()
{
    LL i,j,res,sum;
    scanf("%I64d%I64d",&n,&s);
    scanf("%I64d%I64d",&c,&y);
    res=c*y;
    LL p=c;
    for(i=1;i<n;i++){
        scanf("%I64d%I64d",&c,&y);
        p=min(p+s,c);
        res+=p*y;
    }
    printf("%I64d\n",res);
    return 0;
}
