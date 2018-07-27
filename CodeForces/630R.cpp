/****************
*PID:630r
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
    LL n;
    while(scanf("%I64d",&n)!=EOF){
        if(n%2==1) puts("1");
        else puts("2");
    }
    return 0;
}
