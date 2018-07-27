/****************
*PID:624a div2
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
    int i,j,n;
    double d,l,v1,v2;
    while(scanf("%lf%lf%lf%lf",&d,&l,&v1,&v2)!=EOF){
        printf("%.8f\n",(l-d)/(v1+v2));
    }
    return 0;
}
