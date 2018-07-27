/*
期望的线性性质
在陆地上的时间是固定的
在河里的时间是均匀的，最好
是船正好；l/v
最坏是船刚走：3*l/v
所以期望的就是：2*l/v
陆地上的时间就是d减去所以的河长
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
