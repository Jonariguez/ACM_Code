/****************
*PID:poj3661
*Auth:Jonariguez
*****************
注意题目说要休息必须要休息到疲劳度为0了才能再继续跑。一开始没看到
dp[i][j]:第i分钟时，疲劳度为j时能跑的最远距离。
dp[i][j]会由两个状态转移过来，即决策：
①第i秒休息到疲劳度为0，则dp[i][0]=max(dp[i-1][0],dp[i-k][k]),k>0后者为在i-k秒时跑到疲劳度为k的maxdist，
②第i秒跑步，则dp[i][j]=max(dp[i][j],dp[i-1][j-1]+D[i])
答案：dp[n][0]
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

const int maxn=10000+10;
const int maxm=500+5;
int n,m,d[maxn],dp[maxn][maxm];

int main()
{
    int i,j;
    sc(n);sc(m);
    for(i=1;i<=n;i++) sc(d[i]);
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0];
        for(j=1;j<=m;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+d[i]);
            if(j<i)
                dp[i][0]=max(dp[i][0],dp[i-j][j]);
        }
    }
    printf("%d\n",dp[n][0]);
    return 0;
}



