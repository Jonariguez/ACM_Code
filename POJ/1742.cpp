/****************
*PID:poj1742
*Auth:Jonariguez
*****************
dp[i][j]:用前i种数组成j时，第i个数最多能剩下几个。
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
int dp[maxn],a[105],c[105];

int main()
{
    int i,j,n,m,T;
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=n;i++)
            sc(c[i]);
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        for(i=1;i<=n;i++){
            for(j=0;j<=m;j++){  //从0开始
                if(dp[j]>=0)
                    dp[j]=c[i];
                else if(j<a[i] || dp[j-a[i]]<=0)
                    dp[j]=-1;
                else dp[j]=dp[j-a[i]]-1;
            }
        }
        int res=0;
        for(i=1;i<=m;i++)
            if(dp[i]>=0) res++;
        printf("%d\n",res);
    }
    return 0;
}


