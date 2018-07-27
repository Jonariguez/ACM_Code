/****************
*PID:zoj2674
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;

LL Euler(LL n){
    LL i,res=n;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            res-=res/i;
            while(n%i==0)
                n/=i;
        }
    }
    if(n!=1)
        res-=res/n;
    return res;
}

LL Pow(LL a,LL n,LL mod){
    LL res=1;
    while(n){
        if(n&1)
            res=res*a%mod;
        n/=2;
        a=a*a%mod;
    }
    return res;
}

LL solve(LL p,LL m_){
    if(m_==1) return m_;
    LL phi=Euler(m_);
    LL now=solve(p,phi);
    LL res=Pow(p,now,m_);
    return res+m_;
}

int main()
{
    int i,j,kcase=0;
    LL n,m;
    while(scanf("%lld%lld",&n,&m)!=EOF){
        if(kcase)
            puts("");
        LL fact=1;
        for(i=1;i<=m;i++)
            fact*=i;
        printf("%lld\n",solve(n,fact)%fact);
        kcase++;
    }
    return 0;
}



