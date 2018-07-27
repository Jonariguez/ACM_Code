/****************
*PID:poj2955
*Auth:Jonariguez
*****************
上一份代码注释写错了
该题是求最长合法的子序列，那么我们可以求为了让整个串
合法需要添加的括号个数，那么n-该个数即为答案(因为需要添加
几个就说明就有几个不匹配的，减去不匹配的不就是匹配的了嘛）
dp决策有两种：
①如果两边匹配，则抛去两边剩[i+1][j-1]
②不管两边匹配不匹配都要尝试在中间分开是否有最优解，即dp[i][j]=min(dp[i][k]+dp[k+1][j])
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
const int INF=1e6;
char str[maxn];
int dp[maxn][maxn];

bool match(int i,int j){
    return str[i]=='(' && str[j]==')' || str[i]=='[' && str[j]==']';
}

int main()
{
    int i,j,k,n,m;
    while(scanf("%s",str+1) && strcmp(str+1,"end")!=0){
        memset(dp,0,sizeof(dp));
        n=strlen(str+1);
        for(i=1;i<=n;i++) dp[i][i]=1;
        for(i=n-1;i>=1;i--){
            for(j=i+1;j<=n;j++){
                dp[i][j]=INF;
                if(match(i,j)) dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
                for(k=i;k<j;k++)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
        printf("%d\n",n-dp[1][n]);
    }
    return 0;
}




