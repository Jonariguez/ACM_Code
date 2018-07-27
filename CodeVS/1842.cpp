/****************
*PID:cdvs1842
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

LL f(LL x){
    if(x>=0) return 5LL;
    return f(x+1)+f(x+2)+1;
}

int main()
{
    LL x;
    scanf("%lld",&x);
    printf("%lld\n",f(x));
    return 0;
}
