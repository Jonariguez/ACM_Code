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

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    LL now=2,lcm=1,i,n;
    for(i=2;i<=10;i++)
        lcm=lcm/gcd(lcm,i)*i;
    while(scanf("%I64d",&n)!=EOF)
        printf("%I64d\n",n/lcm);
    return 0;
}
