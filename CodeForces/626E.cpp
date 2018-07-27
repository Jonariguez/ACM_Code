/****************
*PID:626e com
*Auth:Jonariguez
*****************
最优解的集合的size一定为奇数。
假设中位数位置i，集合的size为len，那么此时的
集合组成为a[i]，整个序列后len个和i前面len个。
枚举中位数位置i，需要三分来求集合的size
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=200000+10;
LL a[maxn],sum[maxn];

int main()
{
    LL i,j,n;
    while(scanf("%I64d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        sort(a+1,a+n+1);
        sum[0]=0;
        for(i=1;i<=n;i++)
            sum[i]=sum[i-1]+a[i];
        if(n==1 || n==2){
            printf("1\n%I64d\n",a[1]);continue;
        }
        LL l,r,sum1,sum2,now,res=0,mid=1,len=0;
        for(i=2;i<n;i++){   //枚举中位数
            l=1;r=min(i-1,n-i);
            for(j=1;j<=100;j++){
                LL m1=(2*l+r)/3;
                LL m2=(l+2*r+2)/3;
                sum1=(sum[i]-sum[i-m1-1])+(sum[n]-sum[n-m1]);
                sum2=(sum[i]-sum[i-m2-1])+(sum[n]-sum[n-m2]);
                if(sum1*(m2*2+1)<sum2*(m1*2+1))
                    l=m1+1;
                else r=m2-1;
            }
            //三分过后，l表示集合的size，i是中位数的位置。
            now=(sum[i]-sum[i-l-1])+(sum[n]-sum[n-l])-a[i]*(2*l+1);//==(mean-median)*(size)
            if(now*(2*len+1)>res*(2*l+1)){
                mid=i;len=l;res=now;
            }
        }
        printf("%I64d\n",2*len+1);
        for(i=mid-len;i<=mid;i++)
            printf("%I64d ",a[i]);
        for(i=n-len+1;i<=n;i++)
            printf("%I64d ",a[i]);
        puts("");
    }
    return 0;
}


