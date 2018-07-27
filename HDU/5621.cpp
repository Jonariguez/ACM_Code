/****************
*PID:hdu5621
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

LL cal(LL n){
    return n*(n+1)/2;
}

int main()
{
    LL i,j,res,n;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%llu",&n);
        res=0;
        for(i=2;i<n;i++){
            res+=cal(n-i-1)*(i-1);
        }
        printf("%llu\n",res+n);
    }
    return 0;
}
