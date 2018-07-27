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
#define eps 1e-8
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

const int maxn=20;
const int MOD=1e9+7;
double p[maxn][maxn],dp[1<<maxn][maxn];

int main()
{
    int i,j,k,n;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++) scanf("%lf",&p[i][j]);
        memset(dp,0,sizeof(dp));
        dp[1][0]=1;
        for(i=0;i<(1<<n);i++){
            for(j=0;j<n;j++){
                if(~i&(1<<j)) continue;
                for(k=0;k<n;k++){
                    if(k==j || ~i&(1<<k)) continue;
                    dp[i][j]=max(dp[i][j],dp[i^(1<<k)][j]*p[j][k]+dp[i^(1<<j)][k]*p[k][j]);
                }
            }
        }
        double res=dp[(1<<n)-1][0];
        for(i=1;i<n;++i)
            res=max(res,dp[((1<<n)-1)][i]);
        printf("%.10f\n",res);
    }
    return 0;
}

