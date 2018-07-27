/*
一开始在想n的范围那么大，n以内的素数
根本没法预处理。 不过后来根据求某个数
的因子和受到了启发：
在sqrt(n)范围内试除，最后如果n不为1，那么
此时n就是大于sqrt(n)的那个素因子

大于n的素因子最多只有一个。
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;


ll solve(ll n){
    ll i;           //这里一开始i用int的TLE。。。
    ll res=0;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            ll sum=1;
            while(n%i==0){
                sum*=i;
                n/=i;
            }
            res+=sum;
        }
    }
    if(n>1) res+=n;
    return res;
}


int main()
{
    int i,kcase=1;
    ll n,res;
    while(scanf("%lld",&n)){
        if(n==0) break;
        printf("Case %d: ",kcase++);
        if(n==1){
            printf("2\n");continue;
        }
        res=solve(n);
        if(res==n)
            printf("%lld\n",n+1);
        else
            printf("%lld\n",res);
    }
    return 0;
}
