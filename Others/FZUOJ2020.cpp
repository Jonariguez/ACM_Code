/****************
*PID:FZUOJ2020
*Auth:Jonariguez
*****************
组合，Lucas定理:
A、B是非负整数，p是质数。AB写成p进制：A=a[n]a[n-1]...a[0]，B=b[n]b[n-1]...b[0]。
则组合数C(A,B) = C(a[n],b[n])*C(a[n-1],b[n-1])*...*C(a[0],b[0]) mod p.
即：Lucas(n,m,p)=c(n%p,m%p)*Lucas(n/p,m/p,p).

只要m或p其中一个较小都可以保证不超时（<1e5左右吧），
因为要么m本身就小，要么mod p之后小。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef __int64 ll;

ll quick_pow(ll a,ll b,ll m){
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
/*
根据费马小定理：
已知(a,p)=1则a^(p-1) ≡ 1 (mod p),所以 a*a^(p-2) ≡ 1 (mod p)。
即a模p的逆元inv是a^(p-2)
*/
ll Comb(ll n,ll m,ll p){
    if(m>n) return 0;
    if(m==n) return 1;
    if(m>n-m) m=n-m;
    ll res=1,i,a=1,b=1;
    for(i=0;i<m;i++){
        a=(a*(n-i))%p;  //C(n,m)=n!/(m!*(n-m)!) 然后约去公共部分之后，a是分子，b是分母，仔细化一下。
        b=(b*(i+1))%p;
    }
    ll inv=quick_pow(b,p-2,p);  //求分母b的逆元
    res=(a*inv)%p;
    return res;
}

ll Lucas(ll n,ll m,ll p){
    if(m==0) return 1;
    return Comb(n%p,m%p,p)*Lucas(n/p,m/p,p)%p;
}

int main()
{
    int i,j,T;
    ll n,m,p;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d%I64d",&n,&m,&p);
        printf("%I64d\n",Lucas(n,m,p));
    }
    return 0;
}
