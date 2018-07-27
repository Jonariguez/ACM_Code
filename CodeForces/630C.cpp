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

const int maxn=60;
LL fact[60];

int main()
{
    LL i,j,n;
    fact[0]=1;
    for(i=1;i<=56;i++)
        fact[i]=fact[i-1]*2;
    fact[0]=0;
    for(i=1;i<=56;i++)
        fact[i]+=fact[i-1];
    while(scanf("%I64d",&n)!=EOF){
        printf("%I64d\n",fact[n]);
    }
    return 0;
}
