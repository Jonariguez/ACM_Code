/****************
*PID:hdu5478
*Auth:Jonariguez
*****************
n=1
a^(k1+b1)+b = 0 (mod c)         ①
n=2
a^(2*k1+b1)+b^(k2+1) = 0 (mod c)    ②
①式同时乘以一个数也成立，设乘以a^k1
a^k1*(a^(k1+b1)+b) = 0 (mod c)
a^(2*k1+b1) + a^k1*b = 0 (mod c)  ==> a^(2*k1+b1)+b^(k2+1) = 0 (mod c)(后者其实是②式)
最后化得
a^k1 == b^k2 (mod c)
思路：枚举a，快速幂求得a^k1,和a^(k1+b1),然后由①式得出b，再快速幂求b^k2，然后判断
a^k1==b^k2，如果成立则(a,b)对满足
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxc=200000+5;

ll Pow(ll a,ll b,ll m){
    a%=m;
    ll res=1;
    while(b){
        if(b&1)
            res=(res*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return res;
}

int main()
{
    ll i,j,res,c,k1,k2,b1;
    int kcase=1;
    while(scanf("%lld%lld%lld%lld",&c,&k1,&b1,&k2)!=EOF){
        printf("Case #%d:\n",kcase++);
        ll a,b;
        int flag=0;
        for(a=1;a<c;a++){
            ll ak1=Pow(a,k1,c);
            ll ab1=Pow(a,b1,c);
            ll ak1b1=ak1*ab1%c;
            b=(c-ak1b1)%c;
            if(b<0)
                b+=c;
            ll bk2=Pow(b,k2,c);
            if(ak1==bk2){
                printf("%lld %lld\n",a,b);
                flag=1;
            }
        }
        if(!flag)
            printf("-1\n");
    }
    return 0;
}
