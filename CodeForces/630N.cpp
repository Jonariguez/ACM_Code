/****************
*PID:630n
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    double a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF){
        double x,y;
        x=(-b+sqrt(b*b-4*a*c))/2/a;
        y=(-b-sqrt(b*b-4*a*c))/2/a;
        if(x<y)
            swap(x,y);
        printf("%.8f\n%.8f\n",x,y);
    }
    return 0;
}
