/****************
*PID:hdu5666
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
LL MOD;

//因为p太大，需要快速乘法
LL multi(LL a,LL b){
    a%=MOD;
    LL res=0;
    while(b){
        if(b&1)
            res=(res+a)%MOD;
        b/=2;
        a=(a+a)%MOD;
    }
    return res;
}

int main()
{
    int i,T;
    scanf("%d",&T);
    while(T--){
        LL q;
        scanf("%I64d%I64d",&q,&MOD);
        LL a=q-1,b=q-2;
        if(a&1) b/=2;
        else a/=2;
        printf("%I64d\n",multi(a,b));
    }
    return 0;
}



