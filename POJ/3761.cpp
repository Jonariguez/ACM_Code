/****************
*PID:poj3761
*Auth:Jonariguez
*****************
首先，定义一个 f(x)表示在数组中位于元素x左面且大于x的个数。那么，
1，f(x) = 0 (x = 1,2,...,n)是最终有序的状态
2，f(x) <= n - x;
3，对于每趟冒泡排序，若f(x) != 0，则f(x)--;
比较好求的是经过不超过k趟冒泡的排列数g(k)
易知，k趟冒泡达到有序的充要条件是 max f(x) == k
所以 n - x <= k;即 x >= n -  k时，x可以放在数组的任意位置。
把元素分为[1,n-k],[n-k+1,n],在n个位置中放好了前n-k个数后，后k个数的方法为k!
对于前n-k 个数挨个来看，
首先要是f(1) <= k,则1有k+1个位置可放，放好1后，由于1的位置对f(2)无影响，
2同样有k+1个位置可放...
g(k) = (k+1)^(n-k) * k!
最终结果则为 g(k) - g(k-1) = k! * [(k + 1)^(n - k) - k^(n - k)];
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000000+10;
const LL MOD=20100713;
LL fact[maxn];

LL quick_pow(LL a,LL b){
    a%=MOD;b%=MOD;
    LL res=1;
    while(b){
        if(b&1) res=(res*a)%MOD;
        b/=2;
        a=(a*a)%MOD;
    }
    return res;
}

int main()
{
    int T;
    LL i,j,n,k;
    fact[0]=1;
    for(i=1;i<=1000000;i++)
        fact[i]=fact[i-1]*i%MOD;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d",&n,&k);
        LL res=fact[k]*(quick_pow(k+1,n-k)-quick_pow(k,n-k));
        res%=MOD;
        if(res<0) res+=MOD;
        printf("%I64d\n",res%MOD);
    }
    return 0;
}
