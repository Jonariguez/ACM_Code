/*
简单二分（纯手工独立打造）
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#define eps 1e-10
#define PI acos(-1.0)

const int maxn=10000+10;
double s[maxn];         //保存的是每个pie的底面积
int n,f;

bool C(double v){       //测试体积v
    int i,cnt=0;
    for(i=0;i<n;i++){
        double t=v/s[i];    //计算以这样的v和这样的底面积s[i]，一个需要多高
        cnt+=floor(1/t);    //然后高度是1，那么看一个pie能分几个人
    }
    return cnt>=f+1;    //注意还有主人自己，需要+1
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
        double lb=0,ub=1000000000;   //ub一开始随便设置了一个值10000，忘了改了，WA了两次
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
