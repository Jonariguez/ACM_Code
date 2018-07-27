/****************
*PID:hdu3037
*Auth:Jonariguez
*****************
��ϣ�Lucas
n����ͬ��m����ͬ����Ϊ�գ�������C(n+m,m)

Lucas�����Code\FZUOJ2020.cpp
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

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

ll Comb(ll n,ll m,ll p){
    if(m>n) return 0;
    if(m==n) return 1;
    if(m>n-m) m=n-m;
    ll res,i,a=1,b=1;
    for(i=0;i<m;i++){
        a=(a*(n-i))%p;
        b=(b*(i+1))%p;
    }
    ll inv=quick_pow(b,p-2,p);
    res=(a*inv)%p;
    return res;
}

ll Lucas(ll n,ll m,ll p){
    if(m==0) return 1;
    return Comb(n%p,m%p,p)*Lucas(n/p,m/p,p)%p;      //ע�����ﻹҪ%p,��Ȼ��WA
}

int main()
{
    int i,T;
    ll n,m,p;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&p);
        printf("%lld\n",Lucas(n+m,m,p));
    }
    return 0;
}
