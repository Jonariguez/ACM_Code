/****************
*PID:hdu1098
*Auth:Jonariguez
*****************
f(x)=5*x^13+13*x^5+k*a*x
f(x+1)=f(x)+5*(C(13,1)*x^12+C(13,2)*x^11+..+C(13,13)*x^0)+13*(C(5,1)x^4+..+C(5,5)*x^0)+k*a
除了5*C(13,13)*x^0, 13*C(5,5)*x^0和k*a之外的所以项都能被65整除
即检查5+13+k*a=18+k*a能被65整除。
-->k*a==47(mod 65)
解同余方程即可。
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

void Exgcd(LL a,LL b,LL &d,LL &x,LL &y){
    if(b==0){
        d=a;x=1;y=0;return ;
    }
    Exgcd(b,a%b,d,y,x);
    y-=a/b*x;
}


int main()
{
    LL i,n,k,a,b,c;
    while(scanf("%I64d",&k)!=EOF){
        a=k;b=65;c=47;
        LL d,x,y;
        Exgcd(a,b,d,x,y);
        if(c%d){
            puts("no");continue;
        }
        LL t=b/d;
        x=(x*(c/d)+t)%t;
        if(x<0) x+=t;
        printf("%I64d\n",x);
    }
    return 0;
}



