/****************
*PID:625a div2
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

int main()
{
    LL i,j,n,m,res,a,b,c;
    while(scanf("%I64d",&n)!=EOF){
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        if(n<a && n<b){
            puts("0");continue;
        }
        if(n<b){
            printf("%I64d\n",n/a);continue;
        }
        LL now=n,d=b-c,f=n-b+1;
        res=(f+d-1)/d;
        n-=res*d;
        if(n>=a) res+=n/a;
        printf("%I64d\n",max(now/a,res));
    }
    return 0;
}
