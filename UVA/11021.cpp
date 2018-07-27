/****************
*PID:uva11021
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

const int maxn=1000+10;
double p[maxn],f[maxn];

int n,k,m;

int main()
{
    int i,j,T,kcase=1;
    sc(T);
    while(T--){
        scanf("%d%d%d",&n,&k,&m);
        for(i=0;i<n;i++)
            scanf("%lf",&p[i]);
        f[0]=0;f[1]=p[0];
        for(i=2;i<=m;i++){
            f[i]=p[0];
            for(j=1;j<n;j++)
                f[i]+=p[j]*pow(f[i-1],j);
        }
        double ans=pow(f[m],k);
        printf("Case #%d: %.7f\n",kcase++,ans);
    }
    return 0;
}



