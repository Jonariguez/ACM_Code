/*
很明显，按经验，设f(n)表示从1到n中满足条件的数的个数。
那么答案就是f(U)-f(L-1)
很明显，我们需要素数表，但是打到10^12是不可能的。
但是仔细看，要求是本身不是素数，但只有一个素因子，
也就是这个数是某个素数p的p^2,p^3...p^k， 即最小也应该
是p^2，因为p本身是不符合的，所以打表的范围降到了
sqrt(U)=10^6。
计算f(n)时，枚举素数p，求出在[1,n]内p的整数幂有多少个
累加即可。

将p^2,p^3...p^k转化成下面这种形式：
p^2 (p^2)*p (p^2)*p^2 (p^2)*p^3 .. (p^2)*p^(k-2)

我们设t=n/(p^2),那么在t的范围内枚举k即可。
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=1000000;
vector<long long> prime;
bool vis[maxn+5];

void prime_table(){
    long long i,j;
    memset(vis,0,sizeof(vis));
    for(i=2;i<=maxn;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*2;j<=maxn;j+=i)
                vis[j]=1;
        }
    }
}

long long cal(long long n){
    long long res=0;
    for(int i=0;i<prime.size();i++){
        if(n<prime[i]*prime[i]) break;
        long long t=n/(prime[i]*prime[i]);
        long long k=1;
        while(t>=k){
            res++;
            k*=prime[i];
        }
    }
    return res;
}

int main()
{
    int T;
    long long L,U;
    prime_table();
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&L,&U);
        printf("%lld\n",cal(U)-cal(L-1));
    }
    return 0;
}
