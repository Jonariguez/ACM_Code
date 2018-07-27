#include <stdio.h>
#include <string.h>
#include <math.h>
#define eps 1e-10   //一开始把那个弧当成了抛物线了，答案一直是偏大一点

double L,n,c,l; //L原始长度，l加热后的长度

double F(double h){
    double r=(L*L+4*h*h)/(8*h);
    return asin(L/(2*r))*2*r;
}

int main()
{
    int i,j,k;
    while(scanf("%lf%lf%lf",&L,&n,&c)){
        if(L<0 && n<0 && c<0) break;
        l=(1+n*c)*L;
        double lb=0,ub=L/2;
        for(i=0;i<50;i++){
            double m=(lb+ub)/2;
            if(F(m)>l)
                ub=m;
            else
                lb=m;
        }
        printf("%.3f\n",lb);
    }
    return 0;
}
