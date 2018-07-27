/****************
*PID:626c div2
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

LL n,m,k;

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

bool C(LL x){
    return (x/2>=n && x/3>=m && x/2+x/3-x/6>=n+m);
}

int main()
{
    LL i,j;
    while(scanf("%I64d%I64d",&n,&m)!=EOF){
        LL l=0,r=1e18;
        while(l<r-1){
            LL M=(l+r)/2;
            if(C(M))
                r=M;
            else l=M;
        }
        printf("%I64d\n",r);
    }
    return 0;
}
