/*
假设最好打开第1个盒子空了，看第2个盒子还有i颗。
则之前打开过n+(n-i)次盒子，n次是盒子1，n-i次是
盒子2，那么概率就是C(2*n-i,n)*p^(n+1)*(1-p)^(n-i)。
p的指数是n+1，因为最后还要开一次1

C太大，后面的又太小，损失精度太多，利用对数处理：

设v1[i]=ln(C(2*n-i,n)) + (n+1)*ln(p) + (n-i)*ln(1-p);
则“最后打开第1个盒子空，第2个还剩i个”对应的概率就是exp(v1[i])

一开始我想着计算ln(C(2*n-i,n))都要重新暴力计算，这样的话
就是O(n^2)了，肯定不行，后来想到了：
C(2*n-i,n)=(2*n-i)!/(n!*(n-i)!),对v1[i]取对数之后就是：
    ①        ②          ③              ④            ⑤
ln(2*n-i)! - ln(n!) - ln((n-i)!) + (n+1)*ln(p) + (n-i)*ln(1-p)

当i变换时只要①，③，⑤变换，随着i增大1
①  应该减小ln(2*n-i+1)
②  应该增大ln(n-i+1)
③  应该减少ln(1-p)

所以求ln(C(2*n-i,n))，只需要一开始暴力求解出来(LNC)，
之后只需O(1)的时间来得到其相邻的v1[i+1]....
(也可以预处理出log(1),log(2)的前缀和，可以O(1)计算)

同理，对于盒子2也一样：
v2[i]=ln(C(2*n-i,n)) + (n+1)*ln(1-p) + (n-i)*ln(p);

要用long double
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=200000+5;
long double v1[maxn],v2[maxn];

int main()
{
    int i,j,n,kcase=1;
    double p;
    long double LNC;
    while(scanf("%d%lf",&n,&p)!=EOF){
        LNC=0;
        for(i=1;i<=n;i++){
            LNC+=log(i+n);
            LNC-=log(i);
        }
        v1[0]=LNC+(n+1)*log(p)+n*log(1-p);
        v2[0]=LNC+(n+1)*log(1-p)+n*log(p);
        for(i=1;i<=n;i++){
            long double exc=log(n-i+1)-log(2*n-i+1);     //注意这里的都要+1，因为i相对于上一次大了1
            v1[i]=v1[i-1]+exc-log(1-p);
            v2[i]=v2[i-1]+exc-log(p);
        }
        double res=0;
        for(i=1;i<=n;i++)
            res+=i*(exp(v1[i])+exp(v2[i]));
        printf("Case %d: %.6lf\n",kcase++,res);
    }
    return 0;
}

