/****************
*PID:hdu5538
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

const int maxn=50+10;
int c[maxn][maxn],n,m;

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(c,0,sizeof(c));
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++) sc(c[i][j]);
        int res=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(c[i][j]) res++;
                res+=max(c[i][j]-c[i][j-1],0);
                res+=max(c[i][j]-c[i][j+1],0);
                res+=max(c[i][j]-c[i-1][j],0);
                res+=max(c[i][j]-c[i+1][j],0);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}


