/*
��ȫ���������εĶԽ�����ͬһ��ֱ����ʱ��Ӱ������
��L��ȫ�������εı߳��ͣ���A��ya=ka*xa  ��B��yb=kb*xb  ��
 xb-xa=L
 ka*xa-kb*xb=L

����µ�A(xa,ya),B(xb,yb)���ǶԽ��ߵĶ˵㣬Ȼ���ò�������
�ټ�ȥ�����������һ�뼴��
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
