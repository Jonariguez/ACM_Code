/****************
*PID:486a div2
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

const int maxn=100000+10;
LL n;

int main()
{
    LL res,i;
    while(scanf("%I64d",&n)!=EOF){
        res=n/2;
        if(n&1)
            res-=n;
        printf("%I64d\n",res);
    }
    return 0;
}
