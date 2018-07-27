/*
类似于找规律，这是随便打开的一个题。
假设节点是12，那么答案就是9(=12-2^2+1)和15(=12+2^2-1)其中2是层数-1
再如8，答案是1(=8-2^3+1)和15(=8+2^3-1)，其中3是层数-1
所以我们只要知道节点x所在的层数就可以直接出解。
而节点x所在的层数有个规律：设层数是deep,那么有x%(2^deep)==2^(deep-1)。
所以枚举层数即可。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long ll;

int main()
{
    int T;
    ll n,deep;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        for(deep=1;deep<=31;deep++)
            if(n%(1<<deep)==(1<<(deep-1)))
                break;
        printf("%lld %lld\n",n-(1<<(deep-1))+1,n+(1<<(deep-1))-1);
    }
    return 0;
}
