/****************
*PID:598A
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
    int i,j,T;
    LL n;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d",&n);
        LL t=1,res=0;
        while(t<=n){
            res-=t;t*=2;
        }
        LL temp=n*(n+1)/2;
        printf("%I64d\n",temp+res*2);
    }
    return 0;
}
