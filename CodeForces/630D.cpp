/****************
*PID:630d
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long LL;

int main()
{
    LL i,res,n;
    while(scanf("%llu",&n)!=EOF){
        printf("%llu\n",n*(n+1)/2*6+1);
    }
    return 0;
}
