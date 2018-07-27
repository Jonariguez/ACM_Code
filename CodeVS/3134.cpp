/****************
*PID:cdv3113
*Auth:Jonariguez
*****************
卡特兰数的定义。。
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
    LL k;
    while(scanf("%lld",&k)!=EOF){
        printf("%lld %lld\n",com(2*k,k)-com(2*k,k+1),k+1);
    }
    return 0;
}
