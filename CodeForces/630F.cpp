/****************
*PID:630f
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
    LL i,j,n;
    while(scanf("%I64d",&n)!=EOF){
        LL res=0;
        for(i=5;i<=7;i++)
            res+=Com(n,i);
        printf("%I64d\n",res);
    }
    return 0;
}
