/****************
*PID:476c div2
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

const int mod=1e9+7;

int main()
{
    LL i,j,n,a,b,res;
    while(scanf("%I64d%I64d",&a,&b)!=EOF){
        LL k;
        res=0;
        for(k=1;k<=a;k++){
            LL t=(k*b+1)%mod;
            LL c=(b*(b-1)/2)%mod;
            res=(res+t*c)%mod;
        }
        printf("%I64d\n",res);
    }
    return 0;
}
