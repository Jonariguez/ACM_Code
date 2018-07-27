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

LL phi(LL n){
    LL res=n,i;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            res=res-res/i;
            while(n%i==0)
                n/=i;
        }
    }
    if(n!=1)
        res=res-res/n;
    return res;
}

int main()
{
    int T;
    LL n,x;
    while(scanf("%I64d%I64d",&n,&x)!=EOF)
        printf("%I64d\n",phi(n+x+1));
    return 0;
}
