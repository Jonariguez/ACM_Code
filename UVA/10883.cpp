/****************
*PID:uva10883
*Auth:Jonariguez
*****************
ans=sigma{a[i]*C(n-1,i)}/(2^(n-1));
用log优化
log(sigma)-(n-1)*log(2)
log(sigma)的求法，可以先求sigma：
枚举i，累加log(a[i])+Log[n-1]-Log[i]-Log[n-1-i]，
得sum，则log(sum)=log(sigma)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=50000+10;
double Log[maxn],a[maxn];

int main()
{
    int i,j,n,T,kcase=1;
    Log[0]=Log[1]=0;
    for(i=2;i<=50000;i++)
        Log[i]=Log[i-1]+log((double)i);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf",&a[i]);
        double sum=0.0;
        for(i=0;i<n;i++){
            if(a[i]>=0)
                sum+=exp(log(a[i])+(Log[n-1]-Log[i]-Log[n-1-i])-(n-1)*log(2));
            else sum-=exp(log((-1)*a[i])+(Log[n-1]-Log[i]-Log[n-1-i])-(n-1)*log(2));
        }
     /*   int sign=0;
        if(sum<0)
            sign=1;
        sum=log(fabs(sum));
        sum-=(n-1)*log(2);
        double res=exp(sum);
        if(sign) res*=(-1);*/
        printf("Case #%d: %.3f\n",kcase++,sum);
    }
    return 0;
}
