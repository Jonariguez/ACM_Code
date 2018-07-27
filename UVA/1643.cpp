/*
在全部的正方形的对角线在同一条直线上时阴影面积最大。
设L是全部正方形的边长和，点A：ya=ka*xa  点B：yb=kb*xb  则：
 xb-xa=L
 ka*xa-kb*xb=L

求得新的A(xa,ya),B(xb,yb)才是对角线的端点，然后用叉积求面积
再减去正方形面积的一半即答案
*/
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int i,n;
    double xa,ya,xb,yb,area,L,l;
    while(scanf("%d",&n),n){
        scanf("%lf%lf%lf%lf",&xa,&ya,&xb,&yb);
        area=0;L=0;
        for(i=0;i<n;i++){
            scanf("%lf",&l);
            area+=l*l;
            L+=l;
        }
        double ka=ya/xa,kb=yb/xb;
        xa=(kb+1)*L/(ka-kb);
        ya=xa*ka;
        xb=(ka+1)*L/(ka-kb);
        yb=xb*kb;
        double cross=fabs(xa*yb-xb*ya)/2;
        printf("%.3f\n",cross-area/2);
    }
    return 0;
}
