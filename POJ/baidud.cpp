#include <stdio.h>
#include <math.h>
#define PI acos(-1.0)
#define eps 1e-10

int main()
{
    int i,T,n,kcase=1;
    double a,r;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d:\n",kcase++);
        scanf("%d%lf%lf",&n,&a,&r);
        double R=0.5*a*tan(PI*0.5-PI/(double)n);
      //  printf("R=%lf,r=%lf\n",R,r);
        if(fabs(R-r)<eps || R-r>0)
            printf("Give me a kiss!\n");
        else
            printf("I want to kiss you!\n");
    }
    return 0;
}
