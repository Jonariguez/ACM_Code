/****************
*PID:cdvs3112
*Auth:Jonariguez
*****************
¿¨ÌØÀ¼Êý
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

LL com(LL n,LL m){
    LL res=n;
    for(LL i=2;i<=m;i++){
        n--;
        res*=n;res/=i;
    }
    return res;
}

int main()
{
    LL n;
    while(scanf("%lld",&n)!=EOF){
        printf("%lld\n",com(2*n,n)-com(2*n,n+1));
    }
    return 0;
}
