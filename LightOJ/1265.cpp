/****************
*PID:lightoj1265
*Auth:Jonariguez
*****************
http://www.cnblogs.com/By-ruoyu/p/4726184.html
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

int main()
{
    int i,j,n,m,T,kcase=1;
    sc(T);
    while(T--){
        scanf("%d%d",&n,&m);
        printf("Case %d: ",kcase++);
        if(n&1)
            printf("0\n");
        else {
            double ans=1;
            for(i=n;i>=2;i-=2)
                ans*=(double)(i-1)/(i+1);
            printf("%.8f\n",ans);
        }
    }
    return 0;
}



