/****************
*PID:431c div2
*Auth:Jonariguez
*****************
dp[i]:权值为i的路径的条数
dp2[i]:权值为i，且路径上的权值都小于d的路径条数
答案：dp[n]-dp2[n]
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
const LL MOD=1e9+7;
LL dp[maxn],dp2[maxn];

int main()
{
    int i,j,n,k,d;
    while(scanf("%d%d%d",&n,&k,&d)!=EOF){
        memset(dp,0,sizeof(dp));
        memset(dp2,0,sizeof(dp2));
        dp[0]=1;
        for(i=1;i<=n;i++){
            for(j=1;j<=k;j++){
                if(i-j>=0){
                    dp[i]+=dp[i-j];
                    dp[i]%=MOD;
                }
            }
        }
        dp2[0]=1;
        for(i=1;i<=n;i++){
            for(j=1;j<d;j++){
                if(i-j>=0){
                    dp2[i]+=dp2[i-j];
                    dp2[i]%=MOD;
                }
            }
        }
        LL res=(dp[n]-dp2[n])%MOD;
        if(res<0) res+=MOD;
        printf("%I64d\n",res);
    }
    return 0;
}


