/****************
*PID:uva11427
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

const int maxn=100+10;
double dp[maxn][maxn];

int main()
{
    int i,j,n,T,kcase=1;
    int p,q;
    sc(T);
    while(T--){
        scanf("%d/%d%d",&p,&q,&n);  //分母是p/q的形式
        memset(dp,0,sizeof(dp));
        double P=(double)p/q;
        dp[0][0]=1;
        for(i=1;i<=n;i++){
            for(j=0;j<=i;j++){
                if(j*q>p*i) break;
                if(!j)
                    dp[i][j]=dp[i-1][j]*(1-P);
                else
                    dp[i][j]=dp[i-1][j-1]*P+dp[i-1][j]*(1-P);
            }
        }
        double onlyOneNightLose=0;
        for(i=0;i*q<=n*p;i++)
            onlyOneNightLose+=dp[n][i];
        printf("Case #%d: %d\n",kcase++,(int)(1.0/onlyOneNightLose));
    }
    return 0;
}





