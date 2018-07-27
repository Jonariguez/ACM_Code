/****************
*PID:hdu4790
*Auth:Jonariguez
*****************
http://www.cnblogs.com/xin-hua/p/3553045.html
这博客说的很明白
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
LL P,M;

LL f(LL n,LL m){
    if(n<0 || m<0) return 0;
    LL res=0;
    LL A=n/P,B=n%P,C=m/P,D=m%P;
    res+=A*C*P;
    res+=(B+1)*C+(D+1)*A;
    if(B>M){
        res+=min(M,D)+1;
        LL x=(P+M-B)%P;
        if(x<=D) res+=D-x+1;
    }else {
        LL x=(P+M-B)%P;
        if(x<=D)
            res+=min(M-x+1,D-x+1);
    }
    return res;
}

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int i,T,kcase=1;
    sc(T);
    while(T--){
        LL a,b,c,d;
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&a,&b,&c,&d,&P,&M);
        LL res=f(b,d)-f(a-1,d)-f(b,c-1)+f(a-1,c-1);
        LL temp=(b-a+1)*(d-c+1);
        LL g=gcd(res,temp);
        printf("Case #%d: %I64d/%I64d\n",kcase++,res/g,temp/g);
    }
    return 0;
}



