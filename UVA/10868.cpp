/*
物理题，
用动能定理
弹绳做功为0.5*k*delta*delta
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define eps 1e-9
const double g=9.81;

int main()
{
    double k,l,s,w;
    while(scanf("%lf%lf%lf%lf",&k,&l,&s,&w)){
        if(fabs(k)<=eps && fabs(l)<=eps) break;
        if(l>=s){
            double h=50/g;
            if(s>h)
                printf("Killed by the impact.\n");
            else printf("James Bond survives.\n");
            continue;
        }
        double E=w*g*s-0.5*k*(s-l)*(s-l);
        if(E<0){
            printf("Stuck in the air.\n");
            continue;
        }
        double v=sqrt(2*E/w);
        if(v<=10)
            printf("James Bond survives.\n");
        else printf("Killed by the impact.\n");
    }
    return 0;
}
