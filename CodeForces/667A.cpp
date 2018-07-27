/****************
*PID:667a div2
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
#define PI acos(-1.0)
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;

int main()
{
    int i,d,h,v,e;
    while(scanf("%d%d%d%d",&d,&h,&v,&e)!=EOF){
        double r=(double)d/2;
        double ar=PI*r*r;
        double vv=ar*h;
        double v1=(double)v;
        double v2=ar*e;
        if(v2-v1>=0)
            printf("NO\n");
        else {
            puts("YES");
            printf("%.10f\n",vv/(v1-v2));
        }
    }
    return 0;
}




