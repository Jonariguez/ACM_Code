/****************
*PID:591a div2
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

int main()
{
    int i,j;
    double p,q,l,res,x,t;
    scanf("%lf%lf%lf",&l,&p,&q);
    x=l/(p+q)*p;
    printf("%.5f\n",x);
    return 0;
}
