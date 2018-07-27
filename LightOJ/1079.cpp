/****************
*PID:lightoj1079
*Auth:Jonariguez
*****************
dp[i][j]:前i家银行，抢到j millions元钱能逃跑的最大概率。
背包思想
dp[i][j]=max(dp[i-1][j],dp[i-1][j-m[i]]*(1-p[i]));
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

const int maxn=100+10;
int m[maxn];
double p[maxn],dp[maxn][maxn*maxn];

int main()
{
    int i,j,n,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        double P;
        scanf("%lf%d",&P,&n);
        for(i=1;i<=n;i++)
            scanf("%d%lf",&m[i],&p[i]);
        memset(dp,0,sizeof(dp));
        int sum=0;
        dp[0][0]=1.0;
        for(i=1;i<=n;i++){
            sum+=m[i];
            for(j=0;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(j-m[i]>=0)
                    dp[i][j]=max(dp[i][j],dp[i-1][j-m[i]]*(1-p[i]));
            }
        }
        int res=0;
        for(i=sum;i>=0;i--)
            if(dp[n][i]>=(1-P))
                break;
        printf("Case %d: %d\n",kcase++,i);
    }
    return 0;
}



