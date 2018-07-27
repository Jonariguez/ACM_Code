/****************
*ID:hdu1028
*Auth:Jonariguez
*****************
母函数
(1+x+x^2+x^3..)*(1+x^2+x^4+...)*..*(1+x^n+x^(2n)+..)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=120+10;

int a[maxn],b[maxn];

int main()
{
    int i,j,k,n;
    while(scanf("%d",&n)!=EOF){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=0;i<=n;i++)
            a[i]=1;
        for(i=2;i<=n;i++){      //i是该计算第几个括号里面的
            for(j=0;j<=n;j++)       //j对应指数的系数，即j代表当前x^j的系数
                for(k=0;k+j<=n;k+=i)        //第i个括号里x的指数跨度为i，所以k依次表示第i个括号里面x的系数
                    b[k+j]+=a[j];
                memcpy(a,b,sizeof(b));
                memset(b,0,sizeof(b));
        }
        printf("%d\n",a[n]);
    }
    return 0;
}
