/****************
*PID:hdu5563
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define eps 1e-6

double x[10],y[10];

double dis(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    int i,j,k,n,T;
    scanf("%d",&T);
    while(T--){
        for(i=1;i<=5;i++)
            scanf("%lf%lf",&x[i],&y[i]);
        double xsum=0.0,ysum=0.0;
        for(i=1;i<=5;i++){
            xsum+=x[i];ysum+=y[i];
        }
        xsum/=5;ysum/=5;
        double temp=dis(x[1],y[1],xsum,ysum);
        int yes=1;
        for(i=2;i<=5;i++)
            if(fabs(dis(x[i],y[i],xsum,ysum)-temp)>eps)
                break;
        if(i<=5){
            printf("No\n");continue;
        }
        double d[100];
        int tot=0;
        for(i=1;i<=5;i++){
            for(j=i+1;j<=5;j++){
                d[++tot]=dis(x[i],y[i],x[j],y[j]);
            }
        }
        sort(d+1,d+tot+1);
        temp=d[1];
        for(i=2;i<=5;i++)
            if(fabs(d[i]-temp)>eps) break;
        if(i<=5)
            printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
