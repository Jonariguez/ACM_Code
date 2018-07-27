/****************
*PID:hdu5446
*Auth:Jonariguez
*****************
Changchun 10
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include<stdio.h>
typedef __int64 ll;

ll multi(ll a,ll b,ll m){
    a=(a%m+m)%m;
    b=(b%m+m)%m;
    ll res=0LL;
    while(b){
        if(b&1)
            res=(res+a)%m;
        b/=2;
        a=(a*2)%m;
    }
    return res;
}

void Exgcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(b==0){
        x=1;y=0;d=a;return ;
    }
    Exgcd(b,a%b,d,y,x);
    y-=(a/b)*x;
}

ll China(ll *a,ll *r,ll k){
    ll M=1LL,Mi,i,j,d,x,y,res=0LL;
    for(i=0;i<k;i++)
        M*=a[i];
    for(i=0;i<k;i++){
        Mi=M/a[i];
        Exgcd(Mi,a[i],d,x,y);
        ll t=
        res=(res+multi(multi(Mi,r[i],M),x,M))%M;    //要处理x为负的数
    }
    res=(res%M+M)%M;
    return res;
}

ll quick_pow(ll a,ll b,ll m){
    a%=m;
    ll res=1LL;
    while(b){
        if(b&1)
            res=multi(res,a,m);
        b/=2;
        a=multi(a,a,m);
    }
    return res;
}

ll Com(ll n,ll m,ll p){
    if(n<m) return 0;
    if(m==0 || m==n) return 1;
    if(m>n-m) m=n-m;
    ll i,a1=1,b1=1;
    for(i=0;i<m;i++){
        a1=(a1*(n-i))%p;
        b1=(b1*(i+1))%p;
    }
    ll res=quick_pow(b1,p-2,p);
    return (a1*res)%p;
}

ll Lucas(ll n,ll m,ll p){
    if(m==0) return 1LL;
    return (Com(n%p,m%p,p)*Lucas(n/p,m/p,p))%p;
}

ll p[12],r[12],a[12];

int main()
{
    ll i,j,T;
    ll n,m,k;
    scanf("%I64d",&T);
    while(T--){
        scanf("%I64d%I64d%I64d",&n,&m,&k);
        for(i=0;i<k;i++)
            scanf("%I64d",&p[i]);
        for(i=0;i<k;i++){
            r[i]=(Lucas(n,m,p[i])%p[i]);
        }
        printf("%I64d\n",China(p,r,k));
    }
    return 0;
}
