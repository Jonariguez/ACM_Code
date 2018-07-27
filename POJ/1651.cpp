/****************
*PID:poj1651
*Auth:Jonariguez
*****************
区间dp
dp[i][j]:表示区间(i,j)内的数都取掉的最小代价
dp[i]=min{dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]} 其中k枚举的意义是区间(i,j)最后要取的数。
貌似还可以理解成矩阵链乘来做。
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
const LL INF=1e15;
LL a[maxn],dp[maxn][maxn];

int main()
{
    int i,j,k,n;
    sc(n);
    for(i=1;i<=n;i++)
        In(a[i]);
    for(i=1;i<=n;i++)
        for(j=i+3;j<=n;j++) dp[i][j]=INF;
    for(i=1;i<=n;i++)
        dp[i][i+2]=a[i]*a[i+1]*a[i+2];
    for(i=n-1;i>=1;i--){
        for(j=i+3;j<=n;j++){
            for(k=i+1;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
            }
        }
    }
    printf("%I64d\n",dp[1][n]);
    return 0;
}



