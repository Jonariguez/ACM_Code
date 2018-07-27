/****************
*PID:603b div1
*Auth:Jonariguez
*****************
对于其他的，将x=k*x带入得，f(k*k*x%p)=k*f(kx%p)%p=k*k*f(x)%p
那么 f(x)%p=k*f(x)%p=k*k*f(x)%p=k*k*k*f(x)%p=......
存在一个m,k^m=1 mod p.
根据费马小定理，m肯定是p-1的因子,直接暴力.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

LL quick_pow(LL a,LL b,LL m){
    a=(a%m+m)%m;
    LL res=1;
    while(b){
        if(b&1) res=(res*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return res;
}

int main()
{
    LL p,m,k,MOD=1000000007;
    while(scanf("%I64d%I64d",&p,&k)!=EOF){
        if(k==0)
            printf("%I64d\n",quick_pow(p,p-1,MOD));
        else if(k==1)
            printf("%I64d\n",quick_pow(p,p,MOD));
        else {
            LL x=k;
            for(m=1;;m++){
                if(x%p==1) break;
                x=x*k%p;
            }
            printf("%I64d\n",quick_pow(p,(p-1)/m,MOD));
        }
    }
    return 0;
}
