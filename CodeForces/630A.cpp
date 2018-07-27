/****************
*PID:630a
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

const int maxn=100000+10;

LL quick_pow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1)
            res=(res*a)%100;
        b/=2;
        a=(a*a)%100;
    }
    return res;
}

int main()
{
    int i,j;
    LL n;
    while(scanf("%I64d",&n)!=EOF){
        puts("25");
    }
    return 0;
}
