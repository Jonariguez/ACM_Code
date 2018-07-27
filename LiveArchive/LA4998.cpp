/****************
*PID:la4998
*Auth:Jonariguez
*****************
不动点问题。
①通过循环迭代的方式求解，随机选取一个稍大于1e12的数，然后求
k1^k2 mod k2 (mod 1e12），设f(k2)=k1^k2,即求f(k2)==k2的k2，一定有解。
②有一个性质： 如果12位数K2满足如上式子的话，那么K2%1,K2%10,K2%100,...,K2%10^12都
会满足如上式子。那么我们可以dfs从后往前一个一个找出这个数的每一位。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD=1e12;
LL k1;

LL multi(LL a,LL b){
    LL res=0;
    a%=MOD;b%=MOD;
    while(b){
        if(b&1) res=(res+a)%MOD;
        b/=2;
        a=(a+a)%MOD;
    }
    return res;
}

LL quick_pow(LL a,LL b){
    a%=MOD;
    LL res=1;
    while(b){
        if(b&1)
            res=multi(res,a);
        b/=2;
        a=multi(a,a);
    }
    return res;
}

LL solve(LL x){
    LL fx;
    while(true){
        fx=quick_pow(k1,x);
        if(fx==x) return fx;
        x=fx;
    }
}

int main()
{
    int kcase=1;
    while(scanf("%lld",&k1)!=EOF && k1){
        printf("Case %d: Public Key = %lld Private Key = %lld\n",kcase++,k1,solve((LL)1e12+7));
    }
    return 0;
}
