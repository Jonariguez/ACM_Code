/*
��������������
��½���ϵ�ʱ���ǹ̶���
�ں����ʱ���Ǿ��ȵģ����
�Ǵ����ã�l/v
��Ǵ����ߣ�3*l/v
���������ľ��ǣ�2*l/v
½���ϵ�ʱ�����d��ȥ���Եĺӳ�
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int i,d,n,kcase=1;
    double res,p,l,v;
    while(scanf("%d%d",&n,&d)){
        if(n==0 && d==0) break;
        res=0;
        double D=(double)d;
        for(i=0;i<n;i++){
            scanf("%lf%lf%lf",&p,&l,&v);
            res+=2*l/v;
            D-=l;
        }
        printf("Case %d: %.3f\n\n",kcase++,res+D);
    }
    return 0;
}
