/****************
*PID:uva11538
*Auth:Jonariguez
*****************
2»Êºó
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;

int main()
{
    ULL n,m,res,t;
    while(scanf("%llu%llu",&m,&n)){
        if(m==0 && n==0) break;
        res=m*n*(n-1)+n*m*(m-1);
        if(n>m)
            swap(n,m);
        res+=(2*n*(n-1)*(3*m-n-1))/3;
        printf("%llu\n",res);
    }
    return 0;
}
