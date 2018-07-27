/****************
*PID:507b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define eps 1e-8
const int maxn=100000+10;

int main()
{
    int i,j,res,n,m;
    double r,x1,y1,x2,y2;
    while(scanf("%lf%lf%lf%lf%lf",&r,&x1,&y1,&x2,&y2)!=EOF){
        double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(fabs(d)<=eps){
            printf("0\n");continue;
        }
        double t=d/2/r;
        if((int)(t)*r*2<d)
            printf("%d\n",(int)t+1);
        else printf("%d\n",(int)t);
    }
    return 0;
}
