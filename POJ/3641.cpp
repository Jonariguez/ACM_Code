/****************
*PID:poj3641
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=1000000000+5;

bool is_prime(ll n){
    if(n%2==0) return false;
    ll i;
    for(i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}

ll quick_multi(ll a,ll b,ll m){
    a%=m;
    ll res=0;
    while(b){
        if(b&1)
            res=(res+a)%m;
        b/=2;
        a=(a+a)%m;
    }
    return res;
}

ll quick_pow(ll a,ll b,ll m){
    a%=m;
    ll res=1;
    while(b){
        if(b&1)
            res=quick_multi(res,a,m);
        b/=2;
        a=quick_multi(a,a,m);
    }
    return res;
}

int main()
{
    ll p,a;
    while(scanf("%lld%lld",&p,&a)){
        if(p==0 && a==0) break;
        if(is_prime(p))
            printf("no\n");
        else {
            if(a==quick_pow(a,p,p))
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
