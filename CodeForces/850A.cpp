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

const int maxn=200000+10;
const int MOD=1e9+7;

int a[maxn],b[maxn],c[maxn],d[maxn],e[maxn],vis[maxn];

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d%d%d%d%d",&a[i],&b[i],&c[i],&d[i],&e[i]);
    if(n>11){
        puts("0");return 0;
    }
    int res=n;
    for(i=1;i<=n;i++){
        int yes=0;
        for(j=1;j<=n && !yes;j++){
            if(j==i) continue;
            for(int k=1;k<=n && !yes;k++){
                if(k==i || k==j) continue;
                int A=a[j]-a[i];
                int B=b[j]-b[i];
                int C=c[j]-c[i];
                int D=d[j]-d[i];
                int E=e[j]-e[i];

                int AA=a[k]-a[i];
                int BB=b[k]-b[i];
                int CC=c[k]-c[i];
                int DD=d[k]-d[i];
                int EE=e[k]-e[i];

                double x=1.0*A*AA+B*BB+C*CC+D*DD+E*EE;
                double y=sqrt(1.0*A*A+B*B+C*C+D*D+E*E)*sqrt(1.0*AA*AA+BB*BB+CC*CC+DD*DD+EE*EE);
                if(x/y>0.0){
                    yes=1;
                    vis[i]=1;
                    res--;
                    break;
                }
            }
        }
    }
    printf("%d\n",res);
    for(i=1;i<=n;i++)
        if(vis[i]==0)
            printf("%d ",i);
    return 0;
}




