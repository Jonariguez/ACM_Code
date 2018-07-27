/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define X first
#define Y second
#define PI acos(-1.0)
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

const int maxn=300000+10;
const int MOD=1e9+7;

void Exgcd(LL a,LL b,LL &d,LL &x,LL &y){
    if(b==0){
        d=a;x=1;y=0;
        return ;
    }
    Exgcd(b,a%b,d,y,x);
    y-=(a/b)*x;
}

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int i,j,n;
    LL a1,b1,a2,b2,L,R;
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&a1,&b1,&a2,&b2,&L,&R);
    LL a=a1,b=-a2,c=b2-b1;
    LL d,x,y;
    Exgcd(a,b,d,x,y);
    if(c%d){
        puts("0");return 0;
    }
   // printf("a=%I64d b=%I64d c=%I64d d=%I64d\n",a,b,c,d);
    LL t=b/d;
    printf("x=%I64d y=%I64d\n",x,y);
    x=((x/d*c)%t+t)%t;
    if(x<=0) x+=t;
    LL res=0;
    b1=a1*x+b1;
  //  printf("t=%I64d\n",b1);
    t*=a1;
    if(L>b1){
        LL temp=(L-b1)/a1;
        while(b1+temp*a1>=L) temp--;
        while(b1+temp*a1<L) temp++;
        res=(R-(a1+b1*temp))/t+1;
    }else if(R>=b1){
        res=(R-b1)/t+1;
    }
    Pfn(res);
    return 0;
}



