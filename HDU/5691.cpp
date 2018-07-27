/****************
*PID:hdu5691
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

const int maxn=17;
const int INF=5e8;
int dp[(1<<16)][maxn];
int a[maxn],p[maxn],bit[1<<maxn];

int cal(int n){
    int cnt=0;
    while(n){
        if(n&1) cnt++;
        n/=2;
    }
    return cnt;
}

int main()
{
    int i,j,k,n,T,kcase=1;
    sc(T);
    while(T--){
        sc(n);
        for(i=0;i<n;i++)
            scanf("%d%d",&a[i],&p[i]);
        for(i=0;i<(1<<n);i++){
            bit[i]=cal(i);
            for(j=0;j<=n;j++)
                dp[i][j]=-INF;
        }
        a[n]=dp[0][n]=0;
        for(i=0;i<(1<<n);i++){
            for(j=0;j<=n;j++){
                if(dp[i][j]!=-INF){
                    for(k=0;k<n;k++){
                        if(((i>>k)&1)==0 && (p[k]==-1 || p[k]==bit[i]))
                            dp[i|(1<<k)][k]=max(dp[i|(1<<k)][k],dp[i][j]+a[j]*a[k]);
                    }
                }
            }
        }
        int res=-INF;
        for(i=0;i<n;i++)
            res=max(res,dp[(1<<n)-1][i]);
        printf("Case #%d:\n%d\n",kcase++,res);
    }
    return 0;
}




