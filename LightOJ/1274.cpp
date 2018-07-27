/****************
*PID:lightoj1274
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

const int maxn=5000+10;

double dp[2][maxn][2];

int main()
{
    int i,j,s,n,T,kcase=1;
    sc(T);
    while(T--){
        scanf("%d%d",&n,&s);
        int Y=s-2*n,N=3*n-s;
        memset(dp,0,sizeof(dp));
        for(i=n-1;i>=0;i--){
            for(j=min(i,Y);j>=0 && (i-j<=N);j--){
                double p1=(Y-j)*1.0/(n-i);
                double p0=(N-(i-j))*1.0/(n-i);
                if(j+1<=Y){
                    dp[i%2][j][0]=(dp[(i+1)%2][j+1][1]+1.0)*p1+dp[(i+1)%2][j][0]*p0;
                    dp[i%2][j][1]=dp[(i+1)%2][j+1][1]*p1+(dp[(i+1)%2][j][0]+1)*p0;
                }else {
                    dp[i%2][j][0]=p1+dp[(i+1)%2][j][0]*p0;
                    dp[i%2][j][1]=(1+dp[(i+1)%2][j][0])*p0;
                }
            }
        }
        printf("Case %d: %.7f\n",kcase++,dp[0][0][1]);
    }
    return 0;
}



