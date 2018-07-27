/****************
*PID:poj2385
*Auth:Jonariguez
*****************
dp[i][j]:表示到第i分钟，移动j次的最大值。
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
int sum[3][maxn],b[maxn],c[maxn];
int dp[maxn][33];

int main()
{
    int i,j,k,n,T,W;
    scanf("%d%d",&T,&W);
    sum[1][0]=sum[2][0]=0;
    for(i=1;i<=T;i++){
        sc(c[i]);
        if(c[i]==1){
            sum[1][i]=sum[1][i-1]+1;
            sum[2][i]=sum[2][i-1];
        }else {
            sum[1][i]=sum[1][i-1];
            sum[2][i]=sum[2][i-1]+1;
        }
    }
    for(i=1;i<=T;i++){
        for(j=0;j<=W;j++){
            int t;
            if(j&1) t=2;
            else t=1;
            dp[i][j]=dp[i-1][j]+sum[t][i]-sum[t][i-1];
            if(j){
                dp[i][j]=max(dp[i][j],dp[0][j-1]+sum[t][i]);
                for(k=1;k<=i;k++){
                    dp[i][j]=max(dp[i][j],dp[k][j-1]+sum[t][i]-sum[t][k-1]);
                }
            }
        }
    }
    int res=0;
    for(i=0;i<=W;i++)
        res=max(res,dp[T][i]);
    pfn(res);
    return 0;
}


