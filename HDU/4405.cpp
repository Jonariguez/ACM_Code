/****************
*PID:hdu4405
*Auth:Jonariguez
*****************
E[i]:为从i出发到达n或者超过n的期望次数。
如果i点有传送到f[i],则E[i]=E[f[i]]
否则E[i]=(E[i+1]+E[i+2]+..+E[i+6])/6+1;
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
int f[maxn];
double E[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 && m==0) break;
        memset(f,0,sizeof(f));
        for(i=1;i<=m;i++){
            int a,b;
            sc(a);sc(b);
            f[a]=b;
        }
        for(i=n;i<=n+6;i++)
            E[i]=0;
        for(i=n-1;i>=0;i--){
            if(f[i]){
                E[i]=E[f[i]];continue;
            }
            double sum=0;
            for(j=i+1;j<=i+6;j++)
                sum+=E[j];
            E[i]=sum/6+1.0;
        }
        printf("%.4f\n",E[0]);
    }
    return 0;
}




