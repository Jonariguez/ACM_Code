/*
�򵥶��֣����ֹ��������죩
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#define eps 1e-10
#define PI acos(-1.0)

const int maxn=10000+10;
double s[maxn];         //�������ÿ��pie�ĵ����
int n,f;

bool C(double v){       //�������v
    int i,cnt=0;
    for(i=0;i<n;i++){
        double t=v/s[i];    //������������v�������ĵ����s[i]��һ����Ҫ���
        cnt+=floor(1/t);    //Ȼ��߶���1����ô��һ��pie�ּܷ�����
    }
    return cnt>=f+1;    //ע�⻹�������Լ�����Ҫ+1
}

int main()
{
    int i,j,k,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&f);
        double r;
        for(i=0;i<n;i++){
            scanf("%lf",&r);
            s[i]=r*r*PI;
        }
        double lb=0,ub=1000000000;   //ubһ��ʼ���������һ��ֵ10000�����˸��ˣ�WA������
        for(i=0;i<100;i++){
            double m=(lb+ub)/2;
            if(C(m))
                lb=m;
            else
                ub=m;
        }
        printf("%.4f\n",lb);
    }
    return 0;
}
