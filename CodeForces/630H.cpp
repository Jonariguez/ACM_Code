/****************
*PID:
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

LL Com(LL n,LL m){
    LL res=n;
    for(LL i=2;i<=m;i++){
        n--;
        res*=n;res/=i;
    }
    return res;
}

int main()
{
    LL res,n;
    while(scanf("%I64d",&n)!=EOF){
        res=Com(n,(LL)5);
        for(LL i=n;i>n-5;i--)
            res*=i;
        printf("%I64d\n",res);
    }
    return 0;
}
