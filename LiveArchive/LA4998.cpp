/****************
*PID:la4998
*Auth:Jonariguez
*****************
���������⡣
��ͨ��ѭ�������ķ�ʽ��⣬���ѡȡһ���Դ���1e12������Ȼ����
k1^k2 mod k2 (mod 1e12������f(k2)=k1^k2,����f(k2)==k2��k2��һ���н⡣
����һ�����ʣ� ���12λ��K2��������ʽ�ӵĻ�����ôK2%1,K2%10,K2%100,...,K2%10^12��
����������ʽ�ӡ���ô���ǿ���dfs�Ӻ���ǰһ��һ���ҳ��������ÿһλ��
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
